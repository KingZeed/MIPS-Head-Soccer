#include <pic32mx.h>
#include <stdint.h>
#include "project.h"

void main_menu(){
        display_string(0, "(1) Singlplayer #");
        display_string(1, "(2) Multiplayer #");
        display_string(2, "(3) Leaderboard #");
    
    while (1) { 
        string_update();

        if (get_button(1)) {
            while (get_button(1)){}
            /* Singleplayer */
        }

        if (get_button(2)) {
            while (get_button(2)){}
            /* Multiplayer */
        }

        if (get_button(3)) {
            while (get_button(3)){}
            show_leaderboard();
        }
        
       
        
    }
    
}






    