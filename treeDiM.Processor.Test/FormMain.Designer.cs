namespace treeDiM.Processor.Test
{
    partial class FormMain
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
            this.bnExport = new System.Windows.Forms.Button();
            this.lbFilePath = new System.Windows.Forms.Label();
            this.fileSelect = new TreeDim.UserControls.FileSelect();
            this.SuspendLayout();
            // 
            // bnExport
            // 
            this.bnExport.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.bnExport.Location = new System.Drawing.Point(192, 39);
            this.bnExport.Name = "bnExport";
            this.bnExport.Size = new System.Drawing.Size(75, 23);
            this.bnExport.TabIndex = 0;
            this.bnExport.Text = "Export!";
            this.bnExport.UseVisualStyleBackColor = true;
            this.bnExport.Click += new System.EventHandler(this.onShowForm);
            // 
            // lbFilePath
            // 
            this.lbFilePath.AutoSize = true;
            this.lbFilePath.Location = new System.Drawing.Point(13, 13);
            this.lbFilePath.Name = "lbFilePath";
            this.lbFilePath.Size = new System.Drawing.Size(47, 13);
            this.lbFilePath.TabIndex = 1;
            this.lbFilePath.Text = "File path";
            // 
            // fileSelect
            // 
            this.fileSelect.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.fileSelect.Location = new System.Drawing.Point(67, 13);
            this.fileSelect.Name = "fileSelect";
            this.fileSelect.Size = new System.Drawing.Size(200, 20);
            this.fileSelect.TabIndex = 2;
            this.fileSelect.FileNameChanged += new System.EventHandler(this.onFileNameChanged);
            // 
            // FormMain
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(284, 82);
            this.Controls.Add(this.fileSelect);
            this.Controls.Add(this.lbFilePath);
            this.Controls.Add(this.bnExport);
            this.MaximizeBox = false;
            this.Name = "FormMain";
            this.Text = "FormMain";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button bnExport;
        private System.Windows.Forms.Label lbFilePath;
        private TreeDim.UserControls.FileSelect fileSelect;
    }
}

