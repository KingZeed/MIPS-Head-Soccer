#include <pic32mx.h>
#include <stdint.h>
#include "project.h"





struct Player p1 = {24, 31, 1, 0, 0};
struct Player p2 = {103, 31, 1, 0, 0};
struct Ball ball = {60, 12, 2, -1};


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
        if (!p1.jumping) {
            start_jump(1);
        }
    }
    if (get_switchtoggle(2)) {
        if (!p2.jumping) {
            start_jump(2);
        }
    }
    if (p1.pos_y <= 31) {
        jump_player(1);
    }
    if (p2.pos_y <= 31) {
        jump_player(2);
    }
}

void move_player_right(int player_number) {
    if (player_number == 1 && p1.pos_x <= 119) {
        p1.pos_x += p1.speed;
    }
    else if (player_number == 2 && p2.pos_x <= 126) {
        p2.pos_x += p2.speed;
    }
}

void move_player_left(int player_number) {
    if (player_number == 1 && p1.pos_x >= 1) {
        p1.pos_x -= p1.speed;
    }
    else if (player_number == 2 && p2.pos_x >= 8) {
        p2.pos_x -= p2.speed;
    }
}

void start_jump(int player_number) {
    if (player_number == 1) {
        p1.jumping = 1;
        p1.rising = 1;
        p1.pos_y--;
    }
    if (player_number == 2) {
        p2.jumping = 1;
        p2.rising = 1;
        p2.pos_y--;
    }
}

void jump_player(int player_number) {
    if (player_number == 1) {
        switch (p1.pos_y)
        {
        case 31 ... 35: // End jump
            p1.jumping = 0;
            p1.pos_y = 31;
            break;
        case 21 ... 30:
            if (p1.rising) {
                p1.pos_y--;
            }
            else if (!p1.rising) {
                p1.pos_y++;
            }
            break;
        case 20:
            p1.rising = 0;
            p1.pos_y = 21;
            break;
        
        default:
            break;
        }
    }

    if (player_number == 2) {
        switch (p2.pos_y)
        {
        case 31 ... 35: // End jump
            p2.jumping = 0;
            p2.pos_y = 31;
            break;
        case 21 ... 30:
            if (p2.rising) {
                p2.pos_y--;
            }
            else if (!p2.rising) {
                p2.pos_y++;
            }
            break;
        case 20:
            p2.rising = 0;
            p2.pos_y = 21;
            break;
        
        default:
            break;
        }
    }
   
}

