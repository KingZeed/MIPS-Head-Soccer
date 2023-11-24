#include <pic32mx.h>
#include <stdint.h>
#include "project.h"

void move_player_right(int player_number) {
    if (player_number = 1) {
        p1.pos_x += p1.speed;
    }
    else if (player_number = 2) {
        p2.pos_x += p2.speed;
    }
}

void move_player_left(int player_number) {
    if (player_number = 1) {
        p1.pos_x -= p1.speed;
    }
    else if (player_number = 2) {
        p2.pos_x -= p2.speed;
    }
}