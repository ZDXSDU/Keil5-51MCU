/**
 * @Author: ZDXSDU [ZDXSDU@qq.com]
 * @Date: Aug. 19, 2023 14:49:25
 * @LastEditors: ZDXSDU [ZDXSDU@qq.com]
 * @LastEditTime: 
 * @FilePath: ./AT24C02.c
 * @Description: 定义AT24C02的两个数据帧
 */
#include <REGX52.H>
#include "I2C.h"
#define AT24C02_SLAVE_ADDRESS_W 0xA0 // 定义AT24C02的写地址
#define AT24C02_SLAVE_ADDRESS_R 0xA1 // 定义AT24C02的读地址
/**
* @brief AT24C02数据帧-字节写
* @param  WordAddress 写入的地址，Data 写入的数据
* @retval 无
* @interpretation  在WordAddress处写入Data数据
*/
void AT24C01_WriteByte(unsigned char WordAddress, Data)
{
	// 正常情况下定义一个变量用来接收AT24C02的应答，从而判断其是否收到了主机发送的数据
	I2C_Start(); // 起始条件
	I2C_SendByte(AT24C02_SLAVE_ADDRESS_W); // 发送地址和写指令
	I2C_ReceiveAck(); // 接收AT24C02的应答
	I2C_SendByte(WordAddress); // 向AT24C02发送数据-写入的地址
	I2C_ReceiveAck(); // 接收AT24C02的应答
	I2C_SendByte(Data); // 向AT24C02发送数据-写入的数据
	I2C_ReceiveAck(); // 接收AT24C02的应答
	I2C_Stop(); // 终止条件
}
/**
* @brief AT24C02数据帧-随机读
* @param  unsigned char WordAddress 要读取的地址
* @retval 无
* @interpretation  在WordAddress处写入Data数据
*/
unsigned char AT24C02_ReadByte(unsigned char WordAddress)
{
	unsigned char Data;
	I2C_Start(); // 起始条件
	I2C_SendByte(AT24C02_SLAVE_ADDRESS_W); // 发送地址和写指令
	I2C_ReceiveAck(); // 接收AT24C02的应答
	I2C_SendByte(WordAddress); // 向AT24C02发送数据-要读取的地址
	I2C_ReceiveAck(); // 接收AT24C02的应答
	I2C_Start(); // 起始条件
	I2C_SendByte(AT24C02_SLAVE_ADDRESS_R); // 发送地址和读指令
	I2C_ReceiveAck(); // 接收AT24C02的应答
	Data = I2C_ReceiveByte(); // 接收AT24C02返回的数据
	I2C_SendAck(1); // 向AT24C02发送数据应答
	I2C_Stop(); //终止条件
	return Data;
}