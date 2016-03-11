#region Using directives
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Windows.Forms;

using Pic.Factory2D;

using Sharp3D.Math.Core;
#endregion

namespace treeDiM.Processor
{
    public class CutTool
    {
        public CutTool(int toolNumber, string toolName, int[] color, int step)
        {
            _number = toolNumber; _name = toolName; _step = step;
            for (int i = 0; i < 3; ++i) _color[i] = color[i];
        }

        public string _name;
        public int _number;
        public int _step = 0;
        public int[] _color = new int[3];
    }

    public class ComparerNearest : IComparer<PicTypedDrawable>
    {
        public ComparerNearest(Vector2D pt)
        {
            _pt = pt;
        }

        public override int Compare(PicTypedDrawable t1, PicTypedDrawable t2)
        {
            double minDistT1 = Double.MaxValue, minDistT2 = Double.MaxValue;

            return minDistT1 < minDistT2 ? 1 : 0;
        }

        Vector2D _pt;
    }

    public class Generator
    {
        #region Public Properties
        #endregion

        #region Static methods
        public static void ShowProcessor(Pic.Factory2D.PicFactory factory, string fileName)
        {
            // sanity checks
            if (!File.Exists(Properties.Settings.Default.SettingsFilePath))
            {
                MessageBox.Show(string.Format("Exporter settings file ({0}) could not be found!", Properties.Settings.Default.SettingsFilePath));
                return;
            }

            // show form
            FormExporterSettings form = new FormExporterSettings();
            form.Factory = factory;
            form.FileName = fileName;
            if (DialogResult.OK == form.ShowDialog()) { }
        }

        public static void ProcessEntities(PicFactory factory, Dictionary<PicGraphics.LT, CutTool> dictTool, ref List<PicTypedDrawable> entities)
        {
            if (null == entities) entities = new List<PicTypedDrawable>();
            entities.Clear();
            // get factory bounding box
            PicVisitorBoundingBox visitorBBox = new PicVisitorBoundingBox();
            factory.ProcessVisitor(visitorBBox, new PicFilterTypedDrawable());
            // translate factory
            PicVisitorTransform visitorTranslation = new PicVisitorTransform(Transform2D.Translation(-visitorBBox.Box.PtMin));
            factory.ProcessVisitor(visitorTranslation, new PicFilter());
            // sort entities by type
            Vector2D currentPt = Vector2D.Zero;
            foreach (PicGraphics.LT lt in dictTool.Keys)
            {
                PicVisitorCollectTypedDrawables visitorCollect = new PicVisitorCollectTypedDrawables();
                factory.ProcessVisitor(visitorCollect, new PicFilterLineType(lt));
                List<PicTypedDrawable> tempList1 = visitorCollect.Entities;
                List<PicTypedDrawable> tempList2 = new List<PicTypedDrawable>();

                while (tempList1.Count > 0)
                {
                    tempList1.Sort(new ComparerNearest(currentPt));
                    tempList2.Add(tempList1.First());
                    tempList1.RemoveAt(0);
                }
                // concatenate list
                entities.AddRange(tempList2);
            }
        }
        #endregion
    }
}
