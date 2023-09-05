#ifndef __OneWire_H__
#define __OneWire_H__
unsigned char OneWire_Init(void);
void OneWire_SendBit(unsigned char Bit);
unsigned char OneWire_ReadBit(void);
void OneWire_SendByte(unsigned char byte);
unsigned char OneWire_ReadBtye(void);
#endif