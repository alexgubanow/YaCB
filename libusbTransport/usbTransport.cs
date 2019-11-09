using System.Collections.Concurrent;
using System.Diagnostics;
using System.Threading;

namespace libusbTransport
{
    public class UsbTransport
    {

        ConcurrentQueue<byte[]> Cmds;
        private bool TxAllowed;
        private int cmdTimeout = 100;

        public void TxUSB()
        {
            while (TxAllowed)
            {
                Stopwatch sw = new Stopwatch();
                sw.Start();
                while (Cmds.IsEmpty && sw.ElapsedMilliseconds < cmdTimeout) { }
                if (Cmds.TryDequeue(out byte[] retValue))
                {
                    SendOverUSB(retValue);
                }
            }
        }
        private void SendOverUSB(byte[] cmd)
        { }
    }
}
