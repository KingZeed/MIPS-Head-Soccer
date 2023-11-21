#include <pic32mx.h>
#include <stdint.h>
#include "project.h"


void main_menu(){
        display_string(0, "(1) Singlplayer #");
        display_string(1, "(2) Multiplayer #");
        display_string(2, "(3) Leaderboard #");
    
    while (1) { 
        string_update();

        if (0/* Button1 */) {
            /* singeplayerfunction */
        }

        if (0/* Button2 */) {
            /* multiplayerfunction */
        }

        if (0/* Button1 */) {
            /* leaderboardfunction function */
        }
        
    }
    
}


void show_leaderboard() {

}




    