#ifndef LED_INTERFACE_H
#define LED_INTERFACE_H

#include "../../Library/std_Bytes.h"

void LED_voidSetPinValue(u8 PORT_number ,u8 PIN_number , u8 stat);
void LED_voidSetPortValue(u8 PORT_number, u8 state);
u8   LED_voidGetPinValue(u8 PORT_number, u8 PIN_number);
u8   LED_voidGetPortValue(u8 PORT_number);

#endif
