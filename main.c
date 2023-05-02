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



//defining CRYSTAL FREQUENCY for __delay_ms()
#define _XTAL_FREQ 4000000

//------binary pattern for common anode seven segment display------------------
unsigned char binary_pattern[]={0b11000000,0b11111001,0b10100100,
                               0b10110000,0b10011001,0b10010010,
                               0b10000010,0b11111000,0b10000000,
                                0b10010000};
//-----------------------------------------------------------------------------



//----------------------------------------------------------------------------
//count keep track of the number in segment display
volatile unsigned int count = 0;
//pass = 0 means the display stops and pass=1 display proceeds
volatile unsigned int pass = 1;

//----------------------------------------------------------------------------
//enable intrrupt will enable interrupt globally and specific hardware interrupts
void enableinterrupt(void);
//setioport set the corresponding ports as input and output]
void setioport(void);

//----------------------------------------------------------------------------

void main(void)
{
    enableinterrupt();
    setioport();
    
    while(1)
    {
        if(pass)
        {
            if(count>9) count = 0; //if greater than 9 reset to zero
            PORTC = binary_pattern[(unsigned char) count++];
            __delay_ms(1000); //provide a delay of 1s
        }
    }
    return;
}

void enableinterrupt()
{
    //------GIE AND INTOE,INT1E,INT2E are enabled
    GIE = 1;
    INT0E = 1;
    INT1E = 1;
    INT2E = 1;
}

void setioport()
{
    //PORTC as output -seven segment display
    TRISC = 0;
    TRISB = 0xFF;
}

//------------interrupt service routine --------------------
void __interrupt () routine()
{
    //if INT0F is high means display should be resetted
    if(INT0E && INT0F)
    {
        count = 0;
        pass  = 1;
        INT0F = 0;
    }
    //if INT1F is high means pause the display
    if(INT1E && INT1F)
    {
        pass = 0;
        INT1F = 0;
    }
    //INT2F is high means resume the display
    if(INT2E && INT2F)
    {
        pass = 1;
        INT2F = 0;
    }
    return;
}
