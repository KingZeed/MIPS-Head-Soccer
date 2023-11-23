#include <pic32mx.h>

/* Hardcoded port and shift number for each button */
int get_button(int port, int shift) {
    int data = port;
    data = data >> shift;
    data &= 0b1;
    return data;
}

/* Check if "button" is pressed */
int get_buttons(int button){
    switch(button) {
        case 1:
            return get_button(PORTF, 1);
        break;
        case 2:
            return get_button(PORTD, 5);
        break;
        case 3:
            return get_button(PORTD, 6);
        break;
        case 4:
            return get_button(PORTD, 7);
        break;
}
    
}




