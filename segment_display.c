/*
 * File:   segment_dsplay.c
 * Author: muham
 *
 * Created on 4 May, 2023, 10:58 AM
 */

#include "segment_display.h"

//------binary pattern for common anode seven segment display------------------
unsigned char single_display[]  =            {0b11000000,0b11111001,0b10100100,
                                              0b10110000,0b10011001,0b10010010,
                                              0b10000010,0b11111000,0b10000000,
                                              0b10010000};
//-----------------------------------------------------------------------------
