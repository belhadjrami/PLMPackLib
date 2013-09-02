﻿using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace PicParam
{
    public partial class OptionPanelWindow : GLib.Options.OptionsPanel
    {
        public OptionPanelWindow()
        {
            InitializeComponent();
        }
        private void OptionPanelWindow_Load(object sender, EventArgs e)
        {
            checkBoxMaximized.Checked = Properties.Settings.Default.StartMaximized;
            checkBoxCenteredTitleBar.Checked = Properties.Settings.Default.ShowCenteredTitle;
            this._OptionsForm.OptionsSaving += new EventHandler(OptionPanelWindow_OptionsSaving);
        }
        private void OptionPanelWindow_OptionsSaving(object sender, EventArgs e)
        {
            Properties.Settings.Default.StartMaximized = checkBoxMaximized.Checked;
            Properties.Settings.Default.ShowCenteredTitle = checkBoxCenteredTitleBar.Checked;
        }
    }
}
