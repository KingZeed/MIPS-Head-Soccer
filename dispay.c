#include <pic32mx.h>
#include <stdint.h>


#define DISPLAY_VDD PORTFbits.RF6
#define DISPLAY_VBATT PORTFbits.RF5
#define DISPLAY_COMMAND_DATA PORTFbits.RF4
#define DISPLAY_RESET PORTGbits.RG9


#define DISPLAY_VDD_PORT PORTF
#define DISPLAY_VDD_MASK 0x40
#define DISPLAY_VBATT_PORT PORTF
#define DISPLAY_VBATT_MASK 0x20
#define DISPLAY_COMMAND_DATA_PORT PORTF
#define DISPLAY_COMMAND_DATA_MASK 0x10
#define DISPLAY_RESET_PORT PORTG
#define DISPLAY_RESET_MASK 0x200


uint8_t display[32][128];		// Readable for humans
uint8_t oled_display[512];

void delay(int cyc) {
	int i;
	for(i = cyc; i > 0; i--);
}

uint8_t spi_send_recv(uint8_t data) {
	while(!(SPI2STAT & 0x08));
	SPI2BUF = data;
	while(!(SPI2STAT & 0x01));
	return SPI2BUF;
}

void display_init() {	 
	DISPLAY_COMMAND_DATA_PORT &= ~DISPLAY_COMMAND_DATA_MASK; // Clear OLED data/command select
	delay(10);
	DISPLAY_VDD_PORT &= ~DISPLAY_VDD_MASK;					// Clear OLED VDD Enable - Power off display
	delay(1000000);
	
	// Send display off command
	spi_send_recv(0xAE);

	// Reset the display
	DISPLAY_RESET_PORT &= ~DISPLAY_RESET_MASK;
	delay(10);
	DISPLAY_RESET_PORT |= DISPLAY_RESET_MASK;
	delay(10);
	
	// Set pre-charge phase length
	spi_send_recv(0x8D);
	spi_send_recv(0x14);
	
	// Set VCOMH deselect level
	spi_send_recv(0xD9);
	spi_send_recv(0xF1);
	
	// Power on the display
	DISPLAY_VBATT_PORT &= ~DISPLAY_VBATT_MASK;
	delay(10000000);
	
	// Set segment remap and com output scan direction
	spi_send_recv(0xA1);
	spi_send_recv(0xC8);
	
	// Set COM pins hardware configuration
	spi_send_recv(0xDA);
	spi_send_recv(0x20);

	// Turn on the display
	spi_send_recv(0xAF);
}

void display_image(const uint8_t *data) {
	int i, j;
	
	for(i = 0; i < 4; i++) {
		DISPLAY_COMMAND_DATA_PORT &= ~DISPLAY_COMMAND_DATA_MASK;
		spi_send_recv(0x22);
		spi_send_recv(i);
		
		spi_send_recv(0 & 0xF);
		spi_send_recv(0x10 | ((0 >> 4) & 0xF));
		
		DISPLAY_COMMAND_DATA_PORT |= DISPLAY_COMMAND_DATA_MASK;
		
		for(j = 0; j < 128; j++)
			spi_send_recv(~data[i*128 + j]);
	}
}



void translateToOled(){

	int page, column, memory_row;
	uint8_t oled_byte = 0;
	
	for(page = 0; page < 4; page++){

		for(column = 0; column < 128; column++) {
			oled_byte = 0;

			for(memory_row = 0; memory_row < 8; memory_row++){
				if(!display[8 * page + memory_row][column]){
					oled_byte |= (1 << memory_row);
				}
				
			}
			oled_display[page*128 + column] = oled_byte;
		}
		
	}

}

void display_clear() {
    int row, column, i;

	for(row = 0; row < 32; row++) {
		for(column = 0; column < 128; column++) {
		display[row][column] = 0;
		}
	}
	translateToOled();
	display_image(oled_display);
}

void update_display(){
	translateToOled();
	display_image(oled_display);
}



void display_dots() {
	
	display[0][0] = 1;
	display[31][127] = 1;
	display[31][0] = 1;
	display[0][127] = 1;
	
	update_display();
	
}