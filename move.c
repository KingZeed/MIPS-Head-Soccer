#include <pic32mx.h>
#include <stdint.h>
#include "project.h"

struct Player p1 = {24, 31, 1};
struct Player p2 = {103, 31, 1};

int p1_jumping = 0;
int p1_in_air = 0;
int p1_ready = 1;
float p1_jumpspeed = 0.2;

int p2_jumping = 0;
int p2_in_air = 0;
int p2_ready = 1;
float p2_jumpspeed = 0.2;

int right = 0;
int left = 1;

struct Ball ball = {63, 12, -2, -1};

void check_player1_inputs() {
    if (get_button(4)) {
        move_player_left(1);
    }
    else if (get_button(3)) {
        move_player_right(1);
    }
    if (get_switchtoggle(4) && p1_ready) {
        p1_ready = 0;
        p1_jumping = 1;
    }
}

void check_player1_inputs_singleplayer() {
    if (get_button(4)) {
        move_player_left(1);
    }
    else if (get_button(3)) {
        move_player_right(1);
    }
    if (get_button(2) && p1_ready) {
        p1_ready = 0;
        p1_jumping = 1;
    }
}

void check_player2_inputs() {
    if (get_button(2)) {
        move_player_left(2);
    }
    else if (get_button(1)) {
        move_player_right(2);
    }
    if (get_switchtoggle(2) && p2_ready) {
        p2_ready = 0;
        p2_jumping = 1;
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


void check_jump_player1() {

    const int jump_height = 21;
    const float jump_speed_increment = 0.2;

    if(p1_jumping) {
        p1_in_air = 1;
        p1.pos_y--;
        // p1.pos_y -= (int)p1_jumpspeed;
        // p1_jumpspeed += jump_speed_increment;

        if(p1.pos_y < jump_height){
            p1_jumpspeed = jump_speed_increment;
            p1_jumping = 0;
        }
    }
    else {
        if(p1_in_air){
            p1_jumpspeed += 0.2;
            p1.pos_y++;
            // p1.pos_y += (int)p1_jumpspeed;
            if(p1.pos_y >= 31){
                p1_in_air = 0;
                p1_ready = 1;
            }
        }
        else {
            p1_jumpspeed = 0.1;
            p1.pos_y = 31;
        }
    }

}

void check_jump_player2(){
    const int jump_height = 21;
    const float jump_speed_increment = 0.2;

    if(p2_jumping) {
        p2_in_air = 1;
        p2.pos_y--;
       

        if(p2.pos_y < jump_height){
            p2_jumpspeed = jump_speed_increment;
            p2_jumping = 0;
        }
    }
    else {
        if(p2_in_air){
            p2_jumpspeed += 0.2;
            p2.pos_y++;
            if(p2.pos_y >= 31){
                p2_in_air = 0;
                p2_ready = 1;
            }
        }
        else {
            p2_jumpspeed = 0.1;
            p2.pos_y = 31;
        }
    }
}


void hardbot_thinking() {
    // ball is not on bot side
    if(ball.pos_y < 25 && p2.pos_y == 31 && p2_ready){
        p2_ready = 0;
        p2_jumping = 1;
    }

    if(ball.pos_x < (DISPLAY_WIDTH/2)){

        if(p2.pos_x < 90) {
            
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
        p2_ready = 0;
        p2_jumping = 1;
    }

    if(ball.pos_x < (DISPLAY_WIDTH/2)){

        if(p2.pos_x < 50) {
            
            right = 1;
            left = 0;
        }
        if (p2.pos_x > 105) {
            right = 0;
            left = 1;
        }

        if(right){
            p2_ready = 0;
            p2_jumping = 1;
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