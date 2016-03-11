#region Using directives
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

using System.IO;

using Pic.Factory2D;
using Pic.Factory2D.Control;

using treeDiM.Processor.Properties;

#endregion

namespace treeDiM.Processor
{
    public partial class FormExporterSettings : Form, IEntitySupplier
    {
        #region Constructor
        public FormExporterSettings()
        {
            InitializeComponent();
        }
        #endregion

        #region Load / Closed
        protected override void OnLoad(EventArgs e)
        {
 	        base.OnLoad(e);

            // load exporter settings
            _exporterSettings = ExporterSettings.LoadFromFile(Settings.Default.SettingsFilePath);

            // fill combo
            foreach (ExporterSettingsTypeCutJob job in _exporterSettings.TypeCutJobs)
                cbCutJobType.Items.Add(job.Name);
            if (cbCutJobType.Items.Count > 0)
                cbCutJobType.SelectedIndex = 0;

            // fill fileSelect control
            string filePath = Path.Combine(Properties.Settings.Default.OutputDirectory, FileName);
            fileSelectOutput.FileName = Path.ChangeExtension(filePath, "oxf");
        }
        protected override void OnClosed(EventArgs e)
        {
            Properties.Settings.Default.OutputDirectory = Path.GetDirectoryName(fileSelectOutput.FileName);
            Properties.Settings.Default.Save();

            base.OnClosed(e);
        }
        #endregion

        #region Implementation IEntitySupplier
        public void CreateEntities(PicFactory factory)
        {
            if (null == _entities) return;
            // show entities
            for (int i = 0; i < Math.Min(_entities.Count, trackBarEntities.Value); ++i)
            {
                PicTypedDrawable entity = _entities[i];
                PicSegment seg = entity as PicSegment;
                if (null != seg)
                {
                    factory.AddSegment(seg.LineType, seg.Group, seg.Layer, seg.Pt0, seg.Pt1);
                }

                PicArc arc = entity as PicArc;
                if (null != arc)
                {
                    factory.AddArc(arc.LineType, arc.Group, arc.Layer, arc.Center, arc.Source, arc.Target);
                }
            }
        }
        #endregion

        #region Processing
        private void Process()
        {
            if (null == _factory || null == _exporterSettings)
                return;
            // selected
            Dictionary<PicGraphics.LT, CutTool> toolDictionary = new Dictionary<PicGraphics.LT, CutTool>();
            ExporterSettingsTypeCutJob typeCutJob = _exporterSettings.TypeCutJobs[cbCutJobType.SelectedIndex];
            foreach (ExporterSettingsTypeCutJobTool tool in typeCutJob.Tools)
            {
                PicGraphics.LT lineType = PicGraphics.ParseLineType(tool.LineType.ToString());
                toolDictionary.Add(lineType, new CutTool(tool.ToolNumber, tool.ToolName, tool.Color.ToArray(), tool.Step));
            }

            Generator.ProcessEntities(_factory, toolDictionary, ref _entities);

            trackBarEntities.Minimum = 0;
            trackBarEntities.Maximum = _entities.Count;
            trackBarEntities.Value = _entities.Count;

            factoryViewerCurrent.Refresh();
        }
        #endregion

        #region Public properties
        public string FileName
        {
            get { return _fileName; }
            set { _fileName = value; }
        }

        public PicFactory Factory
        {
            set { _factory = value; }
            get { return _factory; }
        }
        #endregion

        #region Event handlers
        private void onCutJobTypeChanged(object sender, EventArgs e)
        {
            Process(); 
        }
        private void onScroll(object sender, EventArgs e)
        {
            factoryViewerCurrent.Refresh();
        }
        #endregion

        #region Data members
        private string _fileName;
        private ExporterSettings _exporterSettings;
        private PicFactory _factory;
        private List<PicTypedDrawable> _entities;
        #endregion
    }
}
