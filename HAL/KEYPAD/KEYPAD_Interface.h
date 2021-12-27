

/******************** PORTS ***********************/
#define USED_PORT PORT_C
/***************************************************/


/******************** ROWS *************************/
#define ROW1 0
#define ROW2 1
#define ROW3 2
#define ROW4 3
/****************************************************/

/********************* colums ***********************/
#define COL1 4
#define COL2 5
#define COL3 6
#define COL4 3
/*****************************************************/


/******************** FUNCTION ***********************/
extern void  KEYPAD_vInit ();
extern uint8 KEYPAD_uGetKey();
//extern void KEYPAD_vDebouncing (uint8 state);
