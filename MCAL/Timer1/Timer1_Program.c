/*
 * Timer1_Program.c
 *
 *  Created on: Sep 7, 2019
 *      Author: Masria For PCs
 */
#include "Timer1_Reg.h"
#include "Timer1_Interface.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../LIB/calc_bits.h"
#include "../../LIB/types.h"


static TIMER1_CONFIG TIM1_Str = { PWM_INV };

void PMW_Init ()
{
	DIO_vSetPinDirection(PORT_D,5,OUTPUT);
	DIO_vWritePinValue(PORT_D,5,HIGH);

	DIO_vSetPinDirection(PORT_A,MOTOR1_PIN1,OUTPUT);
	DIO_vWritePinValue(PORT_A,MOTOR1_PIN1,HIGH);

	DIO_vSetPinDirection(PORT_A,MOTOR1_PIN2,OUTPUT);
	DIO_vWritePinValue(PORT_A,MOTOR1_PIN2,LOW);

	DIO_vSetPinDirection(PORT_A,MOTOR2_PIN1,OUTPUT);
	DIO_vWritePinValue(PORT_A,MOTOR2_PIN1,HIGH);

	DIO_vSetPinDirection(PORT_A,MOTOR2_PIN2,OUTPUT);
	DIO_vWritePinValue(PORT_A,MOTOR2_PIN2,LOW);

}


void PWM_Generate(uint8 DutyCycle,uint32 freq)
{
	uint16 comp_value ;
	uint16 local_top ;
	if (TIM1_Str.mode_inv == PWM_INV)
	{
		//mode 14
		clear_bit(TCCR1A ,WGM10);
		set_bit  (TCCR1A ,WGM11);
		set_bit  (TCCR1A ,WGM12);
		set_bit  (TCCR1A ,WGM13);

		set_bit  (TCCR1A ,COM1A0);
		set_bit  (TCCR1A ,COM1B0);
		set_bit  (TCCR1A ,COM1A1);
		set_bit  (TCCR1A ,COM1B1);

		local_top=(16000000/freq)-1;
		comp_value = (((local_top+1)/100)*(DutyCycle));
		OCR1AH = comp_value >> 0x0008;
		OCR1AL = comp_value & 0X00FF;


		ICR1H =(local_top & 0xff00) >> 0x0008;
		ICR1L = local_top & 0x00ff;

	}
	else if (TIM1_Str.mode_inv== PWM_NONINV)
	{
		//mode 14
		clear_bit(TCCR1A ,WGM10);
		set_bit  (TCCR1A ,WGM11);
		set_bit  (TCCR1A ,WGM12);
		set_bit  (TCCR1A ,WGM13);

		clear_bit(TCCR1A ,COM1A0);
		clear_bit(TCCR1A ,COM1B0);
		set_bit  (TCCR1A ,COM1A1);
		set_bit  (TCCR1A ,COM1B1);

		local_top=(16000000/(2*freq));
		comp_value = (((local_top/100))*(100-DutyCycle));
		OCR1AH = comp_value >> 0x0008;
		OCR1AL = comp_value & 0X00FF;


		ICR1H =(local_top & 0xff00) >> 0x0008;
		ICR1L = local_top & 0x00ff;

	}

	else if (TIM1_Str.mode_inv==PHASE_CORRECT_INV)
	{
		clear_bit(TCCR1A ,WGM10);
		set_bit  (TCCR1A ,WGM11);
		clear_bit(TCCR1A ,WGM12);
		set_bit  (TCCR1A ,WGM13);

		set_bit  (TCCR1A ,COM1A0);
		set_bit  (TCCR1A ,COM1B0);
		set_bit  (TCCR1A ,COM1A1);
		set_bit  (TCCR1A ,COM1B1);

		local_top=(16000000/(2*freq));
				comp_value = (((local_top+1)/100)*(100-DutyCycle));
				OCR1AH = comp_value >> 0x0008;
				OCR1AL = comp_value & 0X00FF;

				ICR1H =( local_top & 0xff00 ) >> 0x0008;
				ICR1L = local_top & 0x00ff;
	}

	else if (TIM1_Str.mode_inv== PHASE_CORRECT_NONINV)
	{
		clear_bit(TCCR1A ,WGM10);
		set_bit  (TCCR1A ,WGM11);
		clear_bit(TCCR1A ,WGM12);
		set_bit  (TCCR1A ,WGM13);

		clear_bit(TCCR1A ,COM1A0);
		clear_bit(TCCR1A ,COM1B0);
		set_bit  (TCCR1A ,COM1A1);
		set_bit  (TCCR1A ,COM1B1);

		local_top=(16000000/(2*freq));
		comp_value = (((local_top+1)/100)*(DutyCycle));
		OCR1AH = comp_value >> 0x0008;
		OCR1AL = comp_value & 0X00FF;

		ICR1H =( local_top & 0xff00 ) >> 0x0008;
		ICR1L = local_top & 0x00ff;

	}

}
