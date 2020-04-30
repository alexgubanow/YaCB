using System;
using System.Linq;
using HidLibrary;

namespace hidTestTool
{
    class Program
    {
        private static HidDevice _device;
        private static bool _attached;

        static void Main()
        {
            _device = HidDevices.Enumerate(0x0483, 0x5750).FirstOrDefault();

            if (_device == null)
            {
                Console.WriteLine("Could not find a dev, press any key to exit.");
                Console.ReadKey();
            }


            _device.OpenDevice();

            _device.Inserted += DeviceAttachedHandler;
            _device.Removed += DeviceRemovedHandler;

            _device.MonitorDeviceEvents = true;
            _device.ReadReport(OnReport);

            Console.WriteLine("dev found, press Escape to exit.");
            var keypr = Console.ReadKey().Key;
            while (keypr != ConsoleKey.Escape)
            {
                keypr = Console.ReadKey().Key;
                if (keypr != ConsoleKey.Escape)
                {
                    HidReport report = _device.CreateReport();
                    report.ReportId = 1;
                    report.Data[0] = Convert.ToByte(keypr);
                    _device.WriteReport(report);
                }
            }
            _device.CloseDevice();
        }

        private static void OnReport(HidReport report)
        {
            if (_attached == false) { return; }
            Console.WriteLine("ReportID: " + report.ReportId + "    Data: " + string.Join(" ", report.Data));

            _device.ReadReport(OnReport);
        }

        private static void DeviceAttachedHandler()
        {
            _attached = true;
            Console.WriteLine("Dev attached.");
            _device.ReadReport(OnReport);
        }

        private static void DeviceRemovedHandler()
        {
            _attached = false;
            Console.WriteLine("Dev removed.");
        }
    }
}
