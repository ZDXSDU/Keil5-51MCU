#include <REGX52.H>
#include "Delay.h"
#include "MatrixLED.h"
unsigned char Animation[] = {
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x81,0x83,0x85,0x89,0x91,0xA1,0xC1,0x81,
	0xFF,0x81,0x81,0x81,0x81,0x81,0x42,0x3C,
	0x81,0x42,0x24,0x18,0x18,0x24,0x42,0x81,
	0x61,0x91,0x91,0x91,0x91,0x91,0x92,0x4C,
	0xFF,0x81,0x81,0x81,0x81,0x81,0x42,0x3C,
	0xFC,0x02,0x01,0x01,0x01,0x01,0x02,0xFC,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
};
void main()
{
	// i:      当前屏幕中的每一列的字模
	// offset: 屏幕的偏移量，即当前是第几屏幕
	// count:  计次。即当前屏幕循环多少次以后开始显示下一屏
	unsigned char i, offset = 0, count = 0;	
	MatrixLED_Init();
	while(1)
	{
		for(i = 0; i < 8; i++)
		{
			MatrixLEDShowColumn(i, Animation[i + offset]);
		}
		count++;
		if(count > 10)
		{
			count = 0;
			offset+=8;
			if(offset > 8 * 8 - 8) // 40是
				offset = 0;			
		}
	}
}