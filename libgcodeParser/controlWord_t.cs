using System.Runtime.InteropServices;

namespace libgcodeParser
{
    public partial class GcodeParser
    {
        [StructLayout(LayoutKind.Sequential)]
        private struct controlWord_t
        {
            public OpcodeEnum opcode;
            public uint execTime;
        }
    }
}
