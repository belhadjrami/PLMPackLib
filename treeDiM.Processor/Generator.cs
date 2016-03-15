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
        public CutTool(int toolNumber, string toolType, string toolName, int[] color)
        {
            _number = toolNumber; _type = toolType; _name = toolName;
            for (int i = 0; i < 3; ++i) _color[i] = color[i];
        }

        public string _type;
        public string _name;
        public int _number;
        public int[] _color = new int[3];
    }

    public class Generator
    {
        #region Static data members
        private static double _epsilon = 0.1;
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

        public static bool Export(PicFactory factory, Dictionary<PicGraphics.LT, CutTool> dicTool
            , double[] dimensions
            , string materialName, double thickness
            , string filePath)
        {
            List<PicTypedDrawable> lEntities = new List<PicTypedDrawable>();
            ProcessEntities(factory, dicTool, ref lEntities);

            StringBuilder sb = new StringBuilder();

            // start file with keyword ";OptiSCOUT"
            sb.AppendLine(";OptiSCOUT");
            // total number of copies
            sb.AppendLine("SR1,1;");
            // number of copies in X
            sb.AppendLine("SR2,1;");
            // number of copies in Y
            sb.AppendLine("SR3;1;");
            // type of regmark (0=Circle)
            sb.AppendLine("SR4,0;");
            // material width in Y [mm]
            sb.AppendLine(string.Format("SR5,{0};", dimensions[1]));
            // material length in X [mm]
            sb.AppendLine(string.Format("SR6,{0};", dimensions[0]));
            // material thickness [mm]
            sb.AppendLine(string.Format("SR7,{0};", thickness));
            // used material 
            sb.AppendLine(string.Format("TM{0};",materialName));

            bool PenDown = false;
            Vector2D currentPt = Vector2D.Zero;
            PicGraphics.LT lt = PicGraphics.LT.LT_DEFAULT;

            // tool Up ->lift the tool
            sb.AppendLine("PU;");

            foreach (PicTypedDrawable entity in lEntities)
            {
                if (lt != entity.LineType)
                {
                    // change current line type
                    lt = entity.LineType;
                    // get corresponding CutTool
                    CutTool ct = dicTool[lt];
                    // SP -> change layer
                    sb.AppendLine(string.Format("SP{0};LN{1};LC{2},{3},{4};TN{5}"
                        , ct._number, ct._type, ct._color[0], ct._color[1], ct._color[2], ct._name));
                }
                Vector2D pt0 = Vector2D.Zero, pt1 = Vector2D.Zero;
                if (entity is PicSegment)
                {
                    PenDown = EntityPoints(entity, currentPt, ref pt0, ref pt1); // if connected, then PenDown
                    if (!PenDown)
                    {
                        sb.AppendLine(string.Format("PU;PA{0:0},{1:0};", 100 * pt0.X, 100 * pt0.Y));
                        sb.AppendLine("PD;");
                        PenDown = true;
                    }
                    sb.AppendLine(string.Format("PA{0:0},{1:0};", 100 * pt1.X, 100 * pt1.Y));
                }

                if (entity is PicArc)
                {
                    PenDown = EntityPoints(entity, currentPt, ref pt0, ref pt1);
                    if (!PenDown)
                    { 
                        sb.AppendLine(string.Format("PU;PA{0:0},{1:0};", 100 * pt0.X, 100 * pt0.Y));
                        sb.AppendLine("PD;");
                        PenDown = true;
                    }
                    PicArc arc = entity as PicArc;
                    Vector2D arcCenter = arc.Center;
                    sb.AppendLine(string.Format("AA{0:0},{1:0},{2}"
                        , 100 * arcCenter.X
                        , 100 * arcCenter.Y
                        , arc.Angle(pt0, pt1).ToString("F2", System.Globalization.CultureInfo.InvariantCulture)));
                }
                currentPt = pt1;

            }

            // write byte array to stream
            using (StreamWriter file = new StreamWriter(filePath, false) )
                file.WriteLine(sb);
            return true;
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
                // get entities with linetype = lt
                PicVisitorCollectTypedDrawables visitorCollect = new PicVisitorCollectTypedDrawables();
                factory.ProcessVisitor(visitorCollect, new PicFilterLineType(lt));
                List<PicTypedDrawable> tempList1 = visitorCollect.Entities;

                // move entities from tempList1 to tempList2 from point to point
                List<PicTypedDrawable> tempList2 = new List<PicTypedDrawable>();

                while (tempList1.Count > 0)
                {
                    int index = 0;
                    double minDist = double.MaxValue;
                    for (int i = 0; i < tempList1.Count; ++i)
                    {
                        double dist = DistanceEntityPt(tempList1[i], currentPt);
                        if (dist < minDist)
                        {
                            index = i;
                            minDist = dist;
                        }
                    }
                    currentPt = OppositePoint(tempList1[index], currentPt);
                    tempList2.Add(tempList1[index]);
                    tempList1.RemoveAt(index);
                }
                // concatenate list
                entities.AddRange(tempList2);
            }
        }  
        #endregion

        #region Helpers
        private static double DistanceEntityPt(PicTypedDrawable entity, Vector2D pt)
        {
            PicSegment seg = entity as PicSegment;
            if (null != seg)
                return Math.Min((seg.Pt0 - pt).GetLength(), (seg.Pt1 - pt).GetLength());
            PicArc arc = entity as PicArc;
            if (null != arc)
                return Math.Min((arc.Source - pt).GetLength(), (arc.Target - pt).GetLength());
            return 0.0;
        }
        private static Vector2D OppositePoint(PicTypedDrawable entity, Vector2D pt)
        {
            PicSegment seg = entity as PicSegment;
            if (null != seg)
            {
                if ((seg.Pt0 - pt).GetLength() < (seg.Pt1 - pt).GetLength())
                    return seg.Pt1;
                else
                    return seg.Pt0;
            }
            PicArc arc = entity as PicArc;
            if (null != arc)
            {
                if ((arc.Source - pt).GetLength() < (arc.Target - pt).GetLength())
                    return arc.Target;
                else
                    return arc.Source;
            }
            return Vector2D.Zero;
        }

        private static bool EntityPoints(PicTypedDrawable entity, Vector2D pt, ref Vector2D pt0, ref Vector2D pt1)
        {
            PicSegment seg = entity as PicSegment;
            if (null != seg)
            {
                if ((pt - seg.Pt0).GetLength() < (pt - seg.Pt1).GetLength())
                {   pt0 = seg.Pt0; pt1 = seg.Pt1; }
                else
                {   pt0 = seg.Pt1; pt1 = seg.Pt0; }
            }
            PicArc arc = entity as PicArc;
            if (null != arc)
            {
                if ((pt - arc.Source).GetLength() < (pt - arc.Target).GetLength())
                { pt0 = arc.Source; pt1 = arc.Target; }
                else
                { pt1 = arc.Target; pt0 = arc.Source; }
            }
            return (pt0 - pt).GetLength() < _epsilon;
        }
        #endregion
    }
}
