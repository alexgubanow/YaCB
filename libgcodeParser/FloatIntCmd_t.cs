using System.Runtime.InteropServices;

namespace libgcodeParser
{
    public partial class GcodeParser
    {
        [StructLayout(LayoutKind.Sequential)]
        private struct FloatIntCmd_t
        {
            public OpcodeEnum opcode;
            public byte subcode;
            public float floatVal;
            public uint uintVal;
            public byte notes1;
            public byte notes2;
            public byte notes3;
        }
    }
}
