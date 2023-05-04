/*
 * File:   interrupt.c
 * Author: Mohammed
 *
 * Created on 4 May, 2023, 11:15 AM
 */
#include "interrupt.h"



volatile unsigned int count_value = 0;
volatile unsigned int pass = 1;

void enableinterrupt()
{
    //------GIE AND INTOE,INT1E,INT2E are enabled
    GLOBAL_ENABLE = 1;
    INTR_ENABLE0 = 1;
    INTR_ENABLE1 = 1;
    INTR_ENABLE2 = 1;
}


//------------interrupt service routine --------------------
void __interrupt () routine()
{
    //if INT0F is high means display should be resetted
    if(INTR_ENABLE0 && INTR_FLAG0)
    {
       count_value = 0;
        pass  = 1;
        INTR_FLAG0 = 0;
    }
    //if INT1F is high means pause the display
    if(INTR_ENABLE1 && INTR_FLAG1)
    {
        pass = 0;
        INTR_FLAG1 = 0;
    }
    //INT2F is high means resume the display
    if(INTR_ENABLE2 && INTR_FLAG2)
    {
        pass = 1;
        INTR_FLAG2 = 0;
    }
    return;
}

