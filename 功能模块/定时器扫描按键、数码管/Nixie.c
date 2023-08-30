#include <REGX52.H>
unsigned char NixieTable[12] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F, 0x00, 0x40}; // 数码管段码表，分别对应0~9\空\短横线
unsigned char NixieBuf[9] = {0, 10, 10, 10, 10, 10, 10, 10, 10}; // 显示缓冲区，NixieBuf[1]~[8]分别对应8个数码管中要显示的数字，10对应NixieTable[10]=>啥都不显示
/**
* @brief 数码管扫描
* @param Location 在第几个数码管上显示
* @param Number 显示什么内容
* @retval 无
* @interpretation  描述
*/
void Nixie_Scan(unsigned char Location, Number)
{
	P0 = 0x00; // 清空段码
	switch(Location)
	{
		case 1: P2_4=1; P2_3=1; P2_2=1; break;
		case 2: P2_4=1; P2_3=1; P2_2=0; break;
		case 3: P2_4=1; P2_3=0; P2_2=1; break;
		case 4: P2_4=1; P2_3=0; P2_2=0; break;
		case 5: P2_4=0; P2_3=1; P2_2=1; break;
		case 6: P2_4=0; P2_3=1; P2_2=0; break;
		case 7: P2_4=0; P2_3=0; P2_2=1; break;
		case 8: P2_4=0; P2_3=0; P2_2=0; break;
	}
	P0 = NixieTable[Number]; // 段码输出		
}
/**
* @brief 可供外界调用的修改显示缓冲区的函数
* @param Location 在第几个数码管上显示
* @param Number 显示什么内容
* @retval 无
* @interpretation  描述
*/
void Nixie_SetBuf(unsigned char Location, Number)
{
	NixieBuf[Location] = Number;
}
/**
* @brief 供Timer0定时器interrupt1中断函数内调用的方法，每两毫秒调用一次
* @param  无
* @retval 无
* @interpretation  每次执行，都将显示缓冲区的数字显示一位到数码管中
*/
void Nixie_Loop(void)
{
	static unsigned char i = 1;
	Nixie_Scan(i, NixieBuf[i]);
	i++;
	if(i >= 9) i = 1; // 由定时器控制，每隔一段时间循环以实现扫描
}