#include <pic32mx.h>
#include <stdint.h>
#include "project.h"


void singleplayer(){
    clear_displaytext();
    display_string(0, "Singleplayer");
    display_string(1, "Work in progress");
    display_string(2, "Startscreen (1)");
    while(1) {
        string_update();
        if (get_button(1)) {
            while (get_button(1)) {}
            startscreen();
        }
    }
}



void multiplayer(){
    clear_displaytext();
    display_string(0, "Multiplayer");
    display_string(1, "Work in progress");
    display_string(2, "Startscreen (1)");
    while(1) {
        string_update();
        if (get_button(1)) {
            while (get_button(1)) {}
            startscreen();
        }
    }
}







