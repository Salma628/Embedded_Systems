#ifndef _calc_bits_H
#define _calc_bits_H
#define set_bit(reg , bit)    reg|=(1<<bit)  /*shift left*/

#define clear_bit(reg,bit)    reg&=~(1<<bit)  /*ممكن اعمل and مع الزيرو علطول */

#define toggle_bit(reg,bit)   reg ^=(1<<bit)

#define get_bit(reg,bit)    ((reg & (1<<bit)) >> bit) /* عشان كده عملت. .كد ه هرجع 1 او 0 shift right*/
#endif


   

