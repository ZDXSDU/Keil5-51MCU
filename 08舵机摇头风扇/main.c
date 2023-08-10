// _nop_()延时一个机器周期
#include <reg52.h>

#include <intrins.h>
#include "Delay.h"
//#include "LCD1602.h"
sbit PWM = P3^7;  //设定PWM输出的I/O端口
sbit FAN = P3^1;  //K1开启风扇
//sbit HED = P3^2;  //K2开启摇头
sbit FAN_L = P3^6; //风扇低电平
unsigned char count = 0;
unsigned char timer1 ;
//unsigned int IsFanRun = 0;//是否开风扇
//unsigned int IsRouter = 0;//是否摇头
/*
对于180°舵机
t = 0.5ms——————-舵机会转动 0 ° 
t = 1.0ms——————-舵机会转动 45°
t = 1.5ms——————-舵机会转动 90°
t = 2.0ms——————-舵机会转动 135°
t = 2.5ms——————-舵机会转动180
*/ 
/*延时程序*/
void delay1s(void)   //误差 0us
{
    unsigned char a,b,c;
    for(c=167;c>0;c--)
        for(b=171;b>0;b--)
            for(a=16;a>0;a--);
    _nop_();  //if Keil,require use intrins.h
}
 
/*定时器T0初始化*/
void Timer0_Init()           
{
    TMOD &= 0x00;
    TMOD |= 0x01; //定时器T0设置成方式1
 
    TH0 = 0xff;   //定时常数 0.1ms 晶振为11.0592MHz
    TL0 = 0xa4;
 
    ET0 = 1;      
    TR0 = 1; 
	EA=1; 
}
	
/*T0中断初始化*/
void Time0_Init() interrupt 1 
{
	TR0 = 0; 
	TH0 = 0xff; // 0.1ms
	TL0 = 0xa4;
	
	if(count <= timer1) //5==0° 15==90°
	{ 
		PWM = 1; 
	}
	else 
	{ 
		PWM = 0; 
	}
	count++;
	if (count >= 200) //T = 20ms清零
	{ 
		count = 0; 
	}
	TR0 = 1; //开启T0
}
void main()
{
	Timer0_Init();
	//LCD_Init();
	
	
	while(1)
	{
//		if(IsRouter==1)
//		{
//			//LCD_ShowString(2,1,"shake : ON");
			timer1 =5;//舵机恢复到0°的位置
			count=0;//让定时器重新计数
			delay1s();
			timer1 =15;//舵机旋转90°
			count=0;
			delay1s();
//		}
//		else
//		{
//			//LCD_ShowString(1,1,"shake : OFF");
//		}
//		if(IsFanRun==1)
//		{
//			FAN_L=0;
//			//LCD_ShowString(2,1,"fan : ON");
//		}
//		else
//		{
//			FAN_L=1;
//			//LCD_ShowString(2,1,"fan : OFF");
//		}
//		if(HED==0)
//		{
//			Delay(20);
//			while(HED==0);
//			Delay(20);
//			IsRouter = 1;
//		}
//		if(FAN==0)
//		{
//			Delay(20);
//			while(FAN==0);
//			Delay(20);
//			IsFanRun = 1;
//		}
		if(FAN==0)
		{
			P2=0;
//			Delay(20);
//			while(FAN==0);
//			Delay(20);
//			FAN_L=~FAN_L;
		}

	}
}
