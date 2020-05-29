using System;
using System.Collections.Concurrent;
using System.Linq;
using System.Threading.Tasks;

namespace zeroxzeroh.libusbTransport
{
    public class UsbDevice : IDisposable
    {
        public string Name { get; private set; }
        public string Manufacturer { get; private set; }
        public string SerialNumber { get; private set; }
        private readonly HidDevice device;
        private HidStream stream;
        public ConcurrentQueue<byte[]> TxQueue = new ConcurrentQueue<byte[]>();
        public ConcurrentQueue<byte[]> RxQueue = new ConcurrentQueue<byte[]>();
        public UsbDevice()
        {
            device = DeviceList.Local.GetHidDevices(0x0483, 0x5750).FirstOrDefault();
            if (device == null)
            {
                throw new Exception("Could not find a default device");
            }
            GetInfo();
        }
        public UsbDevice(HidDevice _device)
        {
            device = _device;
            GetInfo();
        }
        private void GetInfo()
        {
            try
            {
                Name = device.GetFriendlyName();
            }
            catch (Exception)
            {
                Name = "";
            }
            try
            {
                Manufacturer = device.GetManufacturer();
            }
            catch (Exception)
            {
                Manufacturer = "";
            }
            try
            {
                SerialNumber = device.GetSerialNumber();
            }
            catch (Exception)
            {
                SerialNumber = "";
            }
        }
        public bool OpenDevice()
        {
            return device.TryOpen(out stream);
            //if (device.TryOpen(out stream))
            //{
            //    //Task.Factory.StartNew(() => TxUSBAsync());
            //    //Task.Factory.StartNew(() => RxUSBAsync());
            //}
        }
        public void TxUsb(byte[] buff)
        {

            var reportDescriptor = device.GetReportDescriptor();
            var inputReceiver = reportDescriptor.();
            var inputReceiver = reportDescriptor.CreateHidDeviceInputReceiver();
            inputReceiver.


            byte[] BytesToSend = new byte[5];
            Array.Copy(buff, 0, BytesToSend, 1, buff.Length);
            BytesToSend[0] = 0; 
            stream.Write(BytesToSend, 0, 5); 
        }
        public async Task TxUSBAsync()
        {
            while (true)
            {
                if (TxQueue.TryDequeue(out byte[] retValue))
                {
                    await stream.WriteAsync(retValue);
                }
            }
        }
        public async Task RxUSBAsync()
        {
            while (true)
            {
                byte[] buff = new byte[device.GetMaxInputReportLength()];
                await stream.ReadAsync(buff);
                RxQueue.Enqueue(buff);
            }
        }
        public void Dispose()
        {
            stream.Dispose();
        }
    }
}
