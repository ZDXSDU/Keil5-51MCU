#ifndef __IR_H__
#define __IR_H__
void IR_Init(void);
unsigned char IR_GetDataFalg(void);
unsigned char IR_GetRepeatFlag(void);
unsigned char IR_GetAddress(void);
unsigned char IR_GetCommand(void);
// 以下是51A2开发板遥控器各按键的键码
#define IRRC_POWER       0x45     // 电源键
#define IRRC_MODE        0x45     // Mode键
#define IRRC_MUTE        0x47     // 静音键
#define IRRC_PAUSED      0x44     // 播放/暂停键
#define IRRC_LAST        0x40     // 上一曲键
#define IRRC_NEXT        0x43     // 下一曲键
#define IRRC_EQ          0x07     // EQ键
#define IRRC_VOL_MINISH  0x15     // 音量减小键
#define IRRC_VOL_ENLARGE 0x09     // 音量增大键
#define IRRC_0           0x16     // 0键
#define IRRC_RPT         0x19     // RPT键
#define IRRC_USD         0x0D     // USD键
#define IRRC_1           0x0C     // 1键
#define IRRC_2           0x18     // 2键
#define IRRC_3           0x5E     // 3键
#define IRRC_4           0x08     // 4键
#define IRRC_5           0x1C     // 5键
#define IRRC_6           0x5A     // 6键
#define IRRC_7           0x42     // 7键
#define IRRC_8           0x52     // 8键
#define IRRC_9           0x4A     // 9键
#endif