#include <REGX52.H>
#include "Key.h" // 独立按键
#include "Delay.h" // 延时
#include "Nixie.h" // 数码管
#include "Timer0.h" // 定时器
#include "Buzzer.h" // 500Hz固定频率按键音
unsigned char KeyNum;
void main()
{
	Nixie(1, 0);	
	while(1)
	{
		KeyNum = Key();
		if(KeyNum)
		{			
			// 这个地方是静态显示的，对Nixie函数进行了修改，注释掉了延时1毫秒并清零的代码	
			Nixie(1, KeyNum);
//			Buzzer500Hz(500);
			Buzzer1000Hz(500);
		}
	}
}