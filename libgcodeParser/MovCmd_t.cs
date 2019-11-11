using System.Runtime.InteropServices;

namespace libgcodeParser
{
    public partial class GcodeParser
    {
        [StructLayout(LayoutKind.Sequential)]
        private struct axes_t
        {
            public float freq;
            public uint steps;
        }
        [StructLayout(LayoutKind.Sequential)]
        private struct MovCmd_t
        {
            public controlWord_t cw;
            public axes_t drv1;
            public axes_t drv2;
            public axes_t drv3;
            public axes_t drv4;
            public axes_t drv5;
            public axes_t drv6;
        }
    }
}
