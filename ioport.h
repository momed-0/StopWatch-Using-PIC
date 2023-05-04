/* 
 * File: ioport.h   
 * Author: Mohammed
 * Comments: specifies the input and output port used in Microcontroller
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef IOPORT_H
#define	IOPORT_H

#include <xc.h> // include processor files - each processor file is guarded.  


#define INPUT_TRIS TRISB //INTERRUPT PORTB
#define OUTPUT_TRIS TRISC
#define OUTPUT_PORT PORTC
#define INPUT_BUTTON_TRIS TRISA0 //PUSH BUTTON TO START THE PROGRAM


//setioport set the corresponding ports as input and output]
void setioport(void);

#endif	/* XC_HEADER_TEMPLATE_H */

