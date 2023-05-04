/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef INTERRUPT_H
#define	INTERRUPT_H

#include <xc.h> // include processor files - each processor file is guarded.  


#define GLOBAL_ENABLE GIE
#define INTR_ENABLE0 INT0E
#define INTR_ENABLE1 INT1E
#define INTR_ENABLE2 INT2E


#define INTR_FLAG0 INT0F
#define INTR_FLAG1 INT1F
#define INTR_FLAG2 INT2F



//count keep track of the number in segment display
extern volatile unsigned int count_value ;
//pass = 0 means the display stops and pass=1 display proceeds
extern volatile unsigned int pass ;



//enable interrupt will enable interrupt globally and specific hardware interrupts
void enableinterrupt(void);

//Interrupt Service Routine
void __interrupt () routine();

#endif	

