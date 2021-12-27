/*
 * SENDER_RECIVER_Program.c
 *
 *  Created on: Oct 11, 2019
 *      Author: Masria For PCs
 */

#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../MCAL/UART/UART_Interface.h"
#include "../../LIB/types.h"
#include "../../HAL/LCD/LCD_Interface.h"
#include "../../HAL/SWITCH/SWITCH_Interface.h"
#include "../../MCAL/ADC/ADC_Interface.h"
#include "../../HAL/KEYPAD/KEYPAD_Interface.h"

void APP_vFinalProject ()
{
	while (1)
		{

			if (1)
			{
				if (SWITCH_uGetSwitchValue(PORT_D,2)==0)
				{

					LCD_vInit();
					LCD_vClear();
					ADC_Init ();
					ADC_Config ();
					ADC_StartConversion ();
					uint16 temp =ADC_GetConvertedValue ();
					uint16 tempt=temp/4;
					DIO_vSetPinDirection(PORT_D , Rx , INPUTWOPULLUP);
					DIO_vSetPinDirection(PORT_D , Tx , OUTPUT);
					UART_Init();
					UART_TransmitData(tempt);
					uint8 Dos =UART_ReceivetData();

					LCD_vGotoxy(1,0);


					 uint8 result[2];
					 uint8 i=0,j=0;
					 if (Dos<100)
					 {
						 j=2;
					 }
					 else if (Dos>100)
					 {
						 j=3;
					 }
					for(i=0;i<j;i++)
					{
						 result[i]=Dos%10;
						 Dos=Dos/10;

					 }
					/* for(i=1;i>=0;i--)
					 {
					 	 LCD_vSendCharacter(result[i]+48);
					 }*/
					DIO_vSetPinDirection(PORT_D,3,OUTPUT);
					DIO_vWritePinValue(PORT_D,3,LOW);
					 LCD_vSendCharacter(result[1]+48);
					 LCD_vSendCharacter(result[0]+48);


					 LCD_vGotoxy(2,0);
					 uint8 String[15]="Deuty";
					 LCD_vSendString (String);
					 LCD_vGotoxy(2,7);
					 while (1)
					 {

					 KEYPAD_vInit ();
					  uint8 x;
					 	x=KEYPAD_uGetKey();
				    	 if (x!=25)
						 {

			 			 LCD_vSendCharacter(x);}

				 		 }
			//		 		 }

				}
				else if (SWITCH_uGetSwitchValue(PORT_D,2)==1)
				{
						LCD_vInit();
						LCD_vClear();
					DIO_vSetPinDirection(PORT_D,3,OUTPUT);
					DIO_vWritePinValue(PORT_D,3,HIGH);

				}
			}
		}

}
