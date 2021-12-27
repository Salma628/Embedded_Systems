
/*
 * main.c
 *
 *  Created on: Aug 19, 2019
 *      Author: Masria For PCs
 */
#include <stdlib.h>
#define F_CPU 16000000UL
#include "MCAL/External_Interrupt/External_Interrupt_Reg.h"
#include "MCAL/External_Interrupt/External_Interrupt_Interface.h"
#include "HAL/SWITCH/SWITCH_Interface.h"
#include "LIB/types.h"
#include "LIB/calc_bits.h"
#include "MCAL/DIO/DIO_Interface.h"
#include "MCAL/DIO/DIO_Reg.h"
#include "HAL/LCD/LCD_Interface.h"
#include "HAL/KEYPAD/KEYPAD_Interface.h"
#include "APP/Infotaiment/Infotainment_Interface.h"
#include <util/delay.h>
#include <avr/interrupt.h>
#include "MCAL/Timer0/Timer0_Interface.h"
#include "MCAL/Timer1/Timer1_Interface.h"
#include "MCAL/UART/UART_Interface.h"
#include "MCAL/ADC/ADC_Interface.h"
#include "APP/SENDER_RECIVER/SENDER_RECIVER_Interface.h"

//static volatile uint16 Timer_Ticks =0;
//extern volatile uint16 time_reached ;



int main(void)
{

while (1)
{
	APP_vFinalProject ();
	/*PMW_Init ();
	PWM_Generate(100,1600);*/
	/*KEYPAD_vInit ();
		LCD_vInit();
		 uint8 x;
		 LCD_vClear();
		 while(1)
		 {

		 x=KEYPAD_uGetKey();
		 if (x!=25)
		 {
			 LCD_vGotoxy(1,5);
			 LCD_vSendCharacter(x);
			 _delay_ms(10);
		 }
		 }*/

}
return 0;
}


