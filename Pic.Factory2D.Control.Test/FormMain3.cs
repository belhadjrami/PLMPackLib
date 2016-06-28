#region Using directives
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Diagnostics;
using System.IO;
using log4net;
#endregion

namespace Pic.Factory2D.Control.Test
{
    public partial class FormMain3 : Form
    {
        #region Data members
        private static ILog _log = LogManager.GetLogger(typeof(FormMain3));
        #endregion

        #region Constructor
        public FormMain3()
        {
            InitializeComponent();

            string fileNameFormats = @"C:\Picador\CardboardFormats.xml";
            string drawingFileName = @"C:\picador\faittout.des";

            // event handlers
            layoutIntroCtrl.LayoutCanceled += onLayoutCanceled;
            layoutIntroCtrl.LayoutValidated +=onLayoutValidated;

            layoutIntroCtrl.setFormatsFileName(fileNameFormats);
            layoutIntroCtrl.setDrawingName(drawingFileName);
        }

        void onLayoutValidated(object sender, LayoutCtrlEventArgs e)
        {
            try
            {
                string appPath = "K:\\GitHub\\PicGEOM\\Release\\PicGEOM.exe";
                if (File.Exists(appPath))
                    Process.Start(appPath, string.Format("\"{0}\"", e._outputPath));
            }
            catch (Exception ex)
            {
                _log.Error(ex.ToString());
            }
            Close();
        }
        void onLayoutCanceled(object sender, LayoutCtrlEventArgs e)
        {
            Close();
        }
        #endregion
    }
}
