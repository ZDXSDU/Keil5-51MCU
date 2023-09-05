#include <REGX52.H>
unsigned char KeyNumber; // 用于定时器扫描独立按键使用
unsigned char Key_GetState(void);
/**
* @brief  获取独立按键键码
* @param  无
* @retval 按下按键的键码，范围：0~4，无按键按下时返回值为0
*/
unsigned char Key(void)
{
	unsigned char Temp = 0; // 由于在Key_Loop()内赋值的KeyNumber并不会自动清零，所以这里需要一个临时变量来接收KeyNumber的值，并把KeyNumber清零后返回临时变量，由于临时变量既不是静态变量又不是全局变量，他会在这个函数运行结束后回收
	Temp = KeyNumber;
	KeyNumber = 0;
	return Temp;	
}
/**
* @brief 循环调用  用于定时器中断扫描独立按键 
* @param  无
* @retval 无
* @interpretation  在定时器Timer0中每隔一段时间（20MS）调用一下这个函数。如果使用定时器中断来扫描案件，则应配合下方的Key_GetState函数一起食用
*/
void Key_Loop(void)
{
	// 这个地方会在main.c中的定时器Timer0中断函数内每隔20ms调用一次，20ms刚好把按键的抖动给消除掉
	static unsigned char NowState, LastState; // 定义两个标识位用来存储当前的状态和之前的状态
	LastState = NowState; // 运行的时候用LastState接收NowState的至，以给NowState可以接受实时扫描到的值
	NowState = Key_GetState(); // 当前的状态等于现在读取出来的状态
	if(NowState == 1 && LastState == 0) // 上次的标识位是按键1，这次的标识位是0，证明已经松手了按键1
		KeyNumber = 1;
	if(NowState == 2 && LastState == 0) // 上次的标识位是按键2，这次的标识位是0，证明已经松手了按键2
		KeyNumber = 2;
	if(NowState == 3 && LastState == 0) // 上次的标识位是按键3，这次的标识位是0，证明已经松手了按键3
		KeyNumber = 3;
	if(NowState == 4 && LastState == 0) // 上次的标识位是按键4，这次的标识位是0，证明已经松手了按键4
		KeyNumber = 4;
}
/**
* @brief 获取此刻的按键状态
* @param  无
* @retval 无
* @interpretation  描述
*/
unsigned char Key_GetState(void)
{
	unsigned char KeyNumber=0;	
	if(P3_1==0){KeyNumber=1;}
	if(P3_0==0){KeyNumber=2;}
	if(P3_2==0){KeyNumber=3;}
	if(P3_3==0){KeyNumber=4;}	
	return KeyNumber;
}