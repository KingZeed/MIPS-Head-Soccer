#include <pic32mx.h>

int get_button_1() {
    int data = PORTF;
    data = data >> 1;
    data &= 0b1;
    return data;
}

int get_button_2() {
    int data = PORTD;
    data = data >> 5;
    data &= 0b1;
    return data;
}

int get_button_3() {
    int data = PORTD;
    data = data >> 6;
    data &= 0b1;
    return data;
}

int get_button_4() {
    int data = PORTD;
    data = data >> 7;
    data &= 0b1;
    return data;
}

int get_buttons(int button){
    switch(button) {
        case 1:
            return get_button_1();
        break;
        case 2:
            return get_button_2();
        break;
        case 3:
            return get_button_3();
        break;
        case 4:
            return get_button_4();
        break;
}
    
}




