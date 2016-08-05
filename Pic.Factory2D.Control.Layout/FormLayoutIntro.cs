#region Using directives
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.IO;
using System.Xml;

using log4net;
#endregion

namespace Pic.Factory2D.Control.Layout
{
    public partial class FormLayoutIntro : Form
    {
        #region Constructor
        public FormLayoutIntro()
        {
            InitializeComponent();
            // event handlers
            layoutIntroCtrl.LayoutCanceled += onLayoutCanceled;
            layoutIntroCtrl.LayoutValidated += onLayoutValidated;
        }
        #endregion

        #region Form override
        protected override void OnLoad(EventArgs e)
        {
            base.OnLoad(e);

            layoutIntroCtrl.setFormatsFileName(_formatsFile);
            layoutIntroCtrl.setDrawingName(_inputFile);
        }
        protected override void OnClosed(EventArgs e)
        {
            base.OnClosed(e);
            if (DialogResult.Cancel == DialogResult)
                GenerateDocument(_outputFile, 0, string.Empty);
        }
        #endregion

        #region Event handlers
        void onLayoutValidated(object sender, LayoutCtrlEventArgs e)
        {
            try
            {
                if (File.Exists(e._outputPath))
                {
                    GenerateDocument(_outputFile, e._result, e._outputPath);
                    DialogResult = DialogResult.OK;
                }
            }
            catch (Exception ex)
            {
                _log.Error(ex.ToString());
            }
            Close();
        }
        void onLayoutCanceled(object sender, LayoutCtrlEventArgs e)
        {
            GenerateDocument(_outputFile, 0, string.Empty);
            Close();
        }
        #endregion

        #region Helpers
        private void GenerateDocument(string xmlFilePath, int order, string outputFile)
        {
            // delete existing document
            if (File.Exists(xmlFilePath))
                File.Delete(xmlFilePath);
            // instantiate document
            XmlDocument doc = new XmlDocument();
            XmlNode docNode = doc.CreateXmlDeclaration("1.0", "UTF-8", null);
            // output
            XmlElement outputElt = doc.CreateElement("output");
            doc.AppendChild(outputElt);
            // order attribute
            XmlAttribute orderAttribute = doc.CreateAttribute("order");
            orderAttribute.Value = string.Format("{0}", order);
            outputElt.Attributes.Append(orderAttribute);
            // file attribute
            if (!string.IsNullOrEmpty(outputFile))
            {
                XmlAttribute fileAttribute = doc.CreateAttribute("file");
                fileAttribute.Value = outputFile;
                outputElt.Attributes.Append(fileAttribute);
            }
            // save document
            doc.Save(xmlFilePath);
        }
        #endregion

        #region Public properties
        public string InputFile
        {
            get { return _inputFile; }
            set { _inputFile = value; }
        }
        public string OutputFile
        {
            get { return _outputFile; }
            set { _outputFile = value; }
        }
        public string FormatsFile
        {
            get { return _formatsFile; }
            set { _formatsFile = value; }
        }
        #endregion

        #region Data members
        private string _formatsFile;
        private string _inputFile;
        private string _outputFile;
        private static ILog _log = LogManager.GetLogger(typeof(FormLayoutIntro));
        #endregion


    }
}
