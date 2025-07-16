#ifndef KYPAD_CONFIG_H
#define KYPAD_CONFIG_H

#define  KPAD_PORT             PORTC
 
#define  KPAD_C0_PIN           PIN4
#define  KPAD_C1_PIN           PIN5
#define  KPAD_C2_PIN           PIN6
#define  KPAD_C3_PIN           PIN7

#define  KPAD_R0_PIN           PIN0
#define  KPAD_R1_PIN           PIN1
#define  KPAD_R2_PIN           PIN2
#define  KPAD_R3_PIN           PIN3

#define  KPAD_COLUMNS_NUM         4
#define  KPAD_ROWS_NUM            4

#define KPAD_KEYS {            \
    {'7','8','9','/'},         \
    {'4','5','6','*'},         \
    {'1','2','3','-'},         \
    {'#','0','=','+'}          \
}

#endif 