#include <pic32mx.h>
#include <stdint.h>
#include "project.h"



void main_menu(){
        display_string(0, "(1) Singlplayer #");
        display_string(1, "(2) Multiplayer #");
        display_string(2, "(3) Leaderboard #");
    
    while (1) { 
        string_update();

        if (get_buttons(1)) {
            display_string(0, "button 1");
            display_string(1, "");
            display_string(2, "");
        }

        if (get_buttons(2)) {
            display_string(0, "button 2");
            display_string(1, "");
            display_string(2, "");
        }

        if (get_buttons(3)) {
            display_string(0, "button 3");
            display_string(1, "");
            display_string(2, "");
        }
        if (get_buttons(4)) {
            display_string(0, "button 4");
            display_string(1, "");
            display_string(2, "");
        }
        
    }
    
}


void show_leaderboard() {

}




    