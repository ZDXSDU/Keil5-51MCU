/*
 * @Author: ZDXSDU [ZDXSDU@qq.com]
 * @Date: Aug. 16, 2023 08:50:17
 * @LastEditors: ZDXSDU [ZDXSDU@qq.com]
 * @LastEditTime: Aug. 17, 2023 14:52:57
 * @FilePath: /main.c
 * @Description: 无分支版
 */
#define IDL_    0x01
#define STOP_   0x02
#define PD_     0x02 
#define GF0_    0x04
#define GF1_    0x08
#define SMOD_   0x80
#define T0_M0_   0x01
#define T0_M1_   0x02
#define T0_CT_   0x04
#define T0_GATE_ 0x08
#define T1_M0_   0x10
#define T1_M1_   0x20
#define T1_CT_   0x40
#define T1_GATE_ 0x80
#define T1_MASK_ 0xF0
#define T0_MASK_ 0x0F
#define DCEN_   0x01    
#define T2OE_   0x02
#define IE0_VECTOR	0 
#define TF0_VECTOR	1
#define IE1_VECTOR	2
#define TF1_VECTOR	3
#define SIO_VECTOR	4
#define TF2_VECTOR	5
#define EX2_VECTOR	5
#define LCD_DataPort P0
#define DS1302_Second_Write 0x80
#define DS1302_Minute_Write 0x82
#define DS1302_Hour_Write 0x84
#define DS1302_Day_Write 0x86
#define DS1302_Month_Write 0x88
#define DS1302_Week_Write 0x8A
#define DS1302_Year_Write 0x8C
#define DS1302_WP 0x8E
sfr P0      = 0x80;
sfr SP      = 0x81;
sfr DPL     = 0x82;
sfr DPH     = 0x83;
sfr PCON    = 0x87;
sfr TCON    = 0x88;
sfr TMOD    = 0x89;
sfr TL0     = 0x8A;
sfr TL1     = 0x8B;
sfr TH0     = 0x8C;
sfr TH1     = 0x8D;
sfr P1      = 0x90;
sfr SCON    = 0x98;
sfr SBUF    = 0x99;
sfr P2      = 0xA0;
sfr IE      = 0xA8;
sfr P3      = 0xB0;
sfr IP      = 0xB8;
sfr T2CON   = 0xC8;
sfr T2MOD   = 0xC9;
sfr RCAP2L  = 0xCA;
sfr RCAP2H  = 0xCB;
sfr TL2     = 0xCC;
sfr TH2     = 0xCD;
sfr PSW     = 0xD0;
sfr ACC     = 0xE0;
sfr B       = 0xF0;
sbit P0_0 = 0x80;
sbit P0_1 = 0x81;
sbit P0_2 = 0x82;
sbit P0_3 = 0x83;
sbit P0_4 = 0x84;
sbit P0_5 = 0x85;
sbit P0_6 = 0x86;
sbit P0_7 = 0x87;
sbit IT0  = 0x88;
sbit IE0  = 0x89;
sbit IT1  = 0x8A;
sbit IE1  = 0x8B;
sbit TR0  = 0x8C;
sbit TF0  = 0x8D;
sbit TR1  = 0x8E;
sbit TF1  = 0x8F;
sbit P1_0 = 0x90;
sbit P1_1 = 0x91;
sbit P1_2 = 0x92;
sbit P1_3 = 0x93;
sbit P1_4 = 0x94;
sbit P1_5 = 0x95;
sbit P1_6 = 0x96;
sbit P1_7 = 0x97;
sbit T2   = 0x90;
sbit T2EX = 0x91;
sbit RI   = 0x98;
sbit TI   = 0x99;
sbit RB8  = 0x9A;
sbit TB8  = 0x9B;
sbit REN  = 0x9C;
sbit SM2  = 0x9D;
sbit SM1  = 0x9E;
sbit SM0  = 0x9F;
sbit P2_0 = 0xA0;
sbit P2_1 = 0xA1;
sbit P2_2 = 0xA2;
sbit P2_3 = 0xA3;
sbit P2_4 = 0xA4;
sbit P2_5 = 0xA5;
sbit P2_6 = 0xA6;
sbit P2_7 = 0xA7;
sbit EX0  = 0xA8;
sbit ET0  = 0xA9;
sbit EX1  = 0xAA;
sbit ET1  = 0xAB;
sbit ES   = 0xAC;
sbit ET2  = 0xAD;
sbit EA   = 0xAF;
sbit P3_0 = 0xB0;
sbit P3_1 = 0xB1;
sbit P3_2 = 0xB2;
sbit P3_3 = 0xB3;
sbit P3_4 = 0xB4;
sbit P3_5 = 0xB5;
sbit P3_6 = 0xB6;
sbit P3_7 = 0xB7;
sbit RXD  = 0xB0;      
sbit TXD  = 0xB1;       
sbit INT0 = 0xB2;       
sbit INT1 = 0xB3;       
sbit T0   = 0xB4;       
sbit T1   = 0xB5;       
sbit WR   = 0xB6;       
sbit RD   = 0xB7;       
sbit PX0  = 0xB8;
sbit PT0  = 0xB9;
sbit PX1  = 0xBA;
sbit PT1  = 0xBB;
sbit PS   = 0xBC;
sbit PT2  = 0xBD;
sbit CP_RL2= 0xC8;      
sbit C_T2 = 0xC9;       
sbit TR2  = 0xCA;       
sbit EXEN2= 0xCB;       
sbit TCLK = 0xCC;       
sbit RCLK = 0xCD;       
sbit EXF2 = 0xCE;       
sbit TF2  = 0xCF;
sbit P    = 0xD0;
sbit F1   = 0xD1;
sbit OV   = 0xD2;
sbit RS0  = 0xD3;
sbit RS1  = 0xD4;
sbit F0   = 0xD5;
sbit AC   = 0xD6;
sbit CY   = 0xD7;
sbit DS1302_SCLK = P3^6;
sbit DS1302_IO = P3^4;
sbit DS1302_CE = P3^5;
sbit LCD_RS=P2^6;
sbit LCD_RW=P2^5;
sbit LCD_EN=P2^7;
unsigned char KeyNum;
unsigned char MODE;
unsigned char TimeSetSelect;
unsigned char TimeSetFlashFlag;
unsigned char DS1302_Time[] = {23, 8, 16, 14, 4, 00, 3};
unsigned char Key();
unsigned char DS1302_ReadByte(unsigned char Command);
int LCD_Pow(int X, int Y);
void TimeShow(void);
void TimeSet(void);
void LCD_Init();
void LCD_ShowBinNum(unsigned char Line, unsigned char Column, unsigned int Number, unsigned char Length);
void LCD_ShowHexNum(unsigned char Line,	unsigned char Column, unsigned int Number, unsigned char Length);
void LCD_ShowSignedNum(unsigned char Line, unsigned char Column, int Number, unsigned char Length);
void LCD_ShowNum(unsigned char Line, unsigned char Column, unsigned int Number, unsigned char Length);
void LCD_ShowString(unsigned char Line, unsigned char Column, char *String);
void LCD_ShowChar(unsigned char Line, unsigned char Column, char Char);
void LCD_SetCursor(unsigned char Line, unsigned char Column);
void LCD_WriteData(unsigned char Data);
void LCD_WriteCommand(unsigned char Command);
void LCD_Delay();
void Timer0_Init();
void DS1302_GetTime(void);
void DS1302_SetTime(void);
void Delay(unsigned int xms);
void DS1302_Init(void);
void DS1302_WriteByte(unsigned char Command, Data);
/* 《按键调时》
* K1: 切换时钟模式[显示<=>设置]。按键将改变MODE值，根据MODE值调用不同的函数[TimeShow()<=>TimeSet()]
* K2: 时钟设置选择位[Y<=>M<=>D<=>H<=>M<=>S]
* K3: 加
* K4: 减
*/
void main()
{
	Timer0_Init();
	LCD_Init();
	DS1302_Init();
	// 2023-08-16 Week3
	// 13:20:35  ZDXSDU
	LCD_ShowString(1, 1, "20  -  -   Week");
	LCD_ShowString(2, 1, "  :  :    ZDXSDU");
	DS1302_SetTime();
	while(1)
	{
		KeyNum = Key();
		if(KeyNum == 1)
		{			
			if(MODE == 0) MODE = 1;
			else if(MODE == 1)
			{
				MODE = 0;
				DS1302_SetTime();
			}				
		}		
		switch(MODE)
		{
			case 0 : 
				TimeShow(); 
				LCD_ShowString(1, 12, "week");
				break;
			case 1 : 
				TimeSet();
				LCD_ShowString(1, 12, " set");
				break;
		}
	}
}
/**
* @brief 读取DS1302的时间，并显示在LCD1602上
* @param  无
* @retval 无
* @interpretation  描述
*/
void TimeShow(void)
{
	DS1302_GetTime();
	LCD_ShowNum(1,3,DS1302_Time[0],2); // 年
	LCD_ShowNum(1,6,DS1302_Time[1],2); // 月
	LCD_ShowNum(1,9,DS1302_Time[2],2); // 日
	LCD_ShowNum(2,1,DS1302_Time[3],2); // 时
	LCD_ShowNum(2,4,DS1302_Time[4],2); // 分
	LCD_ShowNum(2,7,DS1302_Time[5],2); // 秒
	LCD_ShowNum(1,16,DS1302_Time[6],1); // 周
}
/**
* @brief 设置时钟
* @param  无
* @retval 无
* @interpretation  描述
*/
void TimeSet(void)
{
	if(KeyNum == 2) // 选择要调整的项目，0~5依次分别对应年月日时分秒同时对应DS1302_Time的index
	{
		TimeSetSelect++;
		TimeSetSelect %= 7; // 越界清零相当于if(TimeSetSelect > 6) TimeSetSelect = 0;
	}
	if(KeyNum == 3) // 对选中的值进行加1
	{
		DS1302_Time[TimeSetSelect]++;
		// 合法性判断
		if(DS1302_Time[0] > 99) DS1302_Time[0] = 0;
		if(DS1302_Time[1] > 12) DS1302_Time[1] = 1;
		if(DS1302_Time[1] == 1 || DS1302_Time[1] == 3 || DS1302_Time[1] == 5 || DS1302_Time[1] == 7 || DS1302_Time[1] == 8 || DS1302_Time[1] == 10 || DS1302_Time[1] == 12)
		{
			if(DS1302_Time[2] > 31) DS1302_Time[2] = 1;
		}
		else if(DS1302_Time[1] == 4 || DS1302_Time[1] == 6 || DS1302_Time[1] == 9 || DS1302_Time[1] == 11)
		{
			if(DS1302_Time[2] > 30) DS1302_Time[2] = 1;
		}
		else if(DS1302_Time[1] == 2)
		{
			if(DS1302_Time[0] % 4 == 0)
			{ 
				if(DS1302_Time[2] > 29) DS1302_Time[2] = 1;
			}
			else
			{
				if(DS1302_Time[2] > 28) DS1302_Time[2] = 1;
			}
		}
		if(DS1302_Time[3] > 23) DS1302_Time[3] = 0;
		if(DS1302_Time[4] > 59) DS1302_Time[4] = 0;
		if(DS1302_Time[5] > 59) DS1302_Time[5] = 0;
		if(DS1302_Time[6] > 7) DS1302_Time[6] = 1;
	}
	if(KeyNum == 4) // 队选中的值进行减1
	{
		DS1302_Time[TimeSetSelect]--;
		// 合法性判断，由于使用的是无符号的数据类型 因此当减到0再减1时 结果不是-1 而是255，所以这里要用>100来判断
		if(DS1302_Time[0] > 100) DS1302_Time[0] = 99;
		// 月份的合法性判断中还需要包含对日期的切换
		if(DS1302_Time[1] == 0) DS1302_Time[1] = 12;		
		if(DS1302_Time[1] == 1 || DS1302_Time[1] == 3 || DS1302_Time[1] == 5 || DS1302_Time[1] == 7 || DS1302_Time[1] == 8 || DS1302_Time[1] == 10 || DS1302_Time[1] == 12)
		{
			if(DS1302_Time[2] == 0) DS1302_Time[2] = 31;
			if(DS1302_Time[2] > 31) DS1302_Time[2] = 1;
		}
		else if(DS1302_Time[1] == 4 || DS1302_Time[1] == 6 || DS1302_Time[1] == 9 || DS1302_Time[1] == 11)
		{
			if(DS1302_Time[2] == 0) DS1302_Time[2] = 30;
			if(DS1302_Time[2] > 30) DS1302_Time[2] = 1;
		}
		else if(DS1302_Time[1] == 2)
		{
			if(DS1302_Time[0] % 4 == 0)
			{ 
				if(DS1302_Time[2] == 0) DS1302_Time[2] = 29;
				if(DS1302_Time[2] > 29) DS1302_Time[2] = 1;
			}
			else
			{
				if(DS1302_Time[2] == 0) DS1302_Time[2] = 28;
				if(DS1302_Time[2] > 28) DS1302_Time[2] = 1;
			}
		}
		if(DS1302_Time[3] > 100) DS1302_Time[3] = 23;
		if(DS1302_Time[4] > 100) DS1302_Time[4] = 59;
		if(DS1302_Time[5] > 100) DS1302_Time[5] = 59;
		if(DS1302_Time[6] == 0) DS1302_Time[6] = 7;
	}
	// 加减完成后需要对LCD进行重新显示但不重新请求DS1302
	// 如果当前的被选中了，并且数字闪烁的标识位为真，则不显示该数字，反之则显示
	if(TimeSetSelect == 0 && TimeSetFlashFlag == 1)
	{
		LCD_ShowString(1, 3, "  ");
	}
	else
	{
		LCD_ShowNum(1,3,DS1302_Time[0],2); // 年
	}	
	if(TimeSetSelect == 1 && TimeSetFlashFlag == 1)
	{
		LCD_ShowString(1, 6, "  ");
	}
	else
	{
		LCD_ShowNum(1,6,DS1302_Time[1],2); // 月
	}
	if(TimeSetSelect == 2 && TimeSetFlashFlag == 1)
	{
		LCD_ShowString(1, 9, "  ");
	}
	else
	{
		LCD_ShowNum(1,9,DS1302_Time[2],2); // 日
	}
	if(TimeSetSelect == 3 && TimeSetFlashFlag == 1)
	{
		LCD_ShowString(2, 1, "  ");
	}
	else
	{
		LCD_ShowNum(2,1,DS1302_Time[3],2); // 时
	}
	if(TimeSetSelect == 4 && TimeSetFlashFlag == 1)
	{
		LCD_ShowString(2, 4, "  ");
	}
	else
	{
		LCD_ShowNum(2,4,DS1302_Time[4],2); // 分
	}
	if(TimeSetSelect == 5 && TimeSetFlashFlag == 1)
	{
		LCD_ShowString(2, 7, "  ");
	}
	else
	{
		LCD_ShowNum(2,7,DS1302_Time[5],2); // 秒
	}
	if(TimeSetSelect == 6 && TimeSetFlashFlag == 1)
	{
		LCD_ShowString(1, 16, "  ");
	}
	else
	{
		LCD_ShowNum(1,16,DS1302_Time[6],1); // 周
	}
}
/**
* @brief 定时器0的中断函数
* @param  无
* @retval 无
* @interpretation  描述
*/
void Timer0_Routine() interrupt 1
{
	static unsigned int T0Count; // 静态变量用于记录中断次数
	// 每一次中断都将定时器的初始值重新赋值，以保证每次都是1ms中断
	TH0 = 0xFC;
	TL0 = 0x18;
	// 每一次中断（1MS），都将T0Count计数器加一，直到加满1000MS视为一秒钟，此时要将T0Count计数器置0
	T0Count++;
	if(T0Count >= 500)
	{
		T0Count = 0;
		TimeSetFlashFlag = !TimeSetFlashFlag; // 通过控制闪烁标志位来实现对应的数字闪烁
	}
}
/**
* @brief 延时子函数
* @param  unsigned int xms 延时时间
* @retval 无
* @interpretation  描述
*/
void Delay(unsigned int xms)
{
	unsigned char i, j;
	while(xms--)
	{
		i = 2;
		j = 239;
		do
		{
			while (--j);
		} while (--i);
	}
}
/**
* @brief DS1302初始化
* @param  无
* @retval 无
* @interpretation 由于MCU上电时I/O口均为高电平，需要给DS1302的时钟和使能引脚低电平
*/
void DS1302_Init(void)
{
	DS1302_CE = 0;
	DS1302_SCLK = 0;
}
/**
* @brief 向DS1302写入数据
* @param Command：命令字
* @param Data：写入的数据字节
* @retval 无
* @interpretation 描述
*/
void DS1302_WriteByte(unsigned char Command, Data)
{
	unsigned char i;
	DS1302_CE = 1; // 芯片使能引脚给高电平使其有效	
	for(i = 0; i < 8; i++)
	{
		DS1302_IO = Command & (0x01 << i); // 取出命令字的第i位
		DS1302_SCLK = 1; // 上升沿将数据写入DS1302
		DS1302_SCLK = 0; // 恢复串行时钟置0
	}
	for(i = 0; i < 8; i++)
	{
		DS1302_IO = Data & (0x01 << i); // 取出Data字节的第i位
		DS1302_SCLK = 1; // 上升沿将数据写入DS1302
		DS1302_SCLK = 0; // 恢复串行时钟置0
	}
	DS1302_CE = 0; // 关闭芯片使能
}
/**
* @brief 向DS1302读取数据
* @param Command：命令字
* @retval [char]: DS1302返回的数据
* @interpretation  描述
*/
unsigned char DS1302_ReadByte(unsigned char Command)
{
	unsigned char i, Data = 0x00;
	DS1302_CE = 1; // 芯片使能引脚给高电平使其有效
	for(i = 0; i < 8; i++)
	{
		DS1302_IO = Command & (0x01 << i); // 取出命令字的第i位
		// 由于DS1302的写入和读取的时序不一样，这里需要先给0再给1
		DS1302_SCLK = 0; // 恢复串行时钟置0
		DS1302_SCLK = 1; // 上升沿将数据写入DS1302
	}
	for(i = 0; i < 8; i++)
	{
		// 这里在取数据的时候又将时序反了过来，原因是如果先0后1会造成多给了一个脉冲周期
		DS1302_SCLK = 1; // 恢复串行时钟置1
		DS1302_SCLK = 0; // 下降沿读取DS1302的数据		
		if(DS1302_IO)
			Data |= (0x01 << i); // 如果DS1302的返回值是1，那么就将接收变量Data对应位置也变成1
	}
	DS1302_CE = 0; // 关闭芯片使能
	DS1302_IO = 0; // 将串行数据口清零，防止读出的不对
	return Data;
}
/**
* @brief 将上方的DS1302_Time中的时间写入到DS1302中
* @param  无
* @retval 无
* @interpretation  描述
*/
void DS1302_SetTime(void)
{
	DS1302_WriteByte(DS1302_WP, 0x00); // 关闭DS1302芯片写保护
	DS1302_WriteByte(DS1302_Year_Write, DS1302_Time[0] / 10 * 16 + DS1302_Time[0] % 10); // 将年转成BCD码后，写入DS1302
	DS1302_WriteByte(DS1302_Month_Write, DS1302_Time[1] / 10 * 16 + DS1302_Time[1] % 10); // 将月转成BCD码后，写入DS1302
	DS1302_WriteByte(DS1302_Day_Write, DS1302_Time[2] / 10 * 16 + DS1302_Time[2] % 10); // 将日期转成BCD码后，写入DS1302
	DS1302_WriteByte(DS1302_Hour_Write, DS1302_Time[3] / 10 * 16 + DS1302_Time[3] % 10); // 将小时转成BCD码后，写入DS1302
	DS1302_WriteByte(DS1302_Minute_Write, DS1302_Time[4] / 10 * 16 + DS1302_Time[4] % 10); // 将分钟转成BCD码后，写入DS1302
	DS1302_WriteByte(DS1302_Second_Write, DS1302_Time[5] / 10 * 16 + DS1302_Time[5] % 10); // 将秒转成BCD码后，写入DS1302
	DS1302_WriteByte(DS1302_Week_Write, DS1302_Time[6] / 10 * 16 + DS1302_Time[6] % 10); // 将星期几转成BCD码后，写入DS1302
	DS1302_WriteByte(DS1302_WP, 0x80); // 打开DS1302芯片写保护
}
/**
* @brief 把DS1302中的时间读取出来放到上方的DS1302_Time数组中
* @param  无
* @retval 无
* @interpretation  描述
*/
void DS1302_GetTime(void)
{
	unsigned char RetvalTemp; // 这里定义一个临时变量，防止在BCD转DEC的时候两次调用返回的值不对（时间总是会流逝的）
	// 由于上方定义的地址都是写数据的地址，并且读的地址相当于写地址的LSB位改成1，因此需要对其或等于，将最低为改成零
	RetvalTemp = DS1302_ReadByte(DS1302_Year_Write | 0x01);
	DS1302_Time[0] = RetvalTemp / 16 * 10 + RetvalTemp % 16;
	RetvalTemp = DS1302_ReadByte(DS1302_Month_Write | 0x01);
	DS1302_Time[1] = RetvalTemp / 16 * 10 + RetvalTemp % 16;
	RetvalTemp = DS1302_ReadByte(DS1302_Day_Write | 0x01);
	DS1302_Time[2] = RetvalTemp / 16 * 10 + RetvalTemp % 16;
	RetvalTemp = DS1302_ReadByte(DS1302_Hour_Write | 0x01);
	DS1302_Time[3] = RetvalTemp / 16 * 10 + RetvalTemp % 16;
	RetvalTemp = DS1302_ReadByte(DS1302_Minute_Write | 0x01);
	DS1302_Time[4] = RetvalTemp / 16 * 10 + RetvalTemp % 16;
	RetvalTemp = DS1302_ReadByte(DS1302_Second_Write | 0x01);
	DS1302_Time[5] = RetvalTemp / 16 * 10 + RetvalTemp % 16;
	RetvalTemp = DS1302_ReadByte(DS1302_Week_Write | 0x01);
	DS1302_Time[6] = RetvalTemp / 16 * 10 + RetvalTemp % 16;
}
/**
* @brief 定时器0的1毫秒*1000=1秒定时器通用初始化函数
* @param  无
* @retval 无
*/
void Timer0_Init()
{
	// 在不改变定时器1的前提下配置定时器0的模式寄存器TMOD（不可位寻址）
	TMOD &= 0xF0;
	TMOD |= 0x01;
	// 配置定时器0的控制寄存器TCON（可位寻址）
	TF0 = 0; // 溢出中断标志置于0，防止定时器刚一启动就中断
	TR0 = 1; // 运行控制位，允许T0开始计数
	// 配置定时器的初始值（高4位+低4位）
	TH0 = 0xFC; // DEC[(65535-1000)/16^2]=>HEX 取出高位
	TL0 = 0x18; // DEC[(65535-1000)%16^2]=>HEX 取出低位
	// 配置中断系统的寄存器以及中断优先级
	ET0 = 1; // 中断
	EA = 1; // 总中断使能
	PT0 = 0;// 优先级置于最低
}
/**
* @brief  获取独立按键键码
* @param  无
* @retval 按下按键的键码，范围：0~4，无按键按下时返回值为0
*/
unsigned char Key()
{
	unsigned char KeyNumber = 0;	
	if(P3_1 == 0)
	{
		Delay(20);
		while(P3_1 == 0);
		Delay(20);
		KeyNumber = 1;
	}
	if(P3_0 == 0)
	{
		Delay(20);
		while(P3_0 == 0);
		Delay(20);
		KeyNumber = 2;
	}
	if(P3_2 == 0)
	{
		Delay(20);
		while(P3_2 == 0);
		Delay(20);
		KeyNumber = 3;
	}
	if(P3_3 == 0)
	{
		Delay(20);
		while(P3_3 == 0);
		Delay(20);
		KeyNumber = 4;
	}	
	return KeyNumber;
}
/**
* @brief  LCD1602延时函数，12MHz调用可延时1ms
* @param  无
* @retval 无
*/
void LCD_Delay()
{
	unsigned char i, j;

	i = 2;
	j = 239;
	do
	{
		while (--j);
	} while (--i);
}

/**
* @brief  LCD1602写命令
* @param  Command 要写入的命令
* @retval 无
*/
void LCD_WriteCommand(unsigned char Command)
{
	LCD_RS = 0;
	LCD_RW = 0;
	LCD_DataPort = Command;
	LCD_EN = 1;
	LCD_Delay();
	LCD_EN = 0;
	LCD_Delay();
}

/**
* @brief  LCD1602写数据
* @param  Data 要写入的数据
* @retval 无
*/
void LCD_WriteData(unsigned char Data)
{
	LCD_RS = 1;
	LCD_RW = 0;
	LCD_DataPort = Data;
	LCD_EN = 1;
	LCD_Delay();
	LCD_EN = 0;
	LCD_Delay();
}
/**
* @brief  LCD1602设置光标位置
* @param  Line 行位置，范围：1~2
* @param  Column 列位置，范围：1~16
* @retval 无
*/
void LCD_SetCursor(unsigned char Line, unsigned char Column)
{
	if(Line == 1)
	{
		LCD_WriteCommand(0x80 | (Column - 1));
	}
	else if(Line == 2)
	{
		LCD_WriteCommand(0x80 | (Column - 1 + 0x40));
	}
}
/**
* @brief  LCD1602初始化函数
* @param  无
* @retval 无
*/
void LCD_Init()
{
	LCD_WriteCommand(0x38);//八位数据接口，两行显示，5*7点阵
	LCD_WriteCommand(0x0c);//显示开，光标关，闪烁关
	LCD_WriteCommand(0x06);//数据读写操作后，光标自动加一，画面不动
	LCD_WriteCommand(0x01);//光标复位，清屏
}
/**
* @brief  在LCD1602指定位置上显示一个字符
* @param  Line 行位置，范围：1~2
* @param  Column 列位置，范围：1~16
* @param  Char 要显示的字符
* @retval 无
*/
void LCD_ShowChar(unsigned char Line, unsigned char Column, char Char)
{
	LCD_SetCursor(Line, Column);
	LCD_WriteData(Char);
}

/**
* @brief  在LCD1602指定位置开始显示所给字符串
* @param  Line 起始行位置，范围：1~2
* @param  Column 起始列位置，范围：1~16
* @param  String 要显示的字符串
* @retval 无
*/
void LCD_ShowString(unsigned char Line, unsigned char Column, char *String)
{
	unsigned char i;
	LCD_SetCursor(Line, Column);
	for(i = 0; String[i] != '\0'; i++)
	{
		LCD_WriteData(String[i]);
	}
}
/**
* @brief  返回值=X的Y次方
*/
int LCD_Pow(int X, int Y)
{
	unsigned char i;
	int Result = 1;
	for(i = 0; i < Y; i++)
	{
		Result *= X;
	}
	return Result;
}
/**
* @brief  在LCD1602指定位置开始显示所给数字
* @param  Line 起始行位置，范围：1~2
* @param  Column 起始列位置，范围：1~16
* @param  Number 要显示的数字，范围：0~65535
* @param  Length 要显示数字的长度，范围：1~5
* @retval 无
*/
void LCD_ShowNum(unsigned char Line, unsigned char Column, unsigned int Number, unsigned char Length)
{
	unsigned char i;
	LCD_SetCursor(Line, Column);
	for(i = Length; i > 0; i--)
	{
		LCD_WriteData(Number / LCD_Pow(10, i - 1) % 10 + '0');
	}
}
/**
* @brief  在LCD1602指定位置开始以有符号十进制显示所给数字
* @param  Line 起始行位置，范围：1~2
* @param  Column 起始列位置，范围：1~16
* @param  Number 要显示的数字，范围：-32768~32767
* @param  Length 要显示数字的长度，范围：1~5
* @retval 无
*/
void LCD_ShowSignedNum(unsigned char Line, unsigned char Column, int Number, unsigned char Length)
{
	unsigned char i;
	unsigned int Number1;
	LCD_SetCursor(Line,Column);
	if(Number >= 0)
	{
		LCD_WriteData('+');
		Number1 = Number;
	}
	else
	{
		LCD_WriteData('-');
		Number1 = -Number;
	}
	for(i = Length; i > 0; i--)
	{
		LCD_WriteData(Number1 / LCD_Pow(10, i - 1) % 10 + '0');
	}
}
/**
* @brief  在LCD1602指定位置开始以十六进制显示所给数字
* @param  Line 起始行位置，范围：1~2
* @param  Column 起始列位置，范围：1~16
* @param  Number 要显示的数字，范围：0~0xFFFF
* @param  Length 要显示数字的长度，范围：1~4
* @retval 无
*/
void LCD_ShowHexNum(unsigned char Line,
	unsigned char Column,
	unsigned int Number,
	unsigned char Length)
{
	unsigned char i, SingleNumber;
	LCD_SetCursor(Line, Column);
	for(i = Length; i > 0; i--)
	{
		SingleNumber = Number / LCD_Pow(16, i - 1) % 16;
		if(SingleNumber < 10)
		{
			LCD_WriteData(SingleNumber + '0');
		}
		else
		{
			LCD_WriteData(SingleNumber - 10 + 'A');
		}
	}
}
/**
* @brief  在LCD1602指定位置开始以二进制显示所给数字
* @param  Line 起始行位置，范围：1~2
* @param  Column 起始列位置，范围：1~16
* @param  Number 要显示的数字，范围：0~1111 1111 1111 1111
* @param  Length 要显示数字的长度，范围：1~16
* @retval 无
*/
void LCD_ShowBinNum(unsigned char Line, 
	unsigned char Column, 
	unsigned int Number, 
	unsigned char Length)
{
	unsigned char i;
	LCD_SetCursor(Line, Column);
	for(i = Length; i > 0; i--)
	{
		LCD_WriteData(Number / LCD_Pow(2, i - 1) % 2 + '0');
	}
}
