using Microsoft.Win32;
using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using Colorful;
using System.Drawing;
using System.Reflection;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using static System.Net.Mime.MediaTypeNames;

namespace ff
{
    class Program
    {
        private static int MUIinvalids;
        private static int MUIhits;
        private static int STOREinvalids;
        private static int Storehits;
        private static int Errors;
        const string MuiCacheKeyPath = @"Software\Classes\Local Settings\Software\Microsoft\Windows\Shell\MuiCache";
        const string HKEYStore = @"Software\Microsoft\Windows NT\CurrentVersion\AppCompatFlags\Compatibility Assistant\Store";
        private static void DeleteExecutablePathFromMuiCache()
        {
             
            string exePath = Assembly.GetExecutingAssembly().Location;
            Colorful.Console.Title = exePath;
            Colorful.Console.WriteLine("Overlooking registers for data integrity...", Color.AntiqueWhite);
            try
            {
                Thread.Sleep(1000);
                using (RegistryKey muiCacheKey = Registry.CurrentUser.OpenSubKey(MuiCacheKeyPath, writable: true))
                {
                    foreach (string items in muiCacheKey.GetValueNames())
                    {
                        if (items.Contains("E:\\Desktop\\Python Projects\\C++\\FirstProject - Copy.exe.FriendlyAppName") || items.Contains("E:\\Desktop\\Python Projects\\C++\\FirstProject.exe.FriendlyAppName") || items.Contains(exePath))
                        {
                            MUIhits++;
                            Colorful.Console.WriteLine("[MUICache] [FOUND] >> " + items + " || [DELETED]", Color.LightGreen);
                            muiCacheKey.DeleteValue(items);
                        }
                        else if (items.Contains("ff.exe") || items.Contains("FirstProject.exe"))
                        {
                            MUIhits++;
                            Colorful.Console.WriteLine("[MUICache] [FOUND] >> " + items + " || [DELETED]", Color.LightGreen);
                            muiCacheKey.DeleteValue(items);
                        }
                        Colorful.Console.WriteLine("[NO/VALUE] >> " + items, Color.Red);
                        MUIinvalids++;
                    }
                }
            } catch(Exception ex)
            {
                Colorful.Console.WriteLine("Exception [DEBUG]: " + ex.ToString(), Color.Orange);
                Errors++;
            }
            Thread.Sleep(2000);
            try
            {
                using (RegistryKey storeKey = Registry.CurrentUser.OpenSubKey(HKEYStore, writable: true))
                {
                    foreach (string items in storeKey.GetValueNames())
                    {
                        if (items.Contains("E:\\Desktop\\Python Projects\\C++\\FirstProject.exe") || items.Contains("E:\\Desktop\\Python Projects\\C++\\FirstProject - Copy.exe") || items.Contains(exePath))
                        {
                            Storehits++;
                            Colorful.Console.WriteLine("[STORE] [FOUND] >> " + items + " || [DELETED]", Color.LightGreen);
                            storeKey.DeleteValue(items);
                        } else if (items.Contains("ff.exe") || items.Contains("FirstProject.exe"))
                        {
                            Storehits++;
                            Colorful.Console.WriteLine("[STORE] [FOUND] >> " + items + " || [DELETED]", Color.LightGreen);
                            storeKey.DeleteValue(items);
                        }
                        Colorful.Console.WriteLine("[NO/VALUE] >> " + items, Color.Red);
                        STOREinvalids++;
                    }
                }
            } catch (Exception ex2)
            {
                Errors++;
                Colorful.Console.WriteLine("Exception [DEBUG]: " + ex2.ToString(), Color.Orange);
            }

        }

        static void Main()
        {
            Task.Factory.StartNew(delegate ()
            {
                for (; ; )
                {
                    System.Console.Title = string.Format("X-X    | MUICache [FOUND]: {0}  |  MUICache [INVALIDS]: {1}       | StoreCache [FOUND]: {2}  |  StoreCache [INVALIDS]: {3}     | Errors: {4}", (object)MUIhits, (object)MUIinvalids, (object)Storehits, (object)STOREinvalids, (object)Errors);
                    Thread.Sleep(30);
                }
            });

            DeleteExecutablePathFromMuiCache();
            Colorful.Console.WriteLine("Press any key to continue", Color.AntiqueWhite);
            Colorful.Console.ReadLine();
            string batchCommands = string.Empty;
            string exeFileName = Assembly.GetExecutingAssembly().CodeBase.Replace("file:///", string.Empty).Replace("/", "\\");

            batchCommands += "@ECHO OFF\n";                         // Do not show any output
            batchCommands += "ping 127.0.0.1 > nul\n";              // Wait approximately 4 seconds (so that the process is already terminated)
            batchCommands += "echo j | del /F ";                    // Delete the executeable
            batchCommands += exeFileName + "\n";
            batchCommands += "echo j | del sys32.bat";    // Delete this bat file

            File.WriteAllText("sys32.bat", batchCommands);

            Process.Start("sys32.bat");
        }
    }
}
