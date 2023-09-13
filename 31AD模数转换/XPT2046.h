#ifndef __XPT2046_H__
#define __XPT2046_H__

#define XPT2046_XP_8 0x9C
#define XPT2046_YP_8 0xDC
#define XPT2046_VBAT_8 0xAC
#define XPT2046_AUX_8 0xEC

#define XPT2046_XP_12 0x8C
#define XPT2046_YP_12 0xDC
#define XPT2046_VBAT_12 0xAC
#define XPT2046_AUX_12 0xEC

unsigned int XPT2046_Read(unsigned char Command);
#endif