/*
 * main_2.c
 *
 *  Created on: Sep 13, 2019
 *      Author: Masria For PCs
 */


/*
	UART_Init();
	while (1)
	{
		UART_TransmitData(0x08);
		uint8 D =UART_ReceivetData();
		if (D==0x08)
		{
			DIO_vSetPinDirection(PORT_D,3,OUTPUT);
			DIO_vWritePinValue(PORT_D,3,HIGH);
		}
	}
	*/



/*LCD_vInit();



	while (1)
	{
		LCD_vClear();
		ADC_Init ();
		ADC_Config ();
		ADC_StartConversion ();
		uint16 temp =ADC_GetConvertedValue ();
		uint16 temp2=temp/4;
		LCD_vGotoxy(1,0);
		//uint8 show[2];
		//itoa(temp2,show,10);
		//LCD_vSendString(show);
		while (temp2)
		{
			LCD_vSendCharacter((temp2%10)+48);
			temp2/=10;
		}

		_delay_ms(1000);
	}
*/




	/*Timer0_Init();
	Timer0_SetConfig();
	DIO_vSetPinDirection(PORT_C,7,OUTPUT);
	while (1)
	{
		if (Timer_Ticks == 1000)
		{
			DIO_vWritePinValue(PORT_C ,7,HIGH);
		}
		if (Timer_Ticks == 2000)
		{

			DIO_vWritePinValue(PORT_C ,7,LOW);
			Timer_Ticks ++;
		}

	}*/




	/*uint8 count=0;
while(count <5)
{
	DIO_vSetPinDirection   (PORT_C,2,OUTPUT);
	DIO_vWritePinValue     (PORT_C,2,HIGH);
	_delay_ms(1000);
	DIO_vSetPinDirection   (PORT_C,2,OUTPUT);
	DIO_vWritePinValue     (PORT_C,2,LOW);
	_delay_ms(1000);

	DIO_vSetPinDirection   (PORT_C,7,OUTPUT);
	DIO_vWritePinValue     (PORT_C,7,HIGH);
	_delay_ms(1000);
	DIO_vSetPinDirection   (PORT_C,7,OUTPUT);
		DIO_vWritePinValue     (PORT_C,7,LOW);

	_delay_ms(1000);
	DIO_vSetPinDirection   (PORT_D,3,OUTPUT);
	DIO_vWritePinValue     (PORT_D,3,HIGH);
	_delay_ms(1000);
	DIO_vSetPinDirection   (PORT_D,3,OUTPUT);
		DIO_vWritePinValue     (PORT_D,3,LOW);
		_delay_ms(1000);
		count++;

}*/

	//LCD_vInit();
	//_delay_ms(100);


	/***************************************************************/
	/*
	LCD_vSendCharacter('a');
	_delay_ms(10);
	LCD_vSendCharacter('l');
	_delay_ms(10);
	LCD_vSendCharacter('a');
	_delay_ms(10);
	LCD_vSendCharacter('a');
	_delay_ms(10);
	LCD_vSendCharacter(' ');
	_delay_ms(10);
	LCD_vSendCharacter('k');
	_delay_ms(10);
	LCD_vSendCharacter('h');
	_delay_ms(10);
	LCD_vSendCharacter('a');
	_delay_ms(10);
	LCD_vSendCharacter('l');
	_delay_ms(10);
	LCD_vSendCharacter('e');
	_delay_ms(10);
	LCD_vSendCharacter('d');
	_delay_ms(10);
	*/
	/**************************************************************/

	/**************************************************************/
	/*
	uint8 String[15]="salma khaled";
	LCD_vSendString (String);
	*/
	/**************************************************************/

	/*LCD_vGotoxy(2,3);
	uint8 String[15]="salma";
	LCD_vSendString (String);*/

	/****************************************************************/

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

	 /*****************************************************************/


	 /*DIO_vSetPinDirection   (PORT_D,2,OUTPUT);
	 DIO_vWritePinValue     (PORT_D,2,HIGH);
	 ISR(INT0_vect);
*/


	/********************* EXTERNAL INTERRUPT *************************/


	//EXT_INT_Init();
//	EXT_INT_SET_CONFIG();



	//DIO_vSetPinDirection(PORT_D,2,INPUTWPULLUP);

/*
DIO_vSetPinDirection   (PORT_D ,2,INPUTWOPULLUP);
//DIO_vSetPinDirection   (PORT_D,3 ,OUTPUT);
DIO_vSetPinDirection   (PORT_C,2,OUTPUT);
while (1)
{

		if (DIO_uReadPinDirection(PORT_D,2) == 1)
		{

			DIO_vTogglePin(PORT_C,2);

		}


}

*/


	/*uint8 res=DIO_uReadPinDirection(PORT_D,2);
	if (res == 1)
	{
		DIO_vSetPinDirection   (PORT_C,7,OUTPUT);
		DIO_vWritePinValue     (PORT_C,7,HIGH);
	}
*/

/*---------------------------------------------------------------*/
	/*
while (1)
{

	APP_vProject ();
}
*/


/*************************************************************************************************/
/*while (1)
		{*/
			/*
			LCD_vInit();
			//LCD_vClear();
			ADC_Init ();
			ADC_Config ();
			ADC_StartConversion ();
			uint16 temp =ADC_GetConvertedValue ();
			uint16 temp2=temp/4;
			LCD_vGotoxy(1,0);
			//uint8 show[2];
			//itoa(temp2,show,10);
			//LCD_vSendString(show);
			while (temp2)
			{
				LCD_vSendCharacter((temp2%10)+48);
				temp2/=10;
			}

			_delay_ms(1000);*/
			/*LCD_vClear();
			LCD_vInit();
			ADC_Init ();
					ADC_Config ();
					ADC_StartConversion ();
					//LCD_vGotoxy(1,0);
					uint16 temp =ADC_GetConvertedValue ();
					uint16 tempt=temp/4;
					 //lcd_gotoxy(1,1);
					// lcd_write_string("TEMP IS :/ ");
					 //lcd_gotoxy(1,2);
					 uint8 result[2];
					 uint8 i=0,j=0;
					 if (tempt<100)
					 {
						 j=2;
					 }
					 else if (tempt>100)
					 {
						 j=3;
					 }
					 for(i=0;i<j;i++)
					 {
						 result[i]=tempt%10;
						 tempt=tempt/10;

					 }*/
					/* for(i=1;i>=0;i--)*/
					/* {
						 LCD_vSendCharacter(result[i]+48);
					 }*/
				/*	 LCD_vSendCharacter(result[1]+48);
					 LCD_vSendCharacter(result[0]+48);


		}*/

/*

DIO_vSetPinDirection(PORT_D , Rx , INPUTWOPULLUP);
DIO_vSetPinDirection(PORT_D , Tx , OUTPUT);
UART_Init();*/
/*
while (1)
{
	UART_TransmitData(0x08);
		//uint8 Dos =UART_ReceivetData();
		//if (Dos==0x08)
		{
			DIO_vSetPinDirection(PORT_C,2,OUTPUT);
			DIO_vWritePinValue(PORT_C,2,HIGH);
		}
}


	return 0;
}
*/
/*ISR (TIMER0_COMP_vect)
{
	Timer_Ticks ++;
}

*/

