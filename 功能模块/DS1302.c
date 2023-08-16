// Header: 驱动DS1302数字时钟的函数
// File Name: DS1302.c
// Author: ZDXSDU
// Date: Aug.15,2023
#include <REGX52.H>
sbit DS1302_SCLK = P3^6; // DS1302芯片的串行时钟引脚
sbit DS1302_IO = P3^4; // DS1302芯片的串行数据引脚
sbit DS1302_CE = P3^5; // DS1302芯片的芯片使能引脚（高电平有效）
/**
* @brief DS1302初始化
* @param  无
* @retval 无
* @interpretation 由于MCU上电时I/O口均为高电平，需要给DS1302的时钟和使能引脚低电平
*/
void DS1302_Init(void)
{
	DS1302_CE = 0;
	DS1302_SCLK = 0;
}
/**
* @brief 向DS1302写入数据
* @param Command：命令字
* @param Data：写入的数据字节
* @retval 无
* @interpretation 描述
*/
void DS1302_WriteByte(unsigned char Command, Data)
{
	unsigned char i;
	DS1302_CE = 1; // 芯片使能引脚给高电平使其有效	
	for(i = 0; i < 8; i++)
	{
		DS1302_IO = Command & (0x01 << i); // 取出命令字的第i位
		DS1302_SCLK = 1; // 上升沿将数据写入DS1302
		DS1302_SCLK = 0; // 恢复串行时钟置0
	}
	for(i = 0; i < 8; i++)
	{
		DS1302_IO = Data & (0x01 << i); // 取出Data字节的第i位
		DS1302_SCLK = 1; // 上升沿将数据写入DS1302
		DS1302_SCLK = 0; // 恢复串行时钟置0
	}
	DS1302_CE = 0; // 关闭芯片使能
}
/**
* @brief 向DS1302读取数据
* @param Command：命令字
* @retval [char]: DS1302返回的数据
* @interpretation  描述
*/
unsigned char DS1302_ReadByte(unsigned char Command)
{
	unsigned char i, Data = 0x00;
	DS1302_CE = 1; // 芯片使能引脚给高电平使其有效
	for(i = 0; i < 8; i++)
	{
		DS1302_IO = Command & (0x01 << i); // 取出命令字的第i位
		// 由于DS1302的写入和读取的时序不一样，这里需要先给0再给1
		DS1302_SCLK = 0; // 恢复串行时钟置0
		DS1302_SCLK = 1; // 上升沿将数据写入DS1302
	}
	for(i = 0; i < 8; i++)
	{
		// 这里在取数据的时候又将时序反了过来，原因是如果先0后1会造成多给了一个脉冲周期
		DS1302_SCLK = 1; // 恢复串行时钟置1
		DS1302_SCLK = 0; // 下降沿读取DS1302的数据		
		if(DS1302_IO)
			Data |= (0x01 << i); // 如果DS1302的返回值是1，那么就将接收变量Data对应位置也变成1
	}
	DS1302_CE = 0; // 关闭芯片使能
	DS1302_IO = 0; // 将串行数据口清零，防止读出的不对
	return Data;
}