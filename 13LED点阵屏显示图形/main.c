#include <REGX52.H>
#define MATRIX_LED_PORT P0
sbit RCK = P3^5; // 74HC595的RCLK引脚(寄存器时钟，上升沿锁存)
sbit SCK = P3^6; // 74HC595的SRCLK引脚(串行时钟，上升沿移位)
sbit SER = P3^4; // 74HC595的SER引脚(串行数据)
void _74HC595_WriteByte(unsigned char byte);
void MatrixLEDShowColumn(unsigned char column, da);
void Delay(unsigned int xms);
void main()
{
	RCK = 0;
	SCK = 0;
	while(1)
	{
		MatrixLEDShowColumn(0,0x00);
		MatrixLEDShowColumn(1,0x80);
		MatrixLEDShowColumn(2,0x88);
		MatrixLEDShowColumn(3,0x84);
		MatrixLEDShowColumn(4,0xFE);
		MatrixLEDShowColumn(5,0x80);
		MatrixLEDShowColumn(6,0x80);
		MatrixLEDShowColumn(7,0x80);
	}
}
/**
* @brief 为74HC595写入数据(8位并锁存)
* @param byte 要写入的字节数据（8位，高位在上）
* @retval 无
*/
void _74HC595_WriteByte(unsigned char byte)
{
	unsigned char i;
	for(i = 0; i < 8; i++) // 循环8次，拿出每一位的值给SER
	{
		SER = byte & (0x80 >> i);
		SCK = 1;
		SCK = 0;
	}
	RCK = 1;
	RCK = 0;
}
/**
* @brief 点阵屏按列显示对应的数据
* @param column 第几列（1位，范围0~7）
* @param data 要显示的数据（8位）
* @retval 无
*/
void MatrixLEDShowColumn(unsigned char column, da)
{
	_74HC595_WriteByte(da);
	MATRIX_LED_PORT = ~ (0x80 >> column);
	Delay(1);
	MATRIX_LED_PORT = 0xFF;
}
/**
* @brief 延时
* @param xms 毫秒
* @retval 无
*/
void Delay(unsigned int xms)
{
	unsigned char i, j;
	while(xms--)
	{
		i = 2;
		j = 239;
		do
		{
			while (--j);
		} while (--i);
	}
}