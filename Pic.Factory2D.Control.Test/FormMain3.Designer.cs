namespace Pic.Factory2D.Control.Test
{
    partial class FormMain3
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
            this.layoutIntroCtrl = new Pic.Factory2D.Control.LayoutIntroCtrl();
            this.SuspendLayout();
            // 
            // layoutIntroCtrl
            // 
            this.layoutIntroCtrl.Dock = System.Windows.Forms.DockStyle.Fill;
            this.layoutIntroCtrl.Location = new System.Drawing.Point(0, 0);
            this.layoutIntroCtrl.Name = "layoutIntroCtrl";
            this.layoutIntroCtrl.Size = new System.Drawing.Size(534, 361);
            this.layoutIntroCtrl.TabIndex = 0;
            // 
            // FormMain3
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(534, 361);
            this.Controls.Add(this.layoutIntroCtrl);
            this.Name = "FormMain3";
            this.Text = "FormMain3 (Pic.Factory2D.Control.Test)";
            this.ResumeLayout(false);

        }

        #endregion

        private LayoutIntroCtrl layoutIntroCtrl;
    }
}