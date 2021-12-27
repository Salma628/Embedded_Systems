/*
 * LCD_Program.c
 *
 *  Created on: Aug 19, 2019
 *      Author: Masria For PCs0
 */
#define F_CPU 16000000UL
#include "../../LIB/types.h"
#include "../../LIB/calc_bits.h"
#include "LCD_Interface.h"
#include "../../MCAL/DIO/DIO_Reg.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "util/delay.h"
void LCD_vSendCommand (uint8 Command )
{
	/* 1- R/S equal to zero (command) */
	DIO_vWritePinValue  (CONTROL_LINES,LCD_RS,LOW);
	/* 2- R/W equal to zero (write )  */
	DIO_vWritePinValue  (CONTROL_LINES,LCD_RW,LOW);


	/* send first high four nibble */
	DIO_vWritePinValue  (DATA_LINES,LCD_D4,((Command & 0x10) >> LCD_D4));
	DIO_vWritePinValue  (DATA_LINES,LCD_D5,((Command & 0x20) >> LCD_D5));
	DIO_vWritePinValue  (DATA_LINES,LCD_D6,((Command & 0x40) >> LCD_D6));
	DIO_vWritePinValue  (DATA_LINES,LCD_D7,((Command & 0x80) >> LCD_D7));


	/************************** LATCH ****************************/
	DIO_vWritePinValue  (CONTROL_LINES,LCD_ENABLE,HIGH);
	_delay_ms(20);
	DIO_vWritePinValue  (CONTROL_LINES,LCD_ENABLE,LOW);
	/************************************************************/

	/*send second low four nibble */
	DIO_vWritePinValue  (DATA_LINES,LCD_D4,((Command & 0x01)));
	DIO_vWritePinValue  (DATA_LINES,LCD_D5,((Command & 0x02) >> (LCD_D5-CONST)));
	DIO_vWritePinValue  (DATA_LINES,LCD_D6,((Command & 0x04) >> (LCD_D6-CONST)));
	DIO_vWritePinValue  (DATA_LINES,LCD_D7,((Command & 0x08) >> (LCD_D7-CONST)));
	/****************************************************************/


	/************************* LATCH *******************************/
	DIO_vWritePinValue  (CONTROL_LINES,LCD_ENABLE,HIGH);
	_delay_ms(20);
	DIO_vWritePinValue  (CONTROL_LINES,LCD_ENABLE,LOW);
}

#include "LCD_Interface.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include <util/delay.h>

void LCD_vSendCharacter  (uint8 Data)
{
	/* 1- R/S equal to zero (command) */
		DIO_vWritePinValue  (CONTROL_LINES,LCD_RS,HIGH);
		/* 2- R/W equal to zero (write )  */
		DIO_vWritePinValue  (CONTROL_LINES,LCD_RW,LOW);


		/* send first high four nibble */
		DIO_vWritePinValue  (DATA_LINES,LCD_D4,((Data & 0x10) >> LCD_D4));
		DIO_vWritePinValue  (DATA_LINES,LCD_D5,((Data & 0x20) >> LCD_D5));
		DIO_vWritePinValue  (DATA_LINES,LCD_D6,((Data & 0x40) >> LCD_D6));
		DIO_vWritePinValue  (DATA_LINES,LCD_D7,((Data & 0x80) >> LCD_D7));


		/************************** LATCH ****************************/
		DIO_vWritePinValue  (CONTROL_LINES,LCD_ENABLE,HIGH);
		_delay_ms(20);
		DIO_vWritePinValue  (CONTROL_LINES,LCD_ENABLE,LOW);
		/************************************************************/

		/*send second low four nibble */
		DIO_vWritePinValue  (DATA_LINES,LCD_D4,((Data & 0x01)));
		DIO_vWritePinValue  (DATA_LINES,LCD_D5,((Data & 0x02) >> (LCD_D5-CONST)));
		DIO_vWritePinValue  (DATA_LINES,LCD_D6,((Data & 0x04) >> (LCD_D6-CONST)));
		DIO_vWritePinValue  (DATA_LINES,LCD_D7,((Data & 0x08) >> (LCD_D7-CONST)));
		/****************************************************************/


		/************************* LATCH *******************************/
		DIO_vWritePinValue  (CONTROL_LINES,LCD_ENABLE,HIGH);
		_delay_ms(20);
		DIO_vWritePinValue  (CONTROL_LINES,LCD_ENABLE,LOW);
}
void LCD_vInit ()
{
	_delay_ms(150);
	DIO_vSetPinDirection  (CONTROL_LINES,LCD_RS,OUTPUT);
	DIO_vSetPinDirection  (CONTROL_LINES,LCD_RW,OUTPUT);
	DIO_vSetPinDirection  (CONTROL_LINES,LCD_ENABLE,OUTPUT);
	DIO_vSetPinDirection  (DATA_LINES,LCD_D4,OUTPUT);
	DIO_vSetPinDirection  (DATA_LINES,LCD_D5,OUTPUT);
	DIO_vSetPinDirection  (DATA_LINES,LCD_D6,OUTPUT);
	DIO_vSetPinDirection  (DATA_LINES,LCD_D7,OUTPUT);

	DIO_vWritePinValue (CONTROL_LINES,LCD_ENABLE,LOW);
	_delay_ms(10);
	//DIO_vWritePinValue (CONTROL_LINES,LCD_ENABLE,HIGH);

	//LCD_vSendCommand (LCD_INIT_PHASE_ONE);
	_delay_ms(10);
	LCD_vSendCommand (LCD_INIT_PHASE_TWO);
	_delay_ms(10);
	LCD_vSendCommand (LCD_INIT_PHASE_THREE);
	_delay_ms(10);
	LCD_vSendCommand (LCD_DISPLAY_OPTIONS);
	_delay_ms(10);
	LCD_vSendCommand (LCD_CLEAR);
	_delay_ms(10);
	LCD_vSendCommand (LCD_INCREMENT_CURSOR);
	_delay_ms(10);
}
void LCD_vClear ()
{
	LCD_vSendCommand(LCD_CLEAR);
}

void LCD_vSendString (uint8 *ptr)   //if i use Arr[i] warning multi character
{
	while(*ptr)
	{

		LCD_vSendCharacter  (*ptr++);
		_delay_ms(10);

	}
}

void LCD_vGotoxy  (uint8 x, uint8 y)//x:1~2, y:0~15
{
	uint8 address = 0;
	if (x==1)
		address = 0x80;
	else if (x==2)
		address = 0xC0;
	if (y<16)
		address += y;
	LCD_vSendCommand (address);
}
