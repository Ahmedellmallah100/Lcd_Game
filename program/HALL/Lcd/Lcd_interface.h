#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H

#include "../../Library/bit_math.h"
#include "../../Library/std_Bytes.h"

void lcdsend_command(u8 command);
void lcdsend_print_data(u8 Data);
void lcdsend_cursor_atPosition(u8 linenum , u8 position);
void lcdsend_data_atPosition(u8 linenum , u8 position , u8 data);
void lcd_saveCustomChar(u8 location, u8* pattern);
void lcd_init(void);
void LCD_voidWriteString (u8 *Arr );
void LCD_voidClearDisplay (void);
#endif


