/*
 * Timer1_Interface.h
 *
 *  Created on: Sep 7, 2019
 *      Author: Masria For PCs
 */

#ifndef MCAL_TIMER1_TIMER1_INTERFACE_H_
#define MCAL_TIMER1_TIMER1_INTERFACE_H_
#include "../../LIB/types.h"

/******************** structure *********************/

typedef struct
{
	uint8 mode_inv ;

}TIMER1_CONFIG ;


#define PWM_INV              1
#define PWM_NONINV           2
#define PHASE_CORRECT_INV    3
#define PHASE_CORRECT_NONINV 4
/******************** motors pins ******************/

#define MOTOR1_PIN1 0
#define MOTOR1_PIN2 1
#define MOTOR2_PIN1 2
#define MOTOR2_PIN2 3


/********************* REG TIFR  ******************/
#define TOV1  2
#define OCF1B 3
#define OCF1A 4
#define ICF1  5  //INPUT CAPTURE FLAG
/**************************************************/

/****************  TCCR1A  **************************/
#define WGM10  0
#define WGM11  1
#define COM1B0 4
#define COM1B1 5
#define COM1A0 6
#define COM1A1 7

/***************  TCCR1B *********************/
#define WGM12  3
#define WGM13  4
/********************************************/


/***************  APIS ************************/
void PMW_Init ();
void PWM_Generate(uint8 DutyCycle,uint32 Top_Value);

#endif /* MCAL_TIMER1_TIMER1_INTERFACE_H_ */
