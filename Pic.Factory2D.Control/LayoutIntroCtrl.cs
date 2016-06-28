#region Using directives
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.IO;

using System.Runtime.InteropServices;
using Microsoft.Win32;
using System.Reflection;

using log4net;

using Sharp3D.Math.Core;

using TreeDim.UserControls;
using DesLib4NET;
#endregion

namespace Pic.Factory2D.Control
{
    #region LayoutIntroCtrl
    [Guid("097304D8-999D-45D3-9153-1D1F971E15C1")]
    [ClassInterface(ClassInterfaceType.AutoDual)]
    [ProgId("Pic.Factory2D.Control.LayoutIntroCtrl")]
    [ComVisible(true)]
    public partial class LayoutIntroCtrl : UserControl/*, ILayoutCtrl*/
    {
        #region Data members
        private string _drawingName;
        private string _fileNameFormats;
        private string _outputFilePath;
        protected static readonly ILog _log = LogManager.GetLogger(typeof(LayoutIntroCtrl));
        private ImpositionTool _impositionTool;
        private List<ImpositionSolution> _solutions;
        private int _result;
        #endregion

        #region PluginValidated event (+ associated delegate)
        public delegate void LayoutCtlrHandler(object sender, LayoutCtrlEventArgs e);
        public event LayoutCtlrHandler LayoutValidated;
        public event LayoutCtlrHandler LayoutCanceled;
        #endregion

        #region Constructor
        public LayoutIntroCtrl()
        {
            InitializeComponent();


        }
        #endregion

        #region Private properties
        private int NumberDirX { get { return (int)nudNumberDirX.Value; } }
        private int NumberDirY { get { return (int)nudNumberDirY.Value; } }
        private int Mode
        {
            set
            {
                rbLayoutMode1.Checked = (0 == value);
                rbLayoutMode2.Checked = (1 == value);
            }
            get
            {
                if (rbLayoutMode1.Checked)
                    return 0;
                else
                    return 1;
            }
        }
        #endregion

        #region UserControl override
        protected override void OnLoad(EventArgs e)
        {
            base.OnLoad(e);

            setFormatsFileName(@"C:\Picador\CardboardFormats.xml");

            // initialize number of rows/columns
            nudNumberDirX.Value = (decimal)2;
            nudNumberDirY.Value = (decimal)2;

            // update mode
            rbLayoutMode1.Checked = true;
            onLayoutModeChanged(this, null);
        }
        #endregion

        #region Implementation ILayoutCtrl
        public void setDrawingName(String drawingName)
        {
            _drawingName = drawingName;
        }
        public int Result()
        {
            return _result;
        }
        public String GetOutputFile()
        {
            return _outputFilePath;
        }
        public void setFormatsFileName(String fileNameFormats)
        {
            _fileNameFormats = fileNameFormats;

            // load cardboard formats
            if (File.Exists(_fileNameFormats))
            {
                CardboardFormats formats = CardboardFormats.LoadFromFile(_fileNameFormats);
                foreach (fCardboardFormat cf in formats.fCardboardFormat)
                    cbCardboardFormat.Items.Add(cf);
                if (cbCardboardFormat.Items.Count > 0)
                    cbCardboardFormat.SelectedIndex = 0;
            }
        }
        #endregion


        #region Event handlers
        private void onEditFormats(object sender, EventArgs e)
        {
            try
            {
                System.Diagnostics.Process.Start("notepad.exe", _fileNameFormats);
            }
            catch (Exception ex)
            {
                _log.Error(ex.ToString());
            }
        }

        private void onLayoutModeChanged(object sender, EventArgs e)
        {
            // mode 1
            lblCardboardFormat.Enabled = rbLayoutMode1.Checked;
            cbCardboardFormat.Enabled = rbLayoutMode1.Checked;
            // mode 2
            lbDirX.Enabled = rbLayoutMode2.Checked;
            nudNumberDirX.Enabled = rbLayoutMode2.Checked;
            lbDirY.Enabled = rbLayoutMode2.Checked;
            nudNumberDirY.Enabled = rbLayoutMode2.Checked;
        }

        private Pic.Factory2D.CardboardFormat CurrentCardboardFormat
        {
            get
            {
                fCardboardFormat fcb = cbCardboardFormat.Items[cbCardboardFormat.SelectedIndex] as fCardboardFormat;
                return new CardboardFormat(0, fcb.name, string.Empty, (double)fcb.dimensions[0], (double)fcb.dimensions[1]);
            }
        }

        private ImpositionTool.HAlignment HorizontalAlignment
        {
            get { return ImpositionTool.HAlignment.HALIGN_CENTER; }
        }

        private ImpositionTool.VAlignment VerticalAlignment
        {
            get { return ImpositionTool.VAlignment.VALIGN_CENTER; }
        }

        private double ImpSpaceX { get { return (double)nudSpaceX.Value; } }
        private double ImpSpaceY { get { return (double)nudSpaceY.Value; } }
        private double ImpMarginLeftRight { get { return (double)nudLeftRightMargin.Value; } }
        private double ImpMarginBottomTop { get { return (double)nudTopBottomMargin.Value; } }
        private double ImpRemainingMarginLeftRight { get { return (double)nudLeftRightRemaining.Value; } }
        private double ImpRemainingMarginBottomTop { get { return (double)nudTopBottomRemaining.Value; } }
        private Vector2D Offset
        {
            get { return new Vector2D((double)nudOffsetX.Value, (double)nudOffsetY.Value); }
            set { nudOffsetX.Value = (decimal)value.X; nudOffsetY.Value = (decimal)value.Y; }
        }
        private bool AllowColumnRotation { get { return true; } }
        private bool AllowRowRotation { get { return true; } }

        private void onOK(object sender, EventArgs e)
        {
            // build factory entities
            try
            {
                // load file
                Pic.Factory2D.PicFactory factory = new PicFactory();
                PicLoaderDes picLoaderDes = new PicLoaderDes(factory);
                using (DES_FileReader fileReader = new DES_FileReader())
                {
                    fileReader.ReadFile(_drawingName, picLoaderDes);
                }

                // build imposition solutions
                if (Mode == 0)
                    _impositionTool = new ImpositionToolCardboardFormat(factory, CurrentCardboardFormat);
                else
                    _impositionTool = new ImpositionToolXY(factory, NumberDirX, NumberDirY);
                // -> margins
                _impositionTool.HorizontalAlignment = HorizontalAlignment;
                _impositionTool.VerticalAlignment = VerticalAlignment;
                _impositionTool.SpaceBetween = new Vector2D(ImpSpaceX, ImpSpaceY);
                _impositionTool.Margin = new Vector2D(ImpMarginLeftRight, ImpMarginBottomTop);
                _impositionTool.MinMargin = new Vector2D(ImpRemainingMarginLeftRight, ImpRemainingMarginBottomTop);
                // -> allowed patterns
                _impositionTool.AllowRotationInColumnDirection = AllowColumnRotation;
                _impositionTool.AllowRotationInRowDirection = AllowRowRotation;
                // -> offsets
                _impositionTool.ImpositionOffset = Offset;
                _solutions = new List<ImpositionSolution>();

                // instantiate ProgressWindow and launch process
                ProgressWindow progress = new ProgressWindow();
                System.Threading.ThreadPool.QueueUserWorkItem(new System.Threading.WaitCallback(GenerateImpositionSolutions), progress);
                progress.ShowDialog();

                if (null != _solutions && _solutions.Count > 0)
                {
                    FormLayoutViewer form = new FormLayoutViewer();
                    // set solutions
                    form.Solutions = _solutions;
                    form.Format = CurrentCardboardFormat;
                    form.DrawingName = Path.GetFileNameWithoutExtension(_drawingName);
                    // show imposition dlg
                    if (DialogResult.OK == form.ShowDialog(this))
                    {
                        _outputFilePath = form.OutputFilePath;
                        _result = form.Result;
                    }
                    else
                        _result = 0;
                }
            }
            catch (PicToolTooLongException /*ex*/)
            {
                MessageBox.Show(
                    string.Format(Properties.Resources.ID_ABANDONPROCESSING
                    , Pic.Factory2D.Properties.Settings.Default.AreaMaxNoSegments)
                    , Application.ProductName
                    , MessageBoxButtons.OK
                    , MessageBoxIcon.Stop);
            }
            catch (Exception ex)
            {
                _log.Error(ex.ToString());
            }
            if (null != LayoutValidated)
                LayoutValidated(sender, new LayoutCtrlEventArgs(_result, GetOutputFile()));
        }

        private void GenerateImpositionSolutions(object status)
        {
            IProgressCallback callback = status as IProgressCallback;
            _impositionTool.GenerateSortedSolutionList(callback, out _solutions);
        }

        private void onCancel(object sender, EventArgs e)
        {
            if (null != LayoutCanceled)
                LayoutCanceled(sender, new LayoutCtrlEventArgs(0, string.Empty));
        }
        #endregion

        #region MAPPING_OF_USER32_DLL_SECTION
        [DllImport("user32.dll", EntryPoint = "SendMessage")]
        public static extern IntPtr SendMessage(
            int hwnd, uint wMsg, IntPtr wParam, IntPtr lParam);

        [DllImport("user32.dll", EntryPoint = "SendMessage")]
        public static extern int SendMessage(
            int hwnd, uint wMsg, int wParam, string lParam);

        [DllImport("user32.dll", EntryPoint = "SendMessage")]
        public static extern int SendMessage(
            int hwnd, uint wMsg, int wParam, out int lParam);

        [DllImport("user32.dll", EntryPoint = "SendMessage")]
        public static extern int GetNbFiles(
            int hwnd, uint wMsg, int wParam, int lParam);

        [DllImport("user32.dll", EntryPoint = "SendMessage")]
        public static extern int GetFileNames(
            int hwnd, uint wMsg,
            [MarshalAs(UnmanagedType.LPArray)]IntPtr[] wParam,
            int lParam);

        [DllImport("user32.dll", EntryPoint = "SendMessage")]
        public static extern int SendMessage(
            int hwnd, uint wMsg, int wParam, StringBuilder lParam);
        #endregion

        #region ActiveX Dll functions
        [ComRegisterFunction()]
        public static void RegisterClass(string key)
        {
            // Strip off HKEY_CLASSES_ROOT\ from the passed key as I don't need it
            StringBuilder sb = new StringBuilder(key);
            sb.Replace(@"HKEY_CLASSES_ROOT\", "");

            // Open the CLSID\{guid} key for write access
            RegistryKey k = Registry.ClassesRoot.OpenSubKey(sb.ToString(), true);

            // And create the 'Control' key - this allows it to show up in 
            // the ActiveX control container 
            RegistryKey ctrl = k.CreateSubKey("Control");
            ctrl.Close();

            // Next create the CodeBase entry - needed if not string named and GACced.
            RegistryKey inprocServer32 = k.OpenSubKey("InprocServer32", true);
            inprocServer32.SetValue("CodeBase", Assembly.GetExecutingAssembly().CodeBase);
            inprocServer32.Close();

            // Finally close the main key
            k.Close();
        }
        [ComUnregisterFunction()]
        public static void UnregisterClass(string key)
        {
            StringBuilder sb = new StringBuilder(key);
            sb.Replace(@"HKEY_CLASSES_ROOT\", "");

            // Open HKCR\CLSID\{guid} for write access
            RegistryKey k = Registry.ClassesRoot.OpenSubKey(sb.ToString(), true);

            // Delete the 'Control' key, but don't throw an exception if it does not exist
            k.DeleteSubKey("Control", false);

            // Next open up InprocServer32
            RegistryKey inprocServer32 = k.OpenSubKey("InprocServer32", true);

            // And delete the CodeBase key, again not throwing if missing 
            k.DeleteSubKey("CodeBase", false);

            // Finally close the main key 
            k.Close();
        }
        #endregion
    }
    #endregion

    #region COM Interface ILayoutCtrl
    /*
    /// <summary>
    /// COM Interface - enables to run c# code from c++
    /// </summary>
    [Guid("F364BC7D-2E1E-403D-9BE2-93C8343561EE")]
    [InterfaceType(ComInterfaceType.InterfaceIsDual)]
    [ComVisible(true)]
    public interface ILayoutCtrl
    {
        void setFormatsFileName(String formatsFileName);
        void setDrawingName(String drawingName);
        String GetOutputFile();
    }
    */

    #region Public event args
    public class LayoutCtrlEventArgs
    {
        #region Constructor
        public LayoutCtrlEventArgs(int result, string outputPath)
        {
            _result = result;
            _outputPath = outputPath;
        }
        #endregion

        #region Public properties
        public string OutputPath
        { get { return _outputPath; } }
        public int Result
        { get { return _result; } }
        #endregion

        #region Data members
        public string _outputPath;
        public int _result;
        #endregion
    }
    #endregion
    #endregion
}
