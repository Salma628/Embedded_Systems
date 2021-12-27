/*
 * External_Interrupt_Interface.h
 *
 *  Created on: Aug 28, 2019
 *      Author: Masria For PCs
 */

#ifndef MCAL_EXTERNAL_INTERRUPT_EXTERNAL_INTERRUPT_INTERFACE_H_
#define MCAL_EXTERNAL_INTERRUPT_EXTERNAL_INTERRUPT_INTERFACE_H_
#include "../../LIB/types.h"
/************* Modes ***********************/



#define LOW_LEVEL_MODE  0
#define FALLING_EDGE_MODE  1
#define RISING_EDGE_MODE   2
#define FALLING_AND_RISING_EDGE_MODE  3


typedef struct
{
uint8 Enable_INT0_Interrupt;
uint8 Enable_INT1_Interrupt;
uint8 Enable_INT2_Interrupt;
uint8 INT0_Triggering_Mode;
uint8 INT1_Triggering_Mode;
uint8 INT2_Triggering_Mode;

}EXT_Int_Conf;

/*--------------------------------------------*/

/************** PINS OF REG ***************/

//REG MCUCR (PINS)
#define ISC00 0
#define ISC01 1
#define ISC10 2
#define ISC11 3

//REG MCUCSR (PINS)
#define ISC2  6



/********** Enable Ext Interrupts ***********/


//REG GICR (PINS)
#define ENABLE_INT0 6
#define ENABLE_INT1 7
#define ENABLE_INT2 5
#define DISABLE_INT 0

/******************** PINS *****************************/
#define Pin_Int0 2
#define Pin_Int1 3
#define Pin_Int2 2




/*********** External_Interrupt APIS ****************/


void EXT_INT_Init(void);
void EXT_INT_SET_CONFIG(void);




#endif /* MCAL_EXTERNAL_INTERRUPT_EXTERNAL_INTERRUPT_INTERFACE_H_ */
