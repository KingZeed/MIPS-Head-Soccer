#include <pic32mx.h>
#include <stdint.h>
#include "project.h"

struct Player p1 = {24, 31, 1};
struct Player p2 = {103, 31, 1};
struct Ball ball = {12, 60, 0, 0};

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
        if (p1.pos_y <= -10) {
            p1.pos_y = 0;
        }
        if (p1.pos_y <= 0) {
            p1.pos_y--;
        }
    }
   
}