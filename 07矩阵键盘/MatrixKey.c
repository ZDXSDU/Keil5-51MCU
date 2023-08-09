// Header:
// File Name: 适用于普中开发板的矩阵键盘逐列扫描读取
// Author:
// Date:

#include <REGX52.H>
#include "Delay.h"

unsigned char KeyNum;
/**
  * @brief 矩阵键盘逐行读取按键键码
  * @param  无
  * @retval KeyNum(unsigned char) 被按下按键的键码值
  */
unsigned char GetMatrixKey()
{
	P1=0XFF;
	P1_3=0;
	if(P1_7==0) { Delay(20); while(P1_7==0); Delay(20); KeyNum=1; }
	if(P1_6==0) { Delay(20); while(P1_6==0); Delay(20); KeyNum=5; }
	if(P1_5==0) { Delay(20); while(P1_5==0); Delay(20); KeyNum=9; }
	if(P1_4==0) { Delay(20); while(P1_4==0); Delay(20); KeyNum=13; }
	
	P1=0XFF;
	P1_2=0;
	if(P1_7==0) { Delay(20); while(P1_7==0); Delay(20); KeyNum=2; }
	if(P1_6==0) { Delay(20); while(P1_6==0); Delay(20); KeyNum=6; }
	if(P1_5==0) { Delay(20); while(P1_5==0); Delay(20); KeyNum=10; }
	if(P1_4==0) { Delay(20); while(P1_4==0); Delay(20); KeyNum=14; }
	
	P1=0XFF;
	P1_1=0;
	if(P1_7==0) { Delay(20); while(P1_7==0); Delay(20); KeyNum=3; }
	if(P1_6==0) { Delay(20); while(P1_6==0); Delay(20); KeyNum=7; }
	if(P1_5==0) { Delay(20); while(P1_5==0); Delay(20); KeyNum=11; }
	if(P1_4==0) { Delay(20); while(P1_4==0); Delay(20); KeyNum=15; }
	
	P1=0XFF;
	P1_0=0;
	if(P1_7==0) { Delay(20); while(P1_7==0); Delay(20); KeyNum=4; }
	if(P1_6==0) { Delay(20); while(P1_6==0); Delay(20); KeyNum=8; }
	if(P1_5==0) { Delay(20); while(P1_5==0); Delay(20); KeyNum=12; }
	if(P1_4==0) { Delay(20); while(P1_4==0); Delay(20); KeyNum=16; }
	
	return KeyNum;
}