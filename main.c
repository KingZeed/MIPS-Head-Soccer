#include <pic32mx.h>
#include <stdint.h>
#include "project.h"


void setUp(){
/* Set up peripheral bus clock */
	// OSCCON &= ~0x180000;
	// OSCCON |= 0x080000;
	
	/* Set up output pins */
	// AD1PCFG = 0xFFFF;
	// ODCE = 0x0;
	// TRISECLR = 0xFF;
	// PORTE = 0x0;
	
	/* Output pins for display signals */
	PORTF = 0xFFFF;
	PORTG = (1 << 9);
	ODCF = 0x0;
	ODCG = 0x0;
	TRISFCLR = 0x70;
	TRISGCLR = 0x200;
	
	/* Set up input pins */
	// TRISDSET = (1 << 8);
	// TRISFSET = (1 << 1);


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
	// setup_lists();
	// display_clear();
	// startscreen();
	while (1) {
		display_clear();
		draw_left_goal();
		draw_right_goal();
		draw_ball(ball.pos_x, ball.pos_y);
		draw_player1(p1.pos_x, p1.pos_y);
		draw_player2(p2.pos_x, p2.pos_y);
		check_movement();
		display_update();
		delay(100000);
	}
	
	
	return;
}