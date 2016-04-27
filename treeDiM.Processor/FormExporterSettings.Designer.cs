namespace treeDiM.Processor
{
    partial class FormExporterSettings
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(FormExporterSettings));
            this.bnOK = new System.Windows.Forms.Button();
            this.bnCancel = new System.Windows.Forms.Button();
            this.lbCutJobType = new System.Windows.Forms.Label();
            this.lbOutputFilePath = new System.Windows.Forms.Label();
            this.cbCutJobType = new System.Windows.Forms.ComboBox();
            this.fileSelectOutput = new TreeDim.UserControls.FileSelect();
            this.trackBarEntities = new System.Windows.Forms.TrackBar();
            this.factoryViewerCurrent = new Pic.Factory2D.Control.FactoryViewer();
            ((System.ComponentModel.ISupportInitialize)(this.trackBarEntities)).BeginInit();
            this.SuspendLayout();
            // 
            // bnOK
            // 
            resources.ApplyResources(this.bnOK, "bnOK");
            this.bnOK.DialogResult = System.Windows.Forms.DialogResult.OK;
            this.bnOK.Name = "bnOK";
            this.bnOK.UseVisualStyleBackColor = true;
            this.bnOK.Click += new System.EventHandler(this.onOK);
            // 
            // bnCancel
            // 
            resources.ApplyResources(this.bnCancel, "bnCancel");
            this.bnCancel.DialogResult = System.Windows.Forms.DialogResult.Cancel;
            this.bnCancel.Name = "bnCancel";
            this.bnCancel.UseVisualStyleBackColor = true;
            // 
            // lbCutJobType
            // 
            resources.ApplyResources(this.lbCutJobType, "lbCutJobType");
            this.lbCutJobType.Name = "lbCutJobType";
            // 
            // lbOutputFilePath
            // 
            resources.ApplyResources(this.lbOutputFilePath, "lbOutputFilePath");
            this.lbOutputFilePath.Name = "lbOutputFilePath";
            // 
            // cbCutJobType
            // 
            resources.ApplyResources(this.cbCutJobType, "cbCutJobType");
            this.cbCutJobType.FormattingEnabled = true;
            this.cbCutJobType.Name = "cbCutJobType";
            this.cbCutJobType.SelectedIndexChanged += new System.EventHandler(this.onCutJobTypeChanged);
            // 
            // fileSelectOutput
            // 
            resources.ApplyResources(this.fileSelectOutput, "fileSelectOutput");
            this.fileSelectOutput.Filter = "(*.oxf)|oxf|All files (*.*)|*.*";
            this.fileSelectOutput.Name = "fileSelectOutput";
            this.fileSelectOutput.SaveMode = true;
            // 
            // trackBarEntities
            // 
            resources.ApplyResources(this.trackBarEntities, "trackBarEntities");
            this.trackBarEntities.Name = "trackBarEntities";
            this.trackBarEntities.TickStyle = System.Windows.Forms.TickStyle.None;
            this.trackBarEntities.Scroll += new System.EventHandler(this.onScroll);
            // 
            // factoryViewerCurrent
            // 
            resources.ApplyResources(this.factoryViewerCurrent, "factoryViewerCurrent");
            this.factoryViewerCurrent.ForeColor = System.Drawing.Color.White;
            this.factoryViewerCurrent.Name = "factoryViewerCurrent";
            this.factoryViewerCurrent.ReflectionX = false;
            this.factoryViewerCurrent.ReflectionY = false;
            this.factoryViewerCurrent.ShowAboutMenu = false;
            this.factoryViewerCurrent.ShowCotations = false;
            this.factoryViewerCurrent.ShowNestingMenu = false;
            // 
            // FormExporterSettings
            // 
            resources.ApplyResources(this, "$this");
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.Controls.Add(this.factoryViewerCurrent);
            this.Controls.Add(this.trackBarEntities);
            this.Controls.Add(this.fileSelectOutput);
            this.Controls.Add(this.cbCutJobType);
            this.Controls.Add(this.lbOutputFilePath);
            this.Controls.Add(this.lbCutJobType);
            this.Controls.Add(this.bnCancel);
            this.Controls.Add(this.bnOK);
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "FormExporterSettings";
            ((System.ComponentModel.ISupportInitialize)(this.trackBarEntities)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button bnOK;
        private System.Windows.Forms.Button bnCancel;
        private System.Windows.Forms.Label lbCutJobType;
        private System.Windows.Forms.Label lbOutputFilePath;
        private System.Windows.Forms.ComboBox cbCutJobType;
        private TreeDim.UserControls.FileSelect fileSelectOutput;
        private System.Windows.Forms.TrackBar trackBarEntities;
        private Pic.Factory2D.Control.FactoryViewer factoryViewerCurrent;
    }
}