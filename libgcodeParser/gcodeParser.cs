using Gcode.Utils.Entity;
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
                    float speed = 100f;
                    uint steps = 123;
                    FloatIntCmd_t cmdTX = new FloatIntCmd_t
                    {
                        opcode = OpcodeEnum.x,
                        subcode = 0,
                        floatVal = speed,
                        uintVal = steps
                    };
                    listOfTXbuffs.Add(PackIntoByteArr(cmdTX));
                }
            }
            return listOfTXbuffs;
        }

        private static byte[] PackIntoByteArr(FloatIntCmd_t cmdTX)
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