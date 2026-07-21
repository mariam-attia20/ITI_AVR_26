#ifndef BIT_MATH
#define BIT_MATH

#define SET_BIT(reg , bit)   reg = reg |(1<<bit)
#define CLEAR_BIT(reg , bit)  reg = reg & ~(1<< bit)
#define TOOGLE_BIT(reg , bit)  reg = reg ^ (1<<bit)
#define GET_BIT(reg , bit )     reg =  1 & (reg>>bit)
#define ROTATE_BIT_l(reg, bit , size)  reg = (reg<<bit)| (reg <<(size-bit))
#define ROTATE_BIT_R(reg , bit , size)  reg = (reg >> bit) | (reg << (size-bit)) 

#endif