

#ifndef BIT_MATH_H
#define BIT_MATH_H

#define SET_BIT(reg , bit)     reg |= (1<<bit)
#define Clear_BIT(reg , bit)   reg &= ~(1<<bit)
#define Toggle_BIT(reg , bit)  reg ^= (1<<bit)
#define Get_Bit(reg , bit)      reg &  (1<<bit)




#endif