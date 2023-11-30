#include <pic32mx.h>
#include <stdint.h>
#include "project.h"

void startscreen() {
    clear_displaytext();
    display_string(0, "Singleplayer (4)");
    display_string(1, "Multiplayer  (3)");
    display_string(2, "Leaderboard  (2)");
    display_string(3, "Credits      (1)");
    
    // Check inputs
    while(1) {
        string_update();
        if (get_button(1)) {
            while (get_button(1)) {}
            show_credits();
        }
        if (get_button(2)) {
            while (get_button(2)) {}
            show_leaderboard();
        }
        if (get_button(3)) {
            while (get_button(2)) {}
            multiplayer();
        }
        if (get_button(4)) {
            while (get_button(2)) {}
            singleplayer();
        }
    }
}

void show_credits() {
    clear_displaytext();
    display_string(0, "MIPS Head Soccer");
    display_string(1, "Mans Zellman");
    display_string(2, "Max Ahglren");
    display_string(3, "Startmenu  (1)");
    while(1) {
        string_update();
        if (get_button(1)) {
            while (get_button(1)) {}
            startscreen();
        }
    }
}