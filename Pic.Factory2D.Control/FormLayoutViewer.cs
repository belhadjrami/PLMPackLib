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

using Pic.Factory2D;
using Pic.Factory2D.Control;
using Sharp3D.Math.Core;
#endregion

namespace Pic.Factory2D.Control
{
    public partial class FormLayoutViewer : Form, IEntitySupplier
    {
        #region Data members
        private List<ImpositionSolution> solutions;
        private CardboardFormat _cardboardFormat;
        private static SolidBrush _textBrush = new SolidBrush(SystemColors.WindowText);
        private int _result = 0;
        private string _outputFilePath = string.Empty;
        private string _drawingName = string.Empty;
        #endregion

        #region Constructor
        public FormLayoutViewer()
        {
            InitializeComponent();
            listBoxSolutions.SelectedValueChanged += new EventHandler(listBoxSolutions_SelectedValueChanged);

            this.factoryViewer.ReflectionX = false;
            this.factoryViewer.ReflectionY = false;
            this.factoryViewer.ShowCotations = false;

            // hide nesting and about menu
            this.factoryViewer.ShowNestingMenu = false;
            this.factoryViewer.ShowAboutMenu = false;
 
        }
        #endregion

        #region IEntitySummplier implementation
        public void CreateEntities(PicFactory factory)
        {
            ImpositionSolution solution = listBoxSolutions.SelectedItem as ImpositionSolution;
            if (null == solution) return;
            solution.CreateEntities(factory);
            factory.InsertCardboardFormat(solution.CardboardPosition, solution.CardboardDimensions);
        }
        #endregion

        #region Public properties
        public List<ImpositionSolution> Solutions
        {
            set
            {
                solutions = value;
                // insert in listbox
                listBoxSolutions.Items.Clear();
                listBoxSolutions.Items.AddRange(solutions.ToArray());
            }
        }
        public CardboardFormat Format
        {
            get { return _cardboardFormat; }
            set { _cardboardFormat = value; }
        }
        public string DrawingName
        {
            get { return _drawingName; }
            set { _drawingName = value; }
        }
        public int Result
        { get { return _result; } }
        public string OutputFilePath
        { get { return _outputFilePath; } }
        #endregion

        #region Form override
        protected override void OnLoad(EventArgs e)
        {
            base.OnLoad(e);
            // initialize list solution
            if (listBoxSolutions.Items.Count > 0)
                listBoxSolutions.SelectedIndex = 0;
            // refresh
            factoryViewer.Refresh();
        }
        protected override void OnClosed(EventArgs e)
        {
            base.OnClosed(e);

        }
        #endregion

        #region Event handlers
        /// <summary>
        /// listBoxSolution: selected item changed
        /// </summary>
        void listBoxSolutions_SelectedValueChanged(object sender, EventArgs e)
        {
            factoryViewer.Refresh();

            ImpositionSolution solution = listBoxSolutions.SelectedItem as ImpositionSolution;
            if (null == solution) return;

            // numbers
            lblValueCardboardFormat.Text = string.Format(": {0} x {1}",
                (int)Math.Ceiling(solution.CardboardDimensions.X),
                (int)Math.Ceiling(solution.CardboardDimensions.Y));
            lblValueCardboardEfficiency.Text = string.Format(": {0:0.#} %",
                100.0 * solution.Area / (solution.CardboardDimensions.X * solution.CardboardDimensions.Y));
            lblValueNumbers.Text = string.Format(": {0} ({1} x {2})",
                solution.PositionCount, solution.Rows, solution.Cols);
            // lengthes
            lblValueLengthCut.Text = string.Format(": {0:0.###} m", solution.LengthCut / 1000.0);
            lblValueLengthFold.Text = string.Format(": {0:0.###} m ", solution.LengthFold / 1000.0);
            lblValueLengthTotal.Text = string.Format(": {0:0.###} m", (solution.LengthCut + solution.LengthFold) / 1000.0);
            // area
            lblValueArea.Text = string.Format(": {0:0.###} m²", solution.Area * 1.0E-06);
            lblValueFormat.Text = string.Format(": {0:0.#} x {1:0.#}", solution.Width, solution.Height);
            lblValueEfficiency.Text = string.Format(": {0:0.#} %", 100.0 * solution.Area / (solution.Width * solution.Height));
        }
        /// <summary>
        /// Owner draw mode item drawing method
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void listBoxSolutions_DrawItem(object sender, DrawItemEventArgs e)
        {
            Graphics g = e.Graphics;

            int itemHeight = listBoxSolutions.ItemHeight;
            // draw image
            Rectangle _drawRect = new Rectangle(0, 0, itemHeight, itemHeight);
            Rectangle scaledRect = _drawRect;
            Rectangle imageRect = e.Bounds;
            imageRect.Y += 1;
            imageRect.Height = scaledRect.Height;
            imageRect.X += 2;
            imageRect.Width = scaledRect.Width;

            if (null != solutions[e.Index].Thumbnail)
                g.DrawImage(solutions[e.Index].Thumbnail, imageRect);
            g.DrawRectangle(Pens.Black, imageRect);

            // draw string
            Rectangle textRect = new Rectangle(
                imageRect.Right + 2
                , imageRect.Y
                , e.Bounds.Width - imageRect.Width - 4
                , itemHeight);

            if ((e.State & DrawItemState.Selected) == DrawItemState.Selected)
            {
                _textBrush.Color = SystemColors.Highlight;
                g.FillRectangle(_textBrush, textRect);
                _textBrush.Color = SystemColors.HighlightText;
            }
            else
            {
                _textBrush.Color = SystemColors.Window;
                g.FillRectangle(_textBrush, textRect);
                _textBrush.Color = SystemColors.WindowText;
            }
            g.DrawString(
                solutions[e.Index].ToString()
                , e.Font
                , _textBrush
                , textRect);
        }
        #region Save/cancel buttons
        private void onSaveAsNewFile(object sender, EventArgs e)
        {
            saveFileDialog.FileName = string.Format("{0}_layout.des", _drawingName);
            if (DialogResult.OK == saveFileDialog.ShowDialog())
            {
                _result = 1;
                _outputFilePath = saveFileDialog.FileName;
                factoryViewer.WriteExportFile(_outputFilePath, "des");

                DialogResult = DialogResult.OK;
                Close();
            }
        }
        private void onSaveToCurrentFile(object sender, EventArgs e)
        {
            _result = 2;
            _outputFilePath = Path.ChangeExtension(Path.GetTempFileName(), "des");
            factoryViewer.WriteExportFile(_outputFilePath, "des"); 

            this.DialogResult = DialogResult.OK;
            Close();
        }
        #endregion
        #region Paint event handlers
        /// <summary>
        /// Paint event handler for Cut length label
        /// </summary>
        private void pbCut_Paint(object sender, PaintEventArgs e)
        {
            Size sz = pbCut.Size;
            e.Graphics.DrawLine(new Pen(Color.Red), new Point(0, sz.Height / 2), new Point(sz.Width / 2, sz.Height / 2));
        }
        /// <summary>
        /// Paint event handler for Fold length
        /// </summary>
        private void pbFold_Paint(object sender, PaintEventArgs e)
        {
            Size sz = pbFold.Size;
            e.Graphics.DrawLine(new Pen(Color.Blue), new Point(0, sz.Height / 2), new Point(sz.Width / 2, sz.Height / 2));
        }
        #endregion

        private void onCancel(object sender, EventArgs e)
        {

        }

        #endregion
    }
}
