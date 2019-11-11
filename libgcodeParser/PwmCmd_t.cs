using System.Runtime.InteropServices;

namespace libgcodeParser
{
    public static partial class GcodeParser
    {
        [StructLayout(LayoutKind.Sequential)]
        private struct PwmCmd_t
        {
            public controlWord_t cw;
            public byte pwmCh;
            public ushort pwmVal;
        }
    }
}