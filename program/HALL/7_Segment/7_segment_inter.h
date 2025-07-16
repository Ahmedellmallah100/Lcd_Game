#include "../../Library/bit_math.h"
#include "../../Library/std_Bytes.h"

#include "../../MCAL/Dio/Dio_interface.h"



#define COMMON_ANODE               0
#define COMMON_CATHODE              1

void SevenSegmentPrint (s8 port_number ,s8 polarity , s8 value);
