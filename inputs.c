#include <pic32mx.h>

/* Hardcoded port and shift number for each button */
int get_input(int port, int shift) {
    int data = port;
    data = data >> shift;
    data &= 0b1;
    return data;
}

/* Check if button(number) is pressed */
int get_button(int button_number){
    switch(button_number) {
        case 1:
            return get_input(PORTF, 1);
        break;
        case 2:
            return get_input(PORTD, 5);
        break;
        case 3:
            return get_input(PORTD, 6);
        break;
        case 4:
            return get_input(PORTD, 7);
        break;
    }
    
}

/* Return a 4 bit value that represent witch buttons that are pressed */
int get_buttons_4bit(){
    int i;
    int button_data = 0;
    for(i = 0; i < 4; i++){
        button_data |= (get_button(i+1) << i);
    }
    return button_data;
}

/* Check if switch(number) is pressed */
int get_switchtoggle(int switch_number){
    switch(switch_number) {
        case 1:
            return get_input(PORTD, 8);
        break;
        case 2:
            return get_input(PORTD, 9);
        break;
        case 3:
            return get_input(PORTD, 10);
        break;
        case 4:
            return get_input(PORTD, 11);
        break;
    }
    
}

/* Return a 4 bit value that represent whitch switches that are toggled */
int get_switches_4bit(){
    int i;
    int button_data = 0;
    for(i = 0; i < 4; i++){
        button_data |= (get_switchtoggle(i+1) << i);
    }
    return button_data;
}


