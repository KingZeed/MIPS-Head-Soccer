#include <pic32mx.h>
#include <stdint.h>
#include "project.h"

struct Player p1 = {24, 31, 1, 0, 0};
struct Player p2 = {103, 31, 1, 0, 0};


int right = 0;
int left = 1;

struct Ball ball = {63, 12, -2, -1};


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
            start_jump_1();
        }
    }
    if (get_switchtoggle(2)) {
        if (!p2.jumping) {
            start_jump_2();
        }
    }
    if (p1.pos_y <= 31) {
        jump_player_1();
    }
    if (p2.pos_y <= 31) {
        jump_player_2();
    }
}

void move_player_right(int player_number) {
    if (player_number == 1 && p1.pos_x <= 55) {
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
    else if (player_number == 2 && p2.pos_x >= 72) {
        p2.pos_x -= p2.speed;
    }
}

void start_jump_1() {
    p1.jumping = 1;
    p1.rising = 1;
    p1.pos_y--;
}
void start_jump_2() {
    p2.jumping = 1;
    p2.rising = 1;
    p2.pos_y--;
}

void jump_player_2() {
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

    void jump_player_1() {
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

void hardbot_thinking() {
    // ball is not on bot side
    if(ball.pos_y < 25 && p2.pos_y == 31){
        start_jump_2();
    }

    if(ball.pos_x < (DISPLAY_WIDTH/2)){

        if(p2.pos_x < 80) {
            
            right = 1;
            left = 0;
        }
        if (p2.pos_x > 105) {
            
            right = 0;
            left = 1;
        }

        if(right){
            move_player_right(2);
        }

        if(left){
            move_player_left(2);
        }
        
    }

    if(ball.pos_x > (DISPLAY_WIDTH/2) && p2.pos_x < (DISPLAY_WIDTH/2) - 10){
        move_player_left(2);
    }
    
    // ball is on bot side

   if(ball.pos_x > (DISPLAY_WIDTH/2) && ball.pos_x < p2.pos_x){
        move_player_left(2);
    }

    if(ball.pos_x > (DISPLAY_WIDTH/2) && ball.pos_x > p2.pos_x){
        move_player_right(2);
    }
}

void easybot_thinking() {
    // ball is not on bot side
    if(ball.pos_y < 10 && p2.pos_y == 31){
        start_jump_2();
    }

    if(ball.pos_x < (DISPLAY_WIDTH/2)){

        if(p2.pos_x < 80) {
            
            right = 1;
            left = 0;
        }
        if (p2.pos_x > 105) {
            
            right = 0;
            left = 1;
        }

        if(right){
            start_jump_2();
        }
        if(left){
            move_player_left(2);
        }
        
    }

    if(ball.pos_x > (DISPLAY_WIDTH/2) && p2.pos_x < (DISPLAY_WIDTH/2) - 10){
        move_player_left(2);
    }
    // ball is on bot side
    if(ball.pos_x > (DISPLAY_WIDTH/2) && ball.pos_x < p2.pos_x){
        move_player_left(2);
    }

    if(ball.pos_x > (DISPLAY_WIDTH/2) && ball.pos_x > p2.pos_x){
        move_player_right(2);
    }

}

void reset_pos(int player){
    
    p1.pos_x = 24;
    p1.pos_y = 31;

    p2.pos_x = 103;
    p2.pos_y = 31;

    right = 0;
    left = 1;

    ball.pos_x = 63;
    ball.pos_y = 12;
    if(player == 1){
        ball.speed_x = -2;
    }
    else {
        ball.speed_x = 2;
    }
    
    ball.speed_y = -1;
}