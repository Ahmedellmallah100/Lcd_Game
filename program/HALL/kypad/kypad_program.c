#include <util/delay.h>
#include "../../Library/bit_math.h"
#include "../../Library/std_Bytes.h"
#include "../../MCAL/Dio/Dio_interface.h"
#include "kypad_config.h"
u8 KPAD_ColumnsArr[KPAD_COLUMNS_NUM] = { KPAD_C0_PIN , KPAD_C1_PIN , KPAD_C2_PIN , KPAD_C3_PIN };
u8 KPAD_RowsArr[KPAD_ROWS_NUM] = { KPAD_R0_PIN , KPAD_R1_PIN , KPAD_R2_PIN , KPAD_R3_PIN };
u8 KPAD_KeysArr[KPAD_ROWS_NUM][KPAD_COLUMNS_NUM] = KPAD_KEYS ;



void KPAD_voidInit (void){
   /* Configer The Direction of Coloums Pins as Output */
    DIO_voidSetPinDirect (KPAD_PORT,KPAD_C0_PIN,OUTPUT);
    DIO_voidSetPinDirect (KPAD_PORT,KPAD_C1_PIN,OUTPUT);
    DIO_voidSetPinDirect (KPAD_PORT,KPAD_C2_PIN,OUTPUT);
    DIO_voidSetPinDirect (KPAD_PORT,KPAD_C3_PIN,OUTPUT);

    /* Configer The Direction of Rows Pins as Input */
    DIO_voidSetPinDirect (KPAD_PORT,KPAD_R0_PIN,INPUT);
    DIO_voidSetPinDirect (KPAD_PORT,KPAD_R1_PIN,INPUT);
    DIO_voidSetPinDirect (KPAD_PORT,KPAD_R2_PIN,INPUT);
    DIO_voidSetPinDirect (KPAD_PORT,KPAD_R3_PIN,INPUT);

    /* Activate Pull-Up Res in Pins of Rows */
    // on == 1   off==0
    DIO_voidConfig_Pull_Up_Pin (KPAD_PORT,KPAD_R0_PIN,ON);
    DIO_voidConfig_Pull_Up_Pin (KPAD_PORT,KPAD_R1_PIN,ON);
    DIO_voidConfig_Pull_Up_Pin (KPAD_PORT,KPAD_R2_PIN,ON);
    DIO_voidConfig_Pull_Up_Pin (KPAD_PORT,KPAD_R3_PIN,ON);

    /* Deactivate Coloum Pins  */      
    DIO_voidSetPinValue (KPAD_PORT,KPAD_C0_PIN,High);
    DIO_voidSetPinValue (KPAD_PORT,KPAD_C1_PIN,High);
    DIO_voidSetPinValue (KPAD_PORT,KPAD_C2_PIN,High);
    DIO_voidSetPinValue (KPAD_PORT,KPAD_C3_PIN,High); 


}

u8 KPAD_u8GetPressedKey (void){
    u8 Local_ColumnsIter;
    u8 Local_RowsIter;
    u8 Local_PinValue;

    for (Local_ColumnsIter = 0; Local_ColumnsIter < KPAD_COLUMNS_NUM; Local_ColumnsIter++) {
        DIO_voidSetPinValue(KPAD_PORT, KPAD_ColumnsArr[Local_ColumnsIter], Low);

        for (Local_RowsIter = 0; Local_RowsIter < KPAD_ROWS_NUM; Local_RowsIter++) {
            Local_PinValue = DIO_voidGetPinValue(KPAD_PORT, KPAD_RowsArr[Local_RowsIter]);

            if (Local_PinValue == 0) {
                while (DIO_voidGetPinValue(KPAD_PORT, KPAD_RowsArr[Local_RowsIter]) == 0);
                _delay_ms(20);
                DIO_voidSetPinValue(KPAD_PORT, KPAD_ColumnsArr[Local_ColumnsIter], High);

                return KPAD_KeysArr[Local_RowsIter][Local_ColumnsIter];
            }
        }

        DIO_voidSetPinValue(KPAD_PORT, KPAD_ColumnsArr[Local_ColumnsIter], High);
    }

    return 0xff ;
}

