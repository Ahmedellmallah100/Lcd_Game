#include "../MCAL/Dio/Dio_interface.h"
#include "../HALL/7_Segment/7_segment_inter.h"
#include "../HALL/Lcd/Lcd_interface.h"
#include "../HALL/Led/Led_interface.h"
#include <util/delay.h>

#define line0 0
#define line1 1

int main() {
    // Custom Characters
    u8 playerChar[8] = {
        0b00100,
        0b00100,
        0b01110,
        0b00100,
        0b01010,
        0b00000,
        0b00000,
        0b00000
    };

    u8 ballChar[8] = {
        0b00000,
        0b00000,
        0b00100,
        0b01110,
        0b00000,
        0b00000,
        0b00000,
        0b00000
    };

    u8 laughChar[8] = {
        0b00000,
        0b01010,
        0b00000,
        0b00000,
        0b10001,
        0b01110,
        0b00000,
        0b00000
    };

    u8 cryChar[8] = {
        0b00000,
        0b01010,
        0b00000,
        0b00000,
        0b00000,
        0b01110,
        0b10001,
        0b01010
    };

    u8 score_left = 0;
    u8 score_right = 0;
    u8 playerLeftLine = line0;
    u8 playerRightLine = line0;

    // Init LCD & Custom Characters
    lcd_init();
    lcd_saveCustomChar(0, playerChar); 
    lcd_saveCustomChar(1, ballChar);
    lcd_saveCustomChar(2, laughChar); 
    lcd_saveCustomChar(3, cryChar);   

    // Buttons & Led
    DIO_voidSetPinDirect(PORTD, PIN0, INPUT);  // Right player button
    DIO_voidSetPinValue(PORTD, PIN0, 1);

    DIO_voidSetPinDirect(PORTD, PIN1, INPUT);  // Left player button
    DIO_voidSetPinValue(PORTD, PIN1, 1);

    DIO_voidSetPinDirect(PORTC, PIN0, OUTPUT); // Led
    DIO_voidSetPinValue(PORTC, PIN0, 0);

    while (1) {
        // Draw players
        lcdsend_data_atPosition(playerLeftLine, 0, 0);   // Left player
        lcdsend_data_atPosition(playerRightLine, 15, 0); // Right player

        // Move ball left → right
        for (int i = 1; i < 14; i++) {
            if (i > 11)
                lcdsend_data_atPosition(line1, i, 1); // Ball in Line1
            else
                lcdsend_data_atPosition(line0, i, 1); // Ball in Line0

            _delay_ms(50);

            if (i > 11)
                lcdsend_data_atPosition(line1, i, ' ');
            else
                lcdsend_data_atPosition(line0, i, ' ');
        }

        // Check right player's move
        if (DIO_voidGetPinValue(PORTD, PIN0) == 0) {
            playerRightLine = line1;
            _delay_ms(50);
        }

        // Draw updated right player position
        lcdsend_data_atPosition(playerRightLine, 15, 0);


        // Check if defended
        if (playerRightLine == line1) {
            lcdsend_data_atPosition(line0, 9, 2); // Laugh

        } else {
            score_left++;
            lcdsend_data_atPosition(line0, 9, 3); // Cry

            DIO_voidSetPinValue(PORTC, PIN0, 1);
            _delay_ms(100);
            DIO_voidSetPinValue(PORTC, PIN0, 0);

        }

        // Reset right player to top
        
        lcdsend_data_atPosition(line0, 15, ' '); 
        lcdsend_data_atPosition(line1, 15, ' '); 
        playerRightLine = line0;
        lcdsend_data_atPosition(line0, 15, 0);

        //Clear Emoji
        _delay_ms(50);
        lcdsend_data_atPosition(line0, 9, ' ');

        // Update score
        lcdsend_data_atPosition(line1, 7, score_left + '0');
        lcdsend_data_atPosition(line1, 8, '-');
        lcdsend_data_atPosition(line1, 9, score_right + '0');

        _delay_ms(50);

        // Draw players again
        lcdsend_data_atPosition(playerLeftLine, 0, 0);
        lcdsend_data_atPosition(playerRightLine, 15, 0);

        // Move ball right → left
        for (int i = 14; i > 1; i--) {
            if (i < 4)
                lcdsend_data_atPosition(line1, i, 1);
            else
                lcdsend_data_atPosition(line0, i, 1);

            _delay_ms(50);

            if (i < 4)
                lcdsend_data_atPosition(line1, i, ' ');
            else
                lcdsend_data_atPosition(line0, i, ' ');
        }

        // Check left player's move
        if (DIO_voidGetPinValue(PORTD, PIN1) == 0) {
            playerLeftLine = line1;
            _delay_ms(50);
        }

        // Draw updated left player position
        lcdsend_data_atPosition(playerLeftLine, 0, 0);

        // Check if defended
        if (playerLeftLine == line1) {
            lcdsend_data_atPosition(line0, 7, 2); // Laugh

        } else {
            score_right++;
            lcdsend_data_atPosition(line0, 7, 3); // Cry

            DIO_voidSetPinValue(PORTC, PIN0, 1);
            _delay_ms(100);
            DIO_voidSetPinValue(PORTC, PIN0, 0);
        }

        // Reset left player to top
         lcdsend_data_atPosition(line1, 0, ' '); 
        lcdsend_data_atPosition(line0, 0, ' '); 
        playerLeftLine = line0;
        lcdsend_data_atPosition(line0, 0, 0);

        //Clear emoji  
                _delay_ms(50);
 
        lcdsend_data_atPosition(line0, 7, ' ');

        // Update score
        lcdsend_data_atPosition(line1, 7, score_left + '0');
        lcdsend_data_atPosition(line1, 8, '-');
        lcdsend_data_atPosition(line1, 9, score_right + '0');

        _delay_ms(100);
    }

    return 0;
}
