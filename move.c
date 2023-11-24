#include <pic32mx.h>
#include <stdint.h>
#include "project.h"

struct Player p1 = {0, 0, 1};
struct Player p2 = {0, 0, 1};
struct Ball ball = {0, 0, 0, 0};

void check_movement() {
    if (get_button(4)) {
        move_player_left(1);
    }
    if (get_button(3)) {
        move_player_right(1);
    }
    if (get_button(2)) {
        move_player_left(2);
    }
    if (get_button(1)) {
        move_player_right(2);
    }
    if (get_switchtoggle(4)) {
        jump_player(1);
    }
}

void move_player_right(int player_number) {
    if (player_number == 1) {
        p1.pos_x += p1.speed;
    }
    else if (player_number == 2) {
        p2.pos_x += p2.speed;
    }
}

void move_player_left(int player_number) {
    if (player_number == 1) {
        p1.pos_x -= p1.speed;
    }
    else if (player_number == 2) {
        p2.pos_x -= p2.speed;
    }
}

void jump_player(int player_number) {
    if (player_number == 1) {
        switch(p1.pos_y) {
        case 0:
            p1.pos_y -= p1.speed;
        break;
        case -1:
            p1.pos_y -= p1.speed;
        break;
        case -2:
            p1.pos_y -= p1.speed;
        break;
        case -3:
            p1.pos_y -= p1.speed;
        break;
        case -4:
            p1.pos_y -= p1.speed;
        break;
        case -5:
            p1.pos_y -= p1.speed;
        break;
        case -6:
            p1.pos_y -= p1.speed;
        break;
        case -7:
            p1.pos_y -= p1.speed;
        break;
        case -8:
            p1.pos_y -= p1.speed;
        break;
        case -9:
            p1.pos_y -= p1.speed;
        break;
        case -10:
            p1.pos_y = 0;
        break;
        }
    }
   
}