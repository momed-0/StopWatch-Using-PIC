/*
 * File:   main.c
 * Author: mohammed
 *
 * 
 * A simple stopwatch implemented in PIC18F452 using 7 seven segment display and
 * hardware interrupts . INT0 INT1 and INT2 hardware interrupts are used for 
 * RESET PAUSE RESUME respectively
 * 
 * Created on 1 May, 2023, 3:34 PM
 */
#include <xc.h>
#include "config.h"
#include "segment_display.h"
#include "interrupt.h"
#include "ioport.h"


//defining CRYSTAL FREQUENCY for __delay_ms()
#define _XTAL_FREQ 4000000



//----------------------------------------------------------------------------

void main(void)
{
    enableinterrupt();
    setioport();
    
    while(1)
    {
        if(pass)//run the timer as pass is high
        {
            if(count_value >9) count_value = 0; //if greater than 9 reset to zero
            //print the count to output port
            OUTPUT_PORT = single_display[(unsigned char) count_value ++];
            //provide a delay of 1s
            __delay_ms(1000); 
        }
        
    }
    return;
}


