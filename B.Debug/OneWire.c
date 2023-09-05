#include <REGX52.H>
#include <INTRINS.H>
sbit OneWire_DQ = P3^7;
/**
* @brief 1-Wire 总线初始化函数
* @param  无
* @retval unsigned char ACKBit 从机是否响应，如果响应则返回0；如果未响应则返回1
* @interpretation  描述
*/
unsigned char OneWire_Init(void)
{
	unsigned char i;
	unsigned char ACKBit;
	// 主机拉低DQ总线500us	
	OneWire_DQ = 1;
	OneWire_DQ = 0;	
	i = 230;	while (--i); // 11.0592MHz 500us
	// 主机释放DQ总线
	OneWire_DQ = 1;
	// 等待70us后，判断从机响应
	_nop_();	i = 31;		while (--i); // 11.0592MHz 70us
	ACKBit = OneWire_DQ;
	// 等待500us，走完初始化的时间片
	i = 230;	while (--i); // 11.0592MHz 500us
	return ACKBit;
}
/**
* @brief 发送一个数据位
* @param  unsigned char Bit 要发送的数据位
* @retval 无
* @interpretation  描述
*/
void OneWire_SendBit(unsigned char Bit)
{
	unsigned char i;
	OneWire_DQ = 0;
	i = 4;	while (--i); // 11.0592MHz 10us
	OneWire_DQ = Bit;
	i = 22;	while (--i); // 11.0592MHz 50us
	OneWire_DQ = 1;
}
/**
* @brief 接收一个数据位
* @param  无
* @retval unsigned char Bit 要发送的数据位
* @interpretation  描述
*/
unsigned char OneWire_ReadBit(void)
{
	unsigned char AckBit, i;
	OneWire_DQ = 0;
	i = 2;	while (--i); // 11.0592MHz 5us
	OneWire_DQ = 1;
	i = 2;	while (--i); // 11.0592MHz 5us
	AckBit = OneWire_DQ;
	i = 22;	while (--i); // 11.0592MHz 50us
	return AckBit;
}
/**
* @brief 发送一个字节
* @param  要发送的字节
* @retval 无
* @interpretation  描述
*/
void OneWire_SendByte(unsigned char byte)
{
	unsigned char i;
	for(i = 0; i < 8; i++)
	{
		OneWire_SendBit(byte & (0x01 << i)); // 调用发送一位八次，取出字节byte，低位在前
	}
}
/**
* @brief 接收一个字节
* @param  无
* @retval 接收到的字节数
* @interpretation  描述
*/
unsigned char OneWire_ReadBtye(void)
{
	unsigned char ResByte = 0x00, i;
	for(i = 0; i < 8; i++)
	{
		if(OneWire_ReadBit())
			ResByte |= (0x01 << i);
	}
	return ResByte;
}