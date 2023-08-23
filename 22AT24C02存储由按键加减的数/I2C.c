/**
 * @Author: ZDXSDU [ZDXSDU@qq.com]
 * @Date: Aug. 19, 2023 11:45:36
 * @LastEditors: ZDXSDU [ZDXSDU@qq.com]
 * @LastEditTime: Aug. 19, 2023 14:39:02
 * @FilePath: ./I2C.c
 * @Description: 定义了I2C总线的6个时序
 */
#include <REGX52.H>
sbit I2C_SCL = P2^1;
sbit I2C_SDA = P2^0;
/**
* @brief I2C时序-起始条件
* @param  无
* @retval 无
* @interpretation  SCL高电平期间，SDA从高电平切换到低电平
*/
void I2C_Start(void)
{
	// 这里先给SCL和SDA高电平是为了防止他们有在低电平的情况
	I2C_SDA = 1;
	I2C_SCL = 1;
	I2C_SDA = 0;
	I2C_SCL = 0;
}
/**
* @brief I2C时序-终止条件
* @param  无
* @retval 无
* @interpretation  SCL高电平期间，SDA从低电平切换到高电平
*/
void I2C_Stop(void)
{
	I2C_SDA = 0;
	I2C_SCL = 1;
	I2C_SDA = 1;
}
/**
* @brief I2C时序-发送一个字节
* @param  无
* @retval 无
* @interpretation  SCL低电平期间，主机将数据位依次放到SDA上（高位在前），然后拉高SCL，从机将在SCL高电平期间读取数据位
*/
void I2C_SendByte(unsigned char byte)
{
	unsigned char i;
	for(i = 0; i < 8; i++)
	{
		I2C_SDA = byte & (0x80 >> i); // 依次取出byte字节中的每一位数据
		I2C_SCL = 1;
		I2C_SCL = 0;
	}
}
/**
* @brief  I2C时序-接收一个字节
* @param  无
* @retval unsigned char 接收到的一个字节数据
* @interpretation  SCL低电平期间，从机将数据位依次放到SDA上（高位在前），然后拉高SCL，主机将在SCL高电平期间读取数据位
*/
unsigned char I2C_ReceiveByte(void)
{
	unsigned char i, byte = 0x00;
	I2C_SDA = 1; // 释放SDA
	for(i = 0; i < 8; i++)
	{
		I2C_SCL = 1;
		if(I2C_SDA) byte |= (0x80 >> i);
		I2C_SCL = 0;
	}
	return byte;
}

/**
* @brief  I2C时序-发送应答
* @param  AckBit 应答位，0为应答，1为非应答
* @retval 无
* @interpretation 在接受完一个字节后，主机在下一时钟发送一位数据；bit类似于bool，只能存储一位
*/
void I2C_SendAck(bit AckBit)
{
	I2C_SDA = AckBit;
	I2C_SCL = 1;
	I2C_SCL = 0;
}

/**
* @brief  I2C时序-接收应答
* @param  无
* @retval bit 接收到的应答位，0为应答，1为非应答
* @interpretation 在接受完一个字节后，主机在下一时钟发送一位数据；bit类似于bool，只能存储一位
*/
bit I2C_ReceiveAck(void)
{
	bit AckBit;
	I2C_SDA = 1; // 释放SDA
	I2C_SCL = 1;
	AckBit = I2C_SDA;
	I2C_SCL = 0;
	return AckBit;
}