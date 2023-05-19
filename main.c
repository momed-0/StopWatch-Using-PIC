/*
 * File:   main.c
 * Author: mohammed
 *
 * 
 * A simple stopwatch implemented in PIC18F452 using 7 seven segment display and
 * hardware interrupts . INT0 INT1 and INT2 hardware interrupts are used for 
 * RESET PAUSE RESUME respectively which is connected to PUSH BUTTONS .
 * By default INT0 has the high priority input and all other are low priority 
 * by default. Hence INT0 which is used for reset button is set to high priority 
 * which will ensure that in the event of multiple interrupts happening it will
 * be reset first
 * It uses TIMER for the delay
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
    
    //set timer0 control register to Prescaler of 256,16bit,Internal Clock source
    T0CON = 0b00000111;

    while(1)
    {
        if(pass)//run the timer as pass is high
        {
            if(count_value >9) count_value = 0; //if greater than 9 reset to zero
            //print the count to output port
            OUTPUT_PORT = single_display[(unsigned char) count_value ++];
            
            //-------------TMR0 loaded with F0BD which will provide a approximate
            //-------------delay of 1s with prescaler of 256 and using 4MHz clock
            TMR0H = 0xF0;
            TMR0L = 0xBD;
           //---------------------------------------------
            
            TMR0IF = 0b0;  //cleared the Timer 0 interrupt flag
           TMR0ON = 0b1;   //Timer0 is started
           
           
            while (!TMR0IF);// Wait for Timer0 to roll off
            TMR0ON = 0b0; //turn off the timer 0 after the delay;
        }
        
    }
    return;
}


