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
#endregion

namespace Pic.Plugin.GeneratorCtrl.Client
{
    public partial class FormMain : Form
    {
        #region Constructor
        public FormMain()
        {
            InitializeComponent();
            this.generatorCtrl.setComponentDirectory( Properties.Settings.Default.OutputPath );
        }
        #endregion

        #region Public Properties
        public string SourceFilePath
        {   set { this.generatorCtrl.setGeneratedSourceCodeFile(value); } }
        public string ComponentName
        {   set { this.generatorCtrl.setDrawingName(value); } }
        public string ComponentDescription
        {   set { this.generatorCtrl.setDrawingDescription(value); } }
        #endregion

        #region Handling GeneratorCtrl events
        private void onPluginViewerClosed(object sender, GeneratorCtrlEventArgs e)
        {
            this.TopMost = true; 
        }
        private void onPluginViewerOpened(object sender, GeneratorCtrlEventArgs e)
        {
            this.TopMost = false; 
        }
        #endregion
    }
}
