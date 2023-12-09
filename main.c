#include <pic32mx.h>
#include <stdint.h>
#include "project.h"

void setUp(){
/* Set up peripheral bus clock */
	// OSCCON &= ~0x180000;
	// OSCCON |= 0x080000;
	
	/* Set up output pins */
	AD1PCFG = 0xFFFF;
	ODCE = 0x0;
	TRISECLR = 0xFF;
	PORTE = 0x0;
	
	/* Output pins for display signals */
	PORTF = 0xFFFF;
	PORTG = (1 << 9);
	ODCF = 0x0;
	ODCG = 0x0;
	TRISFCLR = 0x70;
	TRISGCLR = 0x200;

	TRISE &= ~0xff;
	
	/* Set up input pins */
	TRISDSET = (1 << 8);
	TRISFSET = (1 << 1);

	/* Set button & switches input pins */
	TRISF |= (0b1 << 1); // button1
	TRISD |= (0b111 << 5); // button2-4

	TRISD |= (0b1111 << 8); // sw1-4

	/* Set up SPI as master */
	SPI2CON = 0;
	SPI2BRG = 4;
	
	/* Clear SPIROV*/
	SPI2STATCLR &= ~0x40;
	/* Set CKP = 1, MSTEN = 1; */
    SPI2CON |= 0x60;
	
	/* Turn on SPI */
	SPI2CONSET = 0x8000;
	
}

int main() {

	setUp();
	display_init();
	setup_lists();
	display_clear();
	startscreen();
	
	return;
}