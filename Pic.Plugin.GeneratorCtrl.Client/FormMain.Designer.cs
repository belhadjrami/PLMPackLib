namespace Pic.Plugin.GeneratorCtrl.Client
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
            this.generatorCtrl = new Pic.Plugin.GeneratorCtrl.GeneratorCtrl();
            this.SuspendLayout();
            // 
            // generatorCtrl
            // 
            this.generatorCtrl.Dock = System.Windows.Forms.DockStyle.Fill;
            this.generatorCtrl.Location = new System.Drawing.Point(0, 0);
            this.generatorCtrl.Name = "generatorCtrl";
            this.generatorCtrl.OutputPath = "C:\\Users\\François\\AppData\\Local\\Temp\\.dll";
            this.generatorCtrl.PluginVersion = "2.0.0.0";
            this.generatorCtrl.Size = new System.Drawing.Size(684, 561);
            this.generatorCtrl.TabIndex = 0;
            this.generatorCtrl.PluginValidated += new Pic.Plugin.GeneratorCtrl.GeneratorCtrl.GeneratorCtlrHandler(this.onPluginViewerClosed);
            this.generatorCtrl.PluginViewerClosed += new Pic.Plugin.GeneratorCtrl.GeneratorCtrl.GeneratorCtlrHandler(this.onPluginViewerClosed);
            this.generatorCtrl.PluginGenerated += new Pic.Plugin.GeneratorCtrl.GeneratorCtrl.GeneratorCtlrHandler(this.onPluginViewerOpened);
            // 
            // FormMain
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(684, 561);
            this.Controls.Add(this.generatorCtrl);
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "FormMain";
            this.ShowIcon = false;
            this.ShowInTaskbar = false;
            this.Text = "FormMain";
            this.TopMost = true;
            this.ResumeLayout(false);
        }

        #endregion

        #region Data members
        private GeneratorCtrl generatorCtrl;
        #endregion
    }
}

