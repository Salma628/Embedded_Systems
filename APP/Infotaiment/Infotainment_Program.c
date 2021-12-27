/*
 * Infotainment_Project.c
 *
 *  Created on: Aug 29, 2019
 *      Author: Masria For PCs
 */

#include "../../LIB/types.h"
#include "../../LIB/calc_bits.h"
#include "Infotainment_Interface.h"
#include "../../HAL/LCD/LCD_Interface.h"
#include "../../HAL/KEYPAD/KEYPAD_Interface.h"
#include "util/delay.h"

void APP_vProject ()
{
	LCD_vInit();
	LCD_vGotoxy(1,4);
	uint8 String[15]="WELCOME";
	LCD_vSendString (String);
	_delay_ms(3000);
	LCD_vSendCommand(LCD_CLEAR);
	uint8 String1[20]="Start Game!";
	LCD_vSendString (String1);
	_delay_ms(5000);
	LCD_vSendCommand(LCD_CLEAR);
	uint8 String2[16]="Today is Monday.";
	LCD_vSendString (String2);
	LCD_vGotoxy(2,0);
	uint8 String3[16]="After 61 days :";
	LCD_vSendString (String3);
	_delay_ms(10000);


	LCD_vSendCommand(LCD_CLEAR);
	LCD_vGotoxy(1,0);
	uint8 String4[16]="1-Sunday";
	LCD_vSendString (String4);
	LCD_vGotoxy(2,0);
	uint8 String5[16]="2-Saturday";
	LCD_vSendString (String5);
	_delay_ms(10000);

	uint8 x=0;


	LCD_vSendCommand(LCD_CLEAR);
			uint8 a=0;
			KEYPAD_vInit();
			_delay_ms(1000);
			while (1)
			{
			a=KEYPAD_uGetKey();
			 if (a!=25)
				 {
					 LCD_vGotoxy(1,0);
					 LCD_vSendCharacter(a);

					 _delay_ms(5000);
				 }
			 if (a == '2' || '1' )
			  break ;
			}
			if (a == '2' )
			{
				x ++;
			}


			LCD_vSendCommand(LCD_CLEAR);
			uint8 String6[16]="29 27 24 20 15";
			LCD_vSendString (String6);
			LCD_vGotoxy(2,0);
			uint8 String7[16]="what's next ?";
			LCD_vSendString (String7);
			_delay_ms(10000);



			LCD_vSendCommand(LCD_CLEAR);
			LCD_vGotoxy(1,0);
			uint8 String8[16]="1- 9";
			LCD_vSendString (String8);
			LCD_vGotoxy(2,0);
			uint8 String9[16]="2- 10";
			LCD_vSendString (String9);
			_delay_ms(10000);


			LCD_vSendCommand(LCD_CLEAR);
			a=0;
			KEYPAD_vInit();
			_delay_ms(1000);
			while (1)
			{
			a=KEYPAD_uGetKey();
			_delay_ms(1000);
			if (a!=25)
			 {
			 LCD_vGotoxy(1,0);
			 LCD_vSendCharacter(a);
			_delay_ms(5000);
			 }
			 if (a == '2' || '1' )
				 break ;
			}
			if (a == '1' )
			{
			x ++;
			}



			LCD_vSendCommand(LCD_CLEAR);
			LCD_vGotoxy(1,0);
			uint8 String12[16]="who is your";
			LCD_vSendString (String12);
			LCD_vGotoxy(2,0);
			uint8 String13[16]="favourite singer";
		    LCD_vSendString (String13);
			_delay_ms(10000);



			LCD_vSendCommand(LCD_CLEAR);
			LCD_vGotoxy(1,0);
			uint8 String14[16]="1- Amr Diab";
			LCD_vSendString (String14);
			LCD_vGotoxy(2,0);
			uint8 String15[16]="2- shreen";
			LCD_vSendString (String15);
			_delay_ms(10000);




			LCD_vSendCommand(LCD_CLEAR);
		     a=0;
			KEYPAD_vInit();
			_delay_ms(1000);
			while (1)
			{
			a=KEYPAD_uGetKey();
			if (a!=25)
	    	 {
			 LCD_vGotoxy(1,0);
			 LCD_vSendCharacter(a);
			_delay_ms(5000);
			 }
			 if (a == '2' || '1' )
				 break ;
			}
			if (a == '1')
			{
			x ++;
     		}




	LCD_vSendCommand(LCD_CLEAR);
	uint8 String10[16]="the score is :";
	LCD_vSendString (String10);
	LCD_vGotoxy(2,0);
	LCD_vSendCharacter(x+48);
	LCD_vGotoxy(2,1);
	uint8 String100[16]=" / 3 ";
	LCD_vSendString (String100);
	_delay_ms(10000);

}


