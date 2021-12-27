/*
 * KEYPAD_Program.c
 *
 *  Created on: Aug 23, 2019
 *      Author: Masria For PCs
 */


#include "../../LIB/types.h"
#include "../../LIB/calc_bits.h"
#include "KEYPAD_Interface.h"
#include "../../MCAL/DIO/DIO_Reg.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include <util/delay.h>

void  KEYPAD_vInit ()
{
	//making four pins as output
	//making col as OUTPUT
	DIO_vSetPinDirection   (USED_PORT,COL1,OUTPUT);
	//DIO_vWritePinValue     (USED_PORT,COL1,HIGH);

	DIO_vSetPinDirection   (USED_PORT,COL2,OUTPUT);
	//DIO_vWritePinValue     (USED_PORT,COL2,HIGH);

	DIO_vSetPinDirection   (USED_PORT,COL3,OUTPUT);
	//DIO_vWritePinValue     (USED_PORT,COL3,HIGH);

	DIO_vSetPinDirection   (USED_PORT,COL4,OUTPUT);
	DIO_vWritePinValue     (USED_PORT,COL4,HIGH);

	//making four pins as inputwpullup
	//making row
	DIO_vSetPinDirection   (USED_PORT,ROW1,INPUTWPULLUP);

	DIO_vSetPinDirection   (USED_PORT,ROW2,INPUTWPULLUP);

	DIO_vSetPinDirection   (USED_PORT,ROW3,INPUTWPULLUP);

	DIO_vSetPinDirection   (USED_PORT,ROW4,INPUTWPULLUP);

}


uint8 KEYPAD_uGetKey()
{

	uint8 COL=0;
	uint8 ROW=0;
	uint8 state=0;
	uint8 Arr[4][4]={{'7','8','9','/'},{'4','5','6','*'},{'1','2','3','-'},{'*','0','=','+'}};
	uint8 pin;
	for (COL =4 ; COL<8 ; COL++)
	{
		DIO_vWritePinValue     (USED_PORT,COL1,HIGH);
		DIO_vWritePinValue     (USED_PORT,COL2,HIGH);
		DIO_vWritePinValue     (USED_PORT,COL3,HIGH);
		DIO_vWritePinValue     (USED_PORT,COL4,HIGH);
		DIO_vWritePinValue (USED_PORT,COL,LOW);
		for (ROW=0; ROW<4 ; ROW++)
		{

			 state=DIO_uReadPinDirection  (USED_PORT ,ROW);

			if (state==LOW)
			{
			//	KEYPAD_vDebouncing (state);
				pin=Arr[ROW][COL-4];
				return pin;
			}
		}
		DIO_vWritePinValue (USED_PORT,COL,HIGH);
	}
	return 25;
}

