
#ifndef _SYS_IOCTL_SPECTRUM_H
#define _SYS_IOCTL_SPECTRUM_H

#include <stdint.h>

// IOCTL FOR ZX_01_INPUT_KBD_INKEY

#define IOCTL_ITERM_GET_DELAY          0x1081
#define IOCTL_ITERM_SET_DELAY          0x1001

// IOCTL FOR ZX_01_INPUT_KBD_LASTK

#define IOCTL_ITERM_LASTK              0x1101

// IOCTL FOR ZX_01_OUTPUT_CHAR_32
// IOCTL FOR ZX_01_OUTPUT_CHAR_64
// IOCTL FOR ZX_01_OUTPUT_CHAR_32_TTY_Z88DK
// IOCTL FOR ZX_01_OUTPUT_CHAR_64_TTY_Z88DK

#define IOCTL_OTERM_FCOLOR             0x1002
#define IOCTL_OTERM_FMASK              0x1102
#define IOCTL_OTERM_BCOLOR             0x1202

#endif
