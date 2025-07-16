#include <util/delay.h>
#include "../../Library/bit_math.h"
#include "../../Library/std_Bytes.h"
#include "../../MCAL/Dio/Dio_interface.h"
#include "Lcd_config.h"
#include "Lcd_private.h"
#include "Lcd_interface.h"   

void lcd_init(void)
{
    DIO_voidSetPinDirect(RS_PORT, RS_PIN, OUTPUT);
    DIO_voidSetPinDirect(RW_PORT, RW_PIN, OUTPUT);
    DIO_voidSetPinDirect(EN_PORT, EN_PIN, OUTPUT);
    DIO_voidSetPortDirect(DATA_PORT, OUTPUT);

    lcdsend_command(FUNCTION_SET);
    _delay_ms(2);

    lcdsend_command(DISPLAY_CONTROL);
    _delay_ms(2);

    lcdsend_command(DISPLAY_CLEAR);
    _delay_ms(2);

    lcdsend_command(ENTRY_MODE_SET);
}

void lcdsend_command(u8 command)
{
    DIO_voidSetPinValue(RW_PORT, RW_PIN, Low);
    DIO_voidSetPinValue(RS_PORT, RS_PIN, Low);
    DIO_voidSetPortValue(DATA_PORT, command);
    DIO_voidSetPinValue(EN_PORT, EN_PIN, High);
    _delay_ms(1);
    DIO_voidSetPinValue(EN_PORT, EN_PIN, Low);
}

void lcdsend_print_data(u8 Data)
{
    DIO_voidSetPinValue(RW_PORT, RW_PIN, Low);
    DIO_voidSetPinValue(RS_PORT, RS_PIN, High);
    DIO_voidSetPortValue(DATA_PORT, Data);
    DIO_voidSetPinValue(EN_PORT, EN_PIN, High);
    _delay_ms(1);
    DIO_voidSetPinValue(EN_PORT, EN_PIN, Low);
}

void lcdsend_cursor_atPosition(u8 linenum , u8 position)
{
    switch (linenum)
    {
    case 0: lcdsend_command(0x80 + position); break;
    case 1: lcdsend_command(0xC0 + position); break;
    }
}

void lcdsend_data_atPosition(u8 linenum , u8 position , u8 data)
{
    lcdsend_cursor_atPosition(linenum , position);
    lcdsend_print_data(data);
}

void lcd_saveCustomChar(u8 location, u8* pattern)
{
    lcdsend_command(0x40 + (location * 8));
    for (u8 i = 0; i < 8; i++)
    {
        lcdsend_print_data(pattern[i]);
    }
    lcdsend_command(0x80);
}

void LCD_voidWriteString (u8 *Arr ){
    u8 i = 0 ;
    while (Arr[i] != '\0' )
    {
        lcdsend_print_data( Arr[i] );
        i++;
    }

}

void LCD_voidClearDisplay (void)
{
    lcdsend_command ( DISPLAY_CLEAR );
}
