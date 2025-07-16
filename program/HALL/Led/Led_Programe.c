#include "../../Library/bit_math.h"
#include "../../Library/std_Bytes.h"
#include "../../MCAL/Dio/Dio_interface.h"
#include "Led_interface.h"

#define ON  1
#define OFF 0

void LED_voidSetPortValue(u8 PORT_number, u8 stat)
{
    if (PORT_number <= PORTD)
    {
        if (stat == ON || stat == OFF)
        {
            DIO_voidSetPortValue(PORT_number, stat ? 0xFF : 0x00);
        }
    }
}

void LED_voidSetPinValue(u8 PORT_number, u8 PIN_number, u8 stat)
{
    if (PORT_number <= PORTD && PIN_number <= PIN7)
    {
        if (stat == ON || stat == OFF)
        {
            DIO_voidSetPinValue(PORT_number, PIN_number, stat);
        }
    }
}

u8 LED_voidGetPortValue(u8 PORT_number)
{
    if (PORT_number <= PORTD)
    {
        return DIO_voidGetPortValue(PORT_number);
    }
    return 0;
}

u8 LED_voidGetPinValue(u8 PORT_number, u8 PIN_number)
{
    if (PORT_number <= PORTD && PIN_number <= PIN7)
    {
        return DIO_voidGetPinValue(PORT_number, PIN_number);
    }
    return 0;
}
