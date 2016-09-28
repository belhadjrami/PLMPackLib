#region Using directives
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;

using log4net;
using log4net.Config;

using CommandLine;
using CommandLine.Text;
#endregion

namespace Pic.Plugin.GeneratorCtrl.Client
{
    class Options
    {
        [Option('s', "source", Required = true, HelpText = "Generated source file path")]
        public string SourceFilePath { get; set; }
        [Option('n', "name", Required = false, HelpText = "Component name")]
        public string Name { get; set; }
        [Option('d', "description", Required = false, HelpText = "Component description")]
        public string Description { get; set; }
        [HelpOption]
        public string GetUsage()
        {
            return HelpText.AutoBuild(this,
              (HelpText current) => HelpText.DefaultParsingErrorsHandler(this, current));
        }
    }
    static class Program
    {
        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        [STAThread]
        static void Main(string[] args)
        {
            string assemblyName = System.Reflection.Assembly.GetExecutingAssembly().CodeBase;

            try
            {
                // log4net
                XmlConfigurator.Configure();
                 _log.Info(string.Format("{0} : Begining...", assemblyName));

                Application.EnableVisualStyles();
                Application.SetCompatibleTextRenderingDefault(false);

                var options = new Options();
                if (CommandLine.Parser.Default.ParseArguments(args, options))
                {
                    if (!File.Exists(options.SourceFilePath))
                        throw new FileNotFoundException(string.Format("File {0} not found", options.SourceFilePath), options.SourceFilePath);
                    FormMain form = new FormMain();
                    form.SourceFilePath = options.SourceFilePath;
                    form.ComponentName = options.Name;
                    form.ComponentDescription
                        = string.IsNullOrEmpty(options.Description) ? options.Name : options.Description;
                    Application.Run(form);
                }
                else
                    MessageBox.Show(options.GetUsage());
            }
            catch (Exception ex)
            {
                _log.Error( string.Format("Exception : {0}", ex.Message) );
            }
            finally
            {
                _log.Info( string.Format("{0} : Ending...", assemblyName) );
            }
        }

        #region Data members
        static ILog _log = LogManager.GetLogger(typeof(Program));
        #endregion
    }
}
