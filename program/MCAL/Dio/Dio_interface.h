
#include "../../Library/std_Bytes.h"
#include "private.h"


#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H


/* Macros as PortNumber options */
#define PORTA                    0    
#define PORTB                    1     
#define PORTC                    2    
#define PORTD                    3

/** Macros as PinNumber options */
#define PIN0                     0    
#define PIN1                     1     
#define PIN2                     2    
#define PIN3                     3
#define PIN4                     4    
#define PIN5                     5     
#define PIN6                     6    
#define PIN7                     7

#define ON   1
#define off  0
#define High 1
#define Low  0

#define INPUT  0
#define OUTPUT 1



#endif

void DIO_voidSetPinDirect(u8 PORT_number, u8 PIN_number, u8 state);
void DIO_voidSetPortDirect(u8 PORT_number, u8 state);
void DIO_voidSetPinValue(u8 PORT_number, u8 PIN_number, u8 state);
void DIO_voidSetPortValue(u8 PORT_number ,u8 value);
u8 DIO_voidGetPinValue(u8 PORT_number, u8 PIN_number);
u8 DIO_voidGetPortValue(u8 PORT_number);
void DIO_voidConfig_Pull_Up_Port (u8 Port_number, u8 PullUpStatus );
void DIO_voidConfig_Pull_Up_Pin (u8 Port_number,u8 Pin_number,u8 PullUpStatus);


