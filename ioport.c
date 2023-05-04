/*
 * File:   ioport.c
 * Author: Mohammed
 *
 * Created on 4 May, 2023, 11:35 AM
 */


#include "ioport.h"


void setioport()
{
    //PORTC as output -seven segment display
    OUTPUT_TRIS = 0;
    INPUT_TRIS = 0xFF;
   
}

