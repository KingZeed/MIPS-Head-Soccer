/* time4io.c

   This file written 2023 by M Zellman
*/
#include <stdint.h>   /* Declarations of uint_32 and the like */
#include <pic32mx.h>  /* Declarations of system-specific addresses etc */
#include "mipslab.h"  /* Declatations for these labs */

int getsw(void) {
    int ret = PORTD;
    ret = ret >> 8;
    ret &= 0xf;
    return ret;
}

int getbtns(void) {
    int ret = PORTD;
    ret = ret >> 5;
    ret &= 0b111;
    return ret;
}