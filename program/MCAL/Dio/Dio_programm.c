
#include "DiO_interface.h"
#include "private.h"
#include "../../Library/bit_math.h"
#include "../../Library/std_Bytes.h"

void DIO_voidSetPinDirect(u8 PORT_number, u8 PIN_number, u8 state)
{

    switch (state)
    {
    case OUTPUT:
        switch (PORT_number)
        {
        case PORTA:      SET_BIT(DDRA_REG , PIN_number);           break;
        case PORTB:      SET_BIT(DDRB_REG, PIN_number);           break;
        case PORTC:      SET_BIT(DDRC_REG, PIN_number);           break;
        case PORTD:      SET_BIT(DDRD_REG, PIN_number);           break;
        default:                                                   break;
        }
        break;

    case INPUT:
        switch (PORT_number)
        {
        case PORTA:      Clear_BIT(DDRA_REG , PIN_number);           break;
        case PORTB:      Clear_BIT(DDRB_REG , PIN_number);           break;
        case PORTC:      Clear_BIT(DDRC_REG , PIN_number);           break;
        case PORTD:      Clear_BIT(DDRD_REG , PIN_number);           break;
        default:                                                     break;

        }
        break;
    }
}


/*********************************************************** */




void DIO_voidSetPortDirect(u8 PORT_number, u8 state)
{

    switch (state)
    {
    case INPUT:
        switch (PORT_number)
        {
        case PORTA:     DDRA_REG =0x00;            break;
        case PORTB:     DDRB_REG =0x00;            break;
        case PORTC:     DDRC_REG =0x00;;           break;
        case PORTD:     DDRD_REG =0x00;            break;
        default: break;
        }
        break;

    case OUTPUT:
        switch (PORT_number)
        {
        case PORTA:     DDRA_REG =0xff;             break;
        case PORTB:     DDRB_REG =0xff;            break;
        case PORTC:     DDRC_REG =0xff;;           break;
        case PORTD:     DDRD_REG =0xff;            break;
        default:                                   break;

        }
        break;
    }
}

/*********************************************************** */
void DIO_voidSetPinValue(u8 PORT_number, u8 PIN_number, u8 state)
{

    switch (state)
    {
    case High:
        switch (PORT_number)
        {
        case PORTA:      SET_BIT(PORTA_REG, PIN_number);           break;
        case PORTB:      SET_BIT(PORTB_REG, PIN_number);           break;
        case PORTC:      SET_BIT(PORTC_REG, PIN_number);           break;
        case PORTD:      SET_BIT(PORTD_REG, PIN_number);           break;
        default: break;
        }
        break;

    case Low:
        switch (PORT_number)
        {
        case PORTA:      Clear_BIT(PORTA_REG, PIN_number);           break;
        case PORTB:      Clear_BIT(PORTB_REG, PIN_number);           break;
        case PORTC:      Clear_BIT(PORTC_REG, PIN_number);           break;
        case PORTD:      Clear_BIT(PORTD_REG, PIN_number);           break;
        default:                                                     break;

        }
                break;

    }
}


/*********************************************************** */

void DIO_voidSetPortValue(u8 PORT_number ,u8 value)
{

    
        switch (PORT_number)
        {
        case PORTA:     PORTA_REG=value;            break;
        case PORTB:     PORTB_REG=value;            break;
        case PORTC:     PORTC_REG=value;;           break;
        case PORTD:     PORTD_REG=value;            break;
        default: break;
        }

  
        
} 

/*********************************************************** */

u8 DIO_voidGetPinValue(u8 PORT_number, u8 PIN_number)
{

 
        switch (PORT_number)
        {
        case PORTA:     return Get_Bit(PINA_REG, PIN_number);                break;
        case PORTB:     return Get_Bit(PINB_REG, PIN_number);                break;
        case PORTC:     return Get_Bit(PINC_REG, PIN_number);                break;
        case PORTD:     return Get_Bit(PIND_REG, PIN_number);                break;
        default:        return 0;                                               break;
         


        }

   
}

/*********************************************************** */


u8 DIO_voidGetPortValue(u8 PORT_number)
{
    switch (PORT_number)
    {
    case PORTA: return PORTA_REG;
    case PORTB: return PORTB_REG;
    case PORTC: return PORTC_REG;
    case PORTD: return PORTD_REG;
    default:    return 0;
    }
}


void DIO_voidConfig_Pull_Up_Port (u8 Port_number, u8 PullUpStatus ){

    if ( Port_number > PORTD )
    {
        
    }
    else
    {
       switch(PullUpStatus)
       {
            case ON :  DIO_voidSetPortValue (Port_number, High); break;
            case off:  DIO_voidSetPortValue (Port_number, Low);  break;
            default :                                                    break;
       }
    } 
}


void DIO_voidConfig_Pull_Up_Pin (u8 Port_number,u8 Pin_number,u8 PullUpStatus){
    if ( Port_number > PORTD || Pin_number > PIN7 )
    {
        
    }
    else
    {
       switch(PullUpStatus)
       {
            case ON :  DIO_voidSetPinValue (Port_number ,Pin_number, High);  break;
            case off:DIO_voidSetPinValue (Port_number ,Pin_number, Low);   break;
            default :                                                    break;
       }
    } 


}



   



