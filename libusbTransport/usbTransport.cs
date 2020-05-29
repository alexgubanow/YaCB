using Device.Net;
#if (!LIBUSB)
using Usb.Net.Windows;
using Hid.Net.Windows;
#else
using Device.Net.LibUsb;
#endif
using System;
using System.Collections.Concurrent;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Diagnostics;
using System.Threading;
using System.Threading.Tasks;

namespace zeroxzeroh.libusbTransport
{
    public class UsbTransport
    {
        public ObservableCollection<UsbDevice> Devices { get;  set; }
        private static readonly DebugLogger Logger = new DebugLogger();
        private static readonly DebugTracer Tracer = new DebugTracer();

        public UsbTransport()
        {
#if (LIBUSB)
            LibUsbUsbDeviceFactory.Register(Logger, Tracer);
#else
            WindowsUsbDeviceFactory.Register(Logger, Tracer);
            WindowsHidDeviceFactory.Register(Logger, Tracer);
#endif
            Devices = new ObservableCollection<UsbDevice>();
            UpdateDeviceList();
        }
        public void UpdateDeviceList(int? vid = null, int? pid = null)
        {
            var DeviceListLocal = DeviceList.Local.GetHidDevices(vid, pid);
            foreach (var dev in DeviceListLocal)
            {
                try
                {
                    if (dev.GetManufacturer() == "0x0h")
                    {
                        Devices.Add(new UsbDevice(dev));
                    }
                }
                catch (Exception)
                {
                }
            }
        }
        public void Connect(ref UsbDevice device)
        {
            device.OpenDevice();
        }
    }
}
