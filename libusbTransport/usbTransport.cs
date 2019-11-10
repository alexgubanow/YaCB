using System.Collections.Concurrent;
using System.Diagnostics;
using System.Threading;

namespace libusbTransport
{
    public class UsbTransport
    {
        private ConcurrentQueue<byte[]> Cmds;
        private int cmdTimeout = 100;

        UsbTransport()
        {
            Cmds = new ConcurrentQueue<byte[]>();
        }

        public void TxUSB()
        {
            Stopwatch sw = new Stopwatch();
            while (true)
            {
                sw.Restart();
                while (Cmds.IsEmpty && sw.ElapsedMilliseconds < cmdTimeout) { }
                if (Cmds.TryDequeue(out byte[] retValue))
                {
                    SendOverUSB(retValue);
                }
            }
        }
        private void SendOverUSB(byte[] cmd)
        {
            Cmds.Enqueue(cmd);
        }
    }
}
