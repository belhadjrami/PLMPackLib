#region Using directives
using System;
using System.Collections.Generic;
using System.Linq;
using System.Windows.Forms;
using System.Reflection;
using System.IO;

using CommandLine;
#endregion

namespace Pic.Factory2D.Control.Layout
{
    /// <summary>
    /// Class to receive parsed values
    /// </summary>
    class Options
    {
        [Option('i', "input", Required = true, HelpText = "Input file to be processed.")]
        public string InputFile { get; set; }

        [Option('o', "output", Required = true, HelpText = "Output XML file")]
        public string OutputFile { get; set; }
    }

    static class Program
    {
        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        [STAThread]
        static void Main(string[] args)
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);

             var options = new Options();
             if (CommandLine.Parser.Default.ParseArguments(args, options))
             {
                 if (File.Exists(options.OutputFile))
                     File.Delete(options.OutputFile);
                 if (File.Exists(options.InputFile))
                 {
                     FormLayoutIntro form = new FormLayoutIntro();
                     form.InputFile = options.InputFile;
                     form.OutputFile = options.OutputFile;
                     form.FormatsFile = Path.Combine( Path.GetDirectoryName(Assembly.GetEntryAssembly().Location), "CardboardFormats.xml" );

                     Application.Run( form );
                 }
             }
        }
    }
}
