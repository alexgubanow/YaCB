using Gcode.Entity;
using System.Collections.Generic;
using System.Runtime.InteropServices;

namespace libgcodeParser
{
    public static partial class GcodeParser
    {
        public static List<byte[]> ParseG(GcodeCommandFrame gcodeFrame)
        {
            List<byte[]> listOfTXbuffs = new List<byte[]>();
            if (gcodeFrame.G.HasValue)
            {
                if (gcodeFrame.X.HasValue)
                {
                    //some how got speed and steps from planner
                    float v = 100f;
                    uint x = 123;
                    MovCmd_t cmdTX = new MovCmd_t
                    {
                        cw = new controlWord_t() { opcode = OpcodeEnum.g },
                        drv1 = new axes_t() { freq = v, steps = x }
                    };
                    listOfTXbuffs.Add(PackIntoByteArr(cmdTX));
                }
            }
            return listOfTXbuffs;
        }
        private static byte[] PackIntoByteArr(MovCmd_t cmdTX)
        {
            int sizeOfBuffer = Marshal.SizeOf(cmdTX); //suppouse to be 16bytes
            byte[] buffer = new byte[sizeOfBuffer];
            GCHandle h = GCHandle.Alloc(cmdTX, GCHandleType.Pinned);
            Marshal.Copy(h.AddrOfPinnedObject(), buffer, 0, sizeOfBuffer);
            h.Free();
            return buffer;
        }
    }
}