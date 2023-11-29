#include <pic32mx.h>
#include <stdint.h>
#include "project.h"

void check_ground_collision() {
    if(ball.pos_y >= (GROUND_LEVEL - BALL_RADIUS)){
        // ball.gravity = 0;

        ball.acceleration_y = ball.acceleration_y * 4;
    }
}

void bounce(int dir_x, int dir_y) {
    

}

void move_ball() {

    ball.speed_x += ball.acceleration_x;
    ball.speed_y += ball.acceleration_y;

    ball.pos_x += ball.speed_x;
    ball.pos_y -= ball.speed_y;
    
     if (ball.acceleration_y <= 0) {
        ball.speed_y = 0;
    }

    if (ball.acceleration_y > 0) {
        ball.acceleration_y = ball.acceleration_y - ball.gravity;
    }

}