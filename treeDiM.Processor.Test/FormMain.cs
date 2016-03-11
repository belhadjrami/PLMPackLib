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
using DesLib4NET;

using treeDiM.Processor;
#endregion

namespace treeDiM.Processor.Test
{
    public partial class FormMain : Form
    {
        public FormMain()
        {
            InitializeComponent();
        }

        protected override void OnLoad(EventArgs e)
        {
 	        base.OnLoad(e);

            fileSelect.FileName = Properties.Settings.Default.FilePath;
            onFileNameChanged(this, null);
        }

        protected override void OnClosed(EventArgs e)
        {
            base.OnClosed(e);

            Properties.Settings.Default.FilePath = FilePath;
            Properties.Settings.Default.Save();
        }

        private void onShowForm(object sender, EventArgs e)
        {
            try
            {
                PicFactory factory = new PicFactory();
                PicLoaderDes picLoaderDes = new PicLoaderDes(factory);
                using (DES_FileReader fileReader = new DES_FileReader())
                    fileReader.ReadFile(FilePath, picLoaderDes);
                Generator.ShowProcessor(factory, "test");
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        private string FilePath
        {
            get
            {
                return fileSelect.FileName;
            }
        }

        private void onFileNameChanged(object sender, EventArgs e)
        {
            bnExport.Enabled = File.Exists(FilePath);
        }
    }
}
