#include "../../Library/bit_math.h"
#include "../../Library/std_Bytes.h"

#include "../../MCAL/Dio/Dio_interface.h"
#include "7_segment_private.h"

#include "7_segment_inter.h"


u8 Common_cathode_Arr[10]= {ZERO,ONE,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE} ;

void SevenSegmentPrint (s8 port_number ,s8 polarity , s8 value){
  if (value < 0 || value > 9) return;

else{
   switch (polarity){
   case COMMON_CATHODE :
   switch(port_number)
        {
        case PORTA:      DIO_voidSetPortValue(PORTA, Common_cathode_Arr[value] );           break;
        case PORTB:      DIO_voidSetPortValue(PORTB, Common_cathode_Arr[value] );          break;
        case PORTC:      DIO_voidSetPortValue(PORTC, Common_cathode_Arr[value] );          break;
        case PORTD:      DIO_voidSetPortValue(PORTD, Common_cathode_Arr[value] );          break;
        default:                                     break;

        }
        break;
        case COMMON_ANODE :
          switch(port_number)
        {
       case PORTA:       DIO_voidSetPortValue(PORTA, ~Common_cathode_Arr[value] );           break;
        case PORTB:      DIO_voidSetPortValue(PORTB, ~Common_cathode_Arr[value] );          break;
        case PORTC:      DIO_voidSetPortValue(PORTC, ~Common_cathode_Arr[value] );          break;
        case PORTD:      DIO_voidSetPortValue(PORTD, ~Common_cathode_Arr[value] );          break;
        default:     break;                                 

        }
        break;
        }
      }

}