#include <REGX52.H>
#include "OneWire.h"
#define DS18B20_Skip_ROM			0xCC
#define DS18B20_ConvertTemperature  0x44
#define DS18B20_ReadScratchpad  	0xBE
/**
* @brief 发送温度转换的命令的数据帧
* @param  无
* @retval 无
* @interpretation  描述
*/
void DS18B20_ConvertT(void)
{
	OneWire_Init();
	OneWire_SendByte(DS18B20_Skip_ROM); // 发送跳过ROM指令
	OneWire_SendByte(DS18B20_ConvertTemperature); // 发送温度转换指令
}
/**
* @brief 接收DS18B02传回的数据
* @param  无
* @retval 无
* @interpretation  描述
*/
float DS18B20_ReadT(void)
{
	unsigned char T_LSB, T_MSB; // 接收从DS18B20中返回的温度
	int temp; // 中间变量
	float Temperature; // 最终输出的温度，有符号的浮点数
	OneWire_Init();
	OneWire_SendByte(DS18B20_Skip_ROM); // 发送跳过ROM指令
	OneWire_SendByte(DS18B20_ReadScratchpad); // 发送读暂存器指令
	T_LSB = OneWire_ReadBtye(); // 先读最低有效数字
	T_MSB = OneWire_ReadBtye();
	temp = (T_MSB << 8) | T_LSB;
	Temperature = temp / 16.0;
	return Temperature;
}