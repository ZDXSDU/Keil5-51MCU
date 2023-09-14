#include <STC89C5xRC.H>
#include "Timer0.h"
#include "Int0.h"
unsigned int IR_Time; // 计时时间
unsigned char IR_Status; // 红外的状态机；【0空闲，1接收到start信号，2接收数据并解码】
unsigned char IR_Data[4]; // 使用char类型的4长度数组来存储红外接收头接收到的数据，这里不适用long类型的原因是因为<<和>>只能操作16位以内的数据，对于32位的long类型操作左移右移会出现问题
unsigned char IR_pData; // 定义当前读到了第几位，如果读满32位，就认为接受结束
unsigned char IR_DataFlag; // 数据接收完毕标识位
unsigned char IR_RepeatFlag; // 重发标识
unsigned char IR_Address; // 红外接收到的地址码
unsigned char IR_Command; // 红外接收到的命令字
void IR_Init(void)
{
	Timer0_Init();
	Int0_Init();
}
void Int0_Rountine(void)  interrupt 0
{
	switch(IR_Status)
	{
		case 0: 
		{
			Timer0_SetCounter(0);
			Timer0_Run(1);
			IR_Status = 1;
			break;
		}
		case 1:
		{
			IR_Time = Timer0_GetCounter();
			Timer0_SetCounter(0);
			if(IR_Time >= (9000 + 4500) - 500 && IR_Time <= (9000 + 4500) + 500)
			{ // Start 信号
				IR_Status = 2;
			}
			else if(IR_Time >= (9000 + 2250) - 500 && IR_Time <= (9000 + 2250) + 500)
			{ // Repeat 信号
				IR_RepeatFlag = 1;
				Timer0_Run(0);
				IR_Status = 0;
			}
			else
			{
				IR_Status = 1;
			}
			break;
		}
		case 2:
		{
			IR_Time = Timer0_GetCounter();
			Timer0_SetCounter(0);
			if(IR_Time >= (560 + 560) - 500 && IR_Time <= (560 + 560) + 500)
			{ // Logical"0"
				IR_Data[IR_pData / 8] &= ~(0x01 << (IR_pData % 8));
				IR_pData++;
			}
			else if(IR_Time >= (560 + 1690) -500 && IR_Time <= (560 + 1690) + 500)
			{ // Logical"1"
				IR_Data[IR_pData / 8] |= 0x01 << (IR_pData % 8);
				IR_pData++;
			}
			else
			{ // Error
				IR_pData = 0;
				IR_Status = 1;
			}
			if(IR_pData >= 32)
			{ // 
				IR_pData = 0;
				if((IR_Data[0] == ~IR_Data[1]) &&(IR_Data[2] == ~IR_Data[3]))
				{					
					IR_Address = IR_Data[0];
					IR_Command = IR_Data[2];
					IR_DataFlag = 1;
				}
				Timer0_Run(0);
				IR_Status = 0;
			}
		}
		default:
		{ 
			break;
		}
	}
}
unsigned char IR_GetDataFalg(void)
{
	if(IR_DataFlag)
	{
		IR_DataFlag = 0;
		return 1;
	}
	else
	{
		return 0;
	}
}
unsigned char IR_GetRepeatFlag(void)
{
	if(IR_RepeatFlag)
	{
		IR_RepeatFlag = 0;
		return 1;
	}
	else
	{
		return 0;
	}
}
unsigned char IR_GetAddress(void)
{
	return IR_Address;
}
unsigned char IR_GetCommand(void)
{
	return IR_Command;
}
/*
外部中断Int0设置为下降沿触发，如果他检测到了下降沿并进入了中断函数，就开启计时器同时将红外状态机的状态改为1，
下次下降沿触发时，拿到计时器的值，并让计时器重新开始计时，同时判断计时器的值是不是在start时间上下500us的波动范围内，如果是，我们就认为接收机已经接收到了start信号，并将红外状态机的状态修改为2；如果时间是在Repeat的时间上下500us内，则认为接收到了重发信号 同时状态机修改为0，重发状态标识置为1,停止计时器；如果都不是，那就认为接收头接收到了错误的数据，将接收标识位置为1，重新接收
*/