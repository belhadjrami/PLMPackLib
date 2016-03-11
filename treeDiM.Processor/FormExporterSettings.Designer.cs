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
            this.bnOK.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.bnOK.DialogResult = System.Windows.Forms.DialogResult.OK;
            this.bnOK.Location = new System.Drawing.Point(429, 13);
            this.bnOK.Name = "bnOK";
            this.bnOK.Size = new System.Drawing.Size(75, 23);
            this.bnOK.TabIndex = 0;
            this.bnOK.Text = "OK";
            this.bnOK.UseVisualStyleBackColor = true;
            // 
            // bnCancel
            // 
            this.bnCancel.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.bnCancel.DialogResult = System.Windows.Forms.DialogResult.Cancel;
            this.bnCancel.Location = new System.Drawing.Point(429, 43);
            this.bnCancel.Name = "bnCancel";
            this.bnCancel.Size = new System.Drawing.Size(75, 23);
            this.bnCancel.TabIndex = 1;
            this.bnCancel.Text = "Cancel";
            this.bnCancel.UseVisualStyleBackColor = true;
            // 
            // lbCutJobType
            // 
            this.lbCutJobType.AutoSize = true;
            this.lbCutJobType.Location = new System.Drawing.Point(13, 13);
            this.lbCutJobType.Name = "lbCutJobType";
            this.lbCutJobType.Size = new System.Drawing.Size(63, 13);
            this.lbCutJobType.TabIndex = 2;
            this.lbCutJobType.Text = "Cut job type";
            // 
            // lbOutputFilePath
            // 
            this.lbOutputFilePath.AutoSize = true;
            this.lbOutputFilePath.Location = new System.Drawing.Point(13, 43);
            this.lbOutputFilePath.Name = "lbOutputFilePath";
            this.lbOutputFilePath.Size = new System.Drawing.Size(39, 13);
            this.lbOutputFilePath.TabIndex = 3;
            this.lbOutputFilePath.Text = "Output";
            // 
            // cbCutJobType
            // 
            this.cbCutJobType.FormattingEnabled = true;
            this.cbCutJobType.Location = new System.Drawing.Point(100, 13);
            this.cbCutJobType.Name = "cbCutJobType";
            this.cbCutJobType.Size = new System.Drawing.Size(153, 21);
            this.cbCutJobType.TabIndex = 4;
            this.cbCutJobType.SelectedIndexChanged += new System.EventHandler(this.onCutJobTypeChanged);
            // 
            // fileSelectOutput
            // 
            this.fileSelectOutput.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.fileSelectOutput.Location = new System.Drawing.Point(99, 43);
            this.fileSelectOutput.Name = "fileSelectOutput";
            this.fileSelectOutput.Size = new System.Drawing.Size(323, 20);
            this.fileSelectOutput.TabIndex = 5;
            // 
            // trackBarEntities
            // 
            this.trackBarEntities.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.trackBarEntities.Location = new System.Drawing.Point(12, 294);
            this.trackBarEntities.Name = "trackBarEntities";
            this.trackBarEntities.Size = new System.Drawing.Size(491, 45);
            this.trackBarEntities.TabIndex = 6;
            this.trackBarEntities.TickStyle = System.Windows.Forms.TickStyle.None;
            this.trackBarEntities.Scroll += new System.EventHandler(this.onScroll);
            // 
            // factoryViewerCurrent
            // 
            this.factoryViewerCurrent.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.factoryViewerCurrent.ForeColor = System.Drawing.Color.White;
            this.factoryViewerCurrent.Location = new System.Drawing.Point(13, 72);
            this.factoryViewerCurrent.Name = "factoryViewerCurrent";
            this.factoryViewerCurrent.ReflectionX = false;
            this.factoryViewerCurrent.ReflectionY = false;
            this.factoryViewerCurrent.ShowAboutMenu = false;
            this.factoryViewerCurrent.ShowCotations = false;
            this.factoryViewerCurrent.ShowNestingMenu = false;
            this.factoryViewerCurrent.Size = new System.Drawing.Size(491, 187);
            this.factoryViewerCurrent.TabIndex = 7;
            // 
            // FormExporterSettings
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(516, 337);
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
            this.Text = "Exporter settings...";
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