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

char textbuffer[4][16];
uint8_t display[32][128];		// Readable for humans
uint8_t oled_display[512];

const uint8_t const icon[] = {
	255, 255, 255, 255, 255, 255, 127, 187,
	68, 95, 170, 93, 163, 215, 175, 95,
	175, 95, 175, 95, 223, 111, 175, 247,
	59, 237, 242, 254, 171, 254, 1, 255,
	255, 255, 15, 211, 109, 58, 253, 8,
	178, 77, 58, 199, 122, 197, 242, 173,
	242, 237, 186, 215, 40, 215, 41, 214,
	35, 175, 91, 212, 63, 234, 149, 111,
	171, 84, 253, 252, 254, 253, 126, 184,
	195, 52, 201, 22, 225, 27, 196, 19,
	165, 74, 36, 146, 72, 162, 85, 8,
	226, 25, 166, 80, 167, 216, 167, 88,
	106, 149, 161, 95, 135, 91, 175, 87,
	142, 123, 134, 127, 134, 121, 134, 121,
	132, 59, 192, 27, 164, 74, 177, 70,
	184, 69, 186, 69, 254, 80, 175, 217,
};

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

void display_update() {
	int i, j, k;
	int c;
	
	// Loop through 4 sections
	for(i = 0; i < 4; i++) {
		// Set display to command mode
		DISPLAY_COMMAND_DATA_PORT &= ~DISPLAY_COMMAND_DATA_MASK;
		
		// Send update command for a specific section
		spi_send_recv(0x22);
		spi_send_recv(i);
		
		// Set column address range
		spi_send_recv(0x0);
		spi_send_recv(0x10);


		
		// Set display to data mode
		DISPLAY_COMMAND_DATA_PORT |= DISPLAY_COMMAND_DATA_MASK;
	}
}

void display_image(int x, const uint8_t *data) {
	int i, j;
	
	for(i = 0; i < 4; i++) {
		DISPLAY_COMMAND_DATA_PORT &= ~DISPLAY_COMMAND_DATA_MASK;
		spi_send_recv(0x22);
		spi_send_recv(i);
		
		spi_send_recv(x & 0xF);
		spi_send_recv(0x10 | ((x >> 4) & 0xF));
		
		DISPLAY_COMMAND_DATA_PORT |= DISPLAY_COMMAND_DATA_MASK;
		
		for(j = 0; j < 128; j++)
			spi_send_recv(~data[i*128 + j]);
	}
}
/*This function translates the display array to oled_display array. 
It converts an x and y coordinate system into a readable array for the computer.*/
void translateToImage() {
  int page, column, row, c, k;
  uint8_t powerOfTwo = 1;
  uint8_t oledNumber = 0;
  int survivalMode = 0;

  for(page = 0; page < 4; page++) {
    for(column = 0; column < 128; column++) {
      powerOfTwo = 1;
      oledNumber = 0;

      for(row = 0; row < 8; row++) {
        if(display[8 * page + row][column]) {
          oledNumber |= powerOfTwo;
        }
        powerOfTwo <<= 1;
      }
      oled_display[column + page * 128] = oledNumber;
    }
  }
}

void display_clear() {
    int row, column, i;

	for(row = 0; row < 32; row++) {
		for(column = 0; column < 128; column++) {
		display[row][column] = 255;
		}
	}
	translateToImage();
	display_image(0, oled_display);
	
}

void display_dots() {
	uint8_t dot_color = 0;
	display[0][0] = dot_color;
	display[0][32] = dot_color;
	display[0][64] = dot_color;
	display[0][96] = dot_color;
	display[16][0] = dot_color;
	display[16][32] = dot_color;
	display[16][64] = dot_color;
	display[16][96] = dot_color;
	
	
	
	translateToImage();
	display_image(0, oled_display);
}

void display_rect(int pos) {
	display[1][1+pos] = 0;
	display[1][2+pos] = 0;
	display[1][3+pos] = 0;
	display[1][4+pos] = 0;
	display[2][1+pos] = 0;
	display[2][2+pos] = 0;
	display[2][3+pos] = 0;
	display[2][4+pos] = 0;
	display[3][1+pos] = 0;
	display[3][2+pos] = 0;
	display[3][3+pos] = 0;
	display[3][4+pos] = 0;
	display[4][1+pos] = 0;
	display[4][2+pos] = 0;
	display[4][3+pos] = 0;
	display[4][4+pos] = 0;

	translateToImage();
	display_image(0, oled_display);
}


int main() {
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
	
	/* Set up SPI as master */
	SPI2CON = 0;
	SPI2BRG = 4;
	
	/* Clear SPIROV*/
	SPI2STATCLR &= ~0x40;
	/* Set CKP = 1, MSTEN = 1; */
        SPI2CON |= 0x60;
	
	/* Turn on SPI */
	SPI2CONSET = 0x8000;
	
	display_init();
	display_clear();
	// display_dots();
	int i;
	while(1){
		for(i = 0; i < 124; i++) {
			display_clear();
			display_rect(i);
			delay(10000);
		}
		for(i = 123; i > 1; i--) {
			display_clear();
			display_rect(i);
			delay(10000);
		}
	}
	
	
	

	for(;;);
	return;
}