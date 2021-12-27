/*
 * SWITCH_Program.c
 *
 *  Created on: Aug 27, 2019
 *      Author: Masria For PCs
 */

#include "../../LIB/types.h"
#include "SWITCH_Interface.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include <util/delay.h>

/*
uint8 SWITCH_uGetSwitchValue (uint8 Name_Port ,uint8 Switch_Num)
{

	uint8 res=0;

	DIO_vSetPinDirection   (Name_Port ,Switch_Num,INPUTWPULLUP);
	res=SWITCH_uDebounceKey (Name_Port ,Switch_Num);
	return res ;

}


uint8  SWITCH_uDebounceKey (uint8 Name_Port , uint8 Switch_Num)
{
	static uint8 count_H =5 ;
	static uint8 count_L =5 ;
	uint8 value ;
	value= DIO_uReadPinDirection  (Name_Port ,Switch_Num);
	switch (value)
	{
	case HIGH :
		_delay_ms(5);
		if (count_H--)
		{
			count_L =5 ;
			SWITCH_uDebounceKey (Name_Port ,Switch_Num);
		}
		break;
	case LOW :
		_delay_ms(2);
		if (count_L--)
		{
		count_H =5 ;
		SWITCH_uDebounceKey (Name_Port ,Switch_Num);
		}
		break;

	}
	return value;
}

*/

uint8 SWITCH_uGetSwitchValue (uint8 Name_Port , uint8 Switch_Num)
{
	return SWITCH_uDebounceKey(Name_Port ,Switch_Num);
}


uint8  SWITCH_uDebounceKey (uint8 Name_Port ,uint8 Switch_Num)
{
	uint8 count_high=0;
	uint8 count_low =0;
	uint8 max_count=10;
			do
			{
				_delay_ms(1);
				if (DIO_uReadPinDirection(Name_Port, Switch_Num)==LOW)
				{
					count_low ++;
					count_high=0;
				}
				else
				{
					count_high ++;
					count_low =0;
				}
			}
			while (count_high <max_count && count_low < max_count);

			if (count_high >= max_count)
				return HIGH;
				return LOW;

}
