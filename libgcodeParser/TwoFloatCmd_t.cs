using System.Runtime.InteropServices;

namespace libgcodeParser
{
    public partial class GcodeParser
    {
        [StructLayout(LayoutKind.Sequential)]
        private struct TwoFloatCmd_t
        {
            public OpcodeEnum opcode;
            public byte subcode;
            public float floatValue1;
            public float floatValue2;
            public byte notes1;
            public byte notes2;
            public byte notes3;
        }
    }
}
