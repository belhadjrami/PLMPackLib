﻿#region Using directives
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
// loging
using log4net;
using log4net.Config;
// treeDiM
using System.Drawing;
using treeDiM.DrawingQuery;
#endregion

namespace treeDiM.DrawingQuery.Test
{
    class Program
    {
        #region Static data members
        public static readonly ILog _log = LogManager.GetLogger(typeof(Program));
        #endregion

        #region Main
        static void Main(string[] args)
        {
            XmlConfigurator.Configure();
            try
            {
                string filePath = @"K:\GitHub\PLMPackLib\Samples\Vaillant\testXML.des";
                string outDir = Path.GetDirectoryName(filePath);
                string fileName = Path.GetFileNameWithoutExtension(filePath);

                _log.WarnFormat("Processing file {0}", filePath);

                // load file and get querier
                DESQuerier querier = DESQuerier.LoadFile(filePath);

                // images
                Console.WriteLine();
                Console.WriteLine("#### Images:");
                // get image with dimensions
                Console.WriteLine("Writing file {0}", Path.Combine(outDir, "imageWDim.png"));
                querier.ImageToFile(Path.Combine(outDir, "imageWDim.png"), 1024, true, null, null);
                // get image without dimensions
                Console.WriteLine("Writing file {0}", Path.Combine(outDir, "imageWODim.png"));
                querier.ImageToFile(Path.Combine(outDir, "imageWODim.png"), 1024, false, null, null);

                // groups and layers
                Console.WriteLine();
                Console.WriteLine("#### Groups:");
                Dictionary<short, string> grps = querier.Groups;
                foreach (short grpId in grps.Keys)
                    Console.WriteLine(string.Format("Group Id={0} Name={1}", grpId, grps[grpId]));

                Console.WriteLine();
                Console.WriteLine("#### Layers:");
                Dictionary<short, string> layers = querier.Layers;
                foreach (short layerId in layers.Keys)
                    Console.WriteLine(string.Format("Group Id={0} Name={1}", layerId, layers[layerId]));

                // list all questions/answers
                Console.WriteLine();
                Console.WriteLine("#### All questions:");
                Dictionary<string, string> questions = querier.Questionnaire;
                foreach (string sKey in questions.Keys)
                    Console.WriteLine("{0} = {1}", sKey, questions[sKey]);

                // single question
                Console.WriteLine();
                Console.WriteLine("#### Single question:");
                string question = "Client";
                string answer = string.Empty;
                if (querier.GetQuestionAnswer(question, ref answer))
                    Console.WriteLine("Answer to question \"{0}\" is \"{1}\"", question, answer);

                // Computed data
                Console.WriteLine();
                Console.WriteLine("#### Diecut lengthes:");
                Dictionary<string, double> diecutLengthes = querier.DiecutLengthes;
                foreach (string sKey in diecutLengthes.Keys)
                    Console.WriteLine("{0} = {1} mm", sKey, diecutLengthes[sKey]);

                Console.WriteLine();
                _log.WarnFormat("Done...");
            }
            catch (Exception ex)
            {
                _log.Error(ex.ToString());
            }
        }
        #endregion
    }
}
