/* mipslabwork.c

   This file written 2015 by F Lundevall
   Updated 2017-04-21 by F Lundevall

   This file should be changed by YOU! So you must
   add comment(s) here with your name(s) and date(s):

   This file modified 2023-09-27 by M Zellman

   For copyright and licensing, see file COPYING */

#include <stdint.h>   /* Declarations of uint_32 and the like */
#include <pic32mx.h>  /* Declarations of system-specific addresses etc */
#include "mipslab.h"  /* Declatations for these labs */

int mytime = 0x5957;

char textstring[] = "text, more text, and even more text!";

/* Interrupt Service Routine */
void user_isr( void )
{
  return;
}

/* Lab-specific initialization goes here */
void labinit( void ) {
	volatile int* tris_e = 0xbf886100;
  	*tris_e &= ~0xff;
  
  	TRISD |= (0b1111111 << 5);
  
  	return;
}

/* This function is called repetitively from the main program */
void labwork( void )
{
	delay( 1000 );
	time2string( textstring, mytime );
	display_string( 3, textstring );
	display_update();
	tick( &mytime );
	volatile int* port_e = 0xbf886110;
	(*port_e)++; 
	display_image(96, icon);
	int btns = getbtns();
	if (btns & 0b001) { // BTN 2
		int sw = getsw() % 6;
		sw = sw << 4;
		int newtime = mytime & 0xff0f | sw;
		mytime = newtime;
	}
	if (btns & 0b010) { // BTN 3
		int sw = getsw() % 10;
		sw = sw << 8;
		int newtime = mytime & 0xf0ff | sw;
		mytime = newtime;
	}
	if (btns & 0b100) { // BTN 4
		int sw = getsw() % 6;
		sw = sw << 12;
		int newtime = mytime & 0x0fff | sw;
		mytime = newtime;
	}
}
