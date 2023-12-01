#include <pic32mx.h>
#include <stdint.h>
#include "project.h"

double bounce_ground = 0.8;
double gravity = 0.05;
double friction = 0.001;

void check_barriar_collision() {
    if(ball.pos_y + BALL_RADIUS >= DISPLAY_HEIGHT){
        ball.pos_y = DISPLAY_HEIGHT - BALL_RADIUS;
        ball.speed_y *= -bounce_ground;   
    }

    if (ball.pos_y - BALL_RADIUS <= 0) {
        ball.pos_y = 1 + BALL_RADIUS;
        ball.speed_y *= -1; 
        // ball.speed += 0.05;
    }

    if (ball.pos_x + BALL_RADIUS >= DISPLAY_WIDTH) {
        ball.pos_x = 126 - BALL_RADIUS;
        ball.speed_x *= -bounce_ground; 
    }

    if (ball.pos_x - BALL_RADIUS <= 0 ) {
        ball.pos_x = 0 + BALL_RADIUS;
        ball.speed_x *= -bounce_ground; 
    }
    shoot();
}


void shoot(){
    if(get_switchtoggle(1)){
        ball.speed_x += 0.1;
        ball.speed_y -= 0.2;  
    }
}

void move_ball() {
    // Add a little gravity so the ball not freeze in midair
    if ((int)ball.speed_y == 0){
        ball.speed_y += 0.27;
    }

    ball.pos_x += (int)ball.speed_x;
    ball.pos_y += (int)ball.speed_y;

    ball.speed_y += gravity;
    
   
}