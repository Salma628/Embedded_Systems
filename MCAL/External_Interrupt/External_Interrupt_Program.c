/*
 * External_Interrupt_Program.c
 *
 *  Created on: Aug 28, 2019
 *      Author: Masria For PCs
 */

#include "External_Interrupt_Reg.h"
#include "External_Interrupt_Interface.h"
#include "../../LIB/types.h"
#include "../../LIB/calc_bits.h"
#include "../../MCAL/DIO/DIO_INTERFACE.h"
#include "../../MCAL/DIO/DIO_Reg.h"
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>


static EXT_Int_Conf Configuration_Ext_Int = {ENABLE_INT0,ENABLE_INT1,DISABLE_INT,RISING_EDGE_MODE,FALLING_EDGE_MODE,LOW_LEVEL_MODE};
void EXT_INT_Init(void)
{

	clear_bit(DDRD,Pin_Int0);
	clear_bit(DDRD,Pin_Int1);
	clear_bit(DDRB,Pin_Int2);
	set_bit(SREG,7);

	}


void EXT_INT_SET_CONFIG(void)
{
	/* Choose the configuration for the External Interrupt*/

	if(Configuration_Ext_Int.Enable_INT0_Interrupt == ENABLE_INT0)
	{
		set_bit (GICR,ENABLE_INT0);
	}
	else
		clear_bit(GICR,ENABLE_INT0);


	if(Configuration_Ext_Int.Enable_INT1_Interrupt == ENABLE_INT1)
	{
		set_bit (GICR , ENABLE_INT1);
	}
	else
			clear_bit(GICR,ENABLE_INT1);


	if(Configuration_Ext_Int.Enable_INT2_Interrupt == ENABLE_INT2)
		{
			set_bit (GICR , ENABLE_INT2);
		}
		else
				clear_bit(GICR,ENABLE_INT2);

	if(Configuration_Ext_Int.INT0_Triggering_Mode == LOW_LEVEL_MODE)
	{
		clear_bit(MCUCR,ISC00);
		clear_bit(MCUCR,ISC01);
	}
	else if (Configuration_Ext_Int.INT0_Triggering_Mode == FALLING_EDGE_MODE)
	{
		clear_bit(MCUCR,ISC00);
		set_bit  (MCUCR,ISC01);
	}
	else if (Configuration_Ext_Int.INT0_Triggering_Mode == RISING_EDGE_MODE)
	{
		set_bit  (MCUCR,ISC00);
		set_bit  (MCUCR,ISC01);
	}
	else
	{
		set_bit(MCUCR,ISC00);
		clear_bit(MCUCR,ISC01);
	}


	if(Configuration_Ext_Int.INT1_Triggering_Mode == LOW_LEVEL_MODE)
		{
			clear_bit(MCUCR,ISC10);
			clear_bit(MCUCR,ISC11);
		}
		else if (Configuration_Ext_Int.INT1_Triggering_Mode == FALLING_EDGE_MODE)
		{
			clear_bit(MCUCR,ISC10);
			set_bit  (MCUCR,ISC11);
		}
		else if (Configuration_Ext_Int.INT1_Triggering_Mode == RISING_EDGE_MODE)
		{
			set_bit  (MCUCR,ISC10);
			set_bit  (MCUCR,ISC11);
		}
		else
		{
			clear_bit(MCUCR,ISC11);
			set_bit(MCUCR,ISC10);
		}


	if(Configuration_Ext_Int.INT2_Triggering_Mode == LOW_LEVEL_MODE)
	{
		set_bit  (MCUCSR,ISC2);
	}
	else
		clear_bit(MCUCSR,ISC2);
}


ISR(INT0_vect)
{
DIO_vTogglePin(PORT_C,2);

}
