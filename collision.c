#include <pic32mx.h>
#include <stdint.h>
#include "project.h"

#define MAX_BALL_SPEED 3 

float bounce_ground = 0.82;
float gravity = 0.05;
float friction = 0.005;

void check_crossbar_collision() {
    if(ball.pos_y + BALL_RADIUS <= 15) {
        // Right crossbar
        if (ball.pos_x > 115 - BALL_RADIUS) {
            ball.pos_x -= 3;
            ball.pos_y -= 3;
            ball.speed_x *= -1;
        }
        // Left crossbar
        if (ball.pos_x < 12 + BALL_RADIUS) {
            ball.pos_x += 3;
            ball.pos_y -= 3;
            ball.speed_x *= -1;
        }
    }
}

void check_goal() {
    if (ball.pos_x <= 13 && ball.pos_y > 15) {
        goal(2);
    }

    if (ball.pos_x >= 116 && ball.pos_y > 15) {
        goal(1);
    }
}

void check_barriar_collision() {
    check_goal();
    check_crossbar_collision();
    if(ball.pos_y + BALL_RADIUS >= DISPLAY_HEIGHT){
        ball.pos_y = DISPLAY_HEIGHT - BALL_RADIUS;
        ball.speed_y *= -bounce_ground;   
    }

    if (ball.pos_y - BALL_RADIUS <= 0) {
        ball.pos_y = 2 + BALL_RADIUS;
        ball.speed_y = -0.8; 
        // ball.speed += 0.05;
    }

    if (ball.pos_x + BALL_RADIUS >= DISPLAY_WIDTH) {
        ball.pos_x = 126 - BALL_RADIUS;
        ball.speed_x *= -1; 
    }

    if (ball.pos_x - BALL_RADIUS <= 0 ) {
        ball.pos_x = 0 + BALL_RADIUS;
        ball.speed_x *= -1; 
    }
}


void shoot(){
    if (ball.speed_x < 0) {
        ball.pos_x += 3;
    }
    if (ball.speed_x > 0) {
        ball.pos_x -= 3;
    }

    ball.speed_x *= -2;
    ball.speed_y = -2.5;  
}

void bounce_player() {
    if (ball.speed_x < 0) {
        ball.pos_x += 3;
    }
    if (ball.speed_x > 0) {
        ball.pos_x -= 3;
    }
    ball.speed_x *= -1.4;
}

void head_player() {
    ball.pos_y -= 5;
    if (ball.speed_x < 0) {
        ball.pos_x += 3;
    }
    if (ball.speed_x > 0) {
        ball.pos_x -= 3;
    }
    ball.speed_y = -2.5;
    //ball.speed_x *= -1.5;
}

void move_ball() {
    // Lowest speed limit
    if (ball.speed_x <= 0 && ball.speed_x > -1) {
        ball.speed_x = -1;
    }
    if (ball.speed_x >= 0 && ball.speed_x < 1) {
        ball.speed_x = 1;
    }
    if (ball.speed_x > MAX_BALL_SPEED) {
        ball.speed_x = MAX_BALL_SPEED;
    }
    if (ball.speed_x < -MAX_BALL_SPEED) {
        ball.speed_x = -MAX_BALL_SPEED;
    }
    
    // Add a little gravity so the ball not freeze in midair
    if ((int)ball.speed_y == 0){
        ball.speed_y += 0.27;
    }

    ball.pos_x += (int)ball.speed_x;
    ball.pos_y += (int)ball.speed_y;

    ball.speed_y += gravity;
    if (ball.speed_x > 0) {
        ball.speed_x -= friction;
    }
    if (ball.speed_x < 0) {
        ball.speed_x += friction;
    }
 
}

void check_player1_ball_collision() {
    
    // For Player 1
    if (p1.pos_x + 11 >= ball.pos_x && p1.pos_x + 6 <= ball.pos_x) {
        // Foot
        if (p1.pos_y - 6 <= ball.pos_y && p1.pos_y + 4 > ball.pos_y) {
            shoot(1);
        }
        // Front body
        else if (p1.pos_y - 13 <= ball.pos_y && p1.pos_y - 6 > ball.pos_y) {
            bounce_player(1);
        }
    }
    else if (p1.pos_x - 4 <= ball.pos_x && p1.pos_x >= ball.pos_x) {
        // Back body
        if (p1.pos_y - 13 <= ball.pos_y && p1.pos_y + 4 > ball.pos_y) {
            bounce_player(1);
        }
    }
    else if (p1.pos_x + 11 > ball.pos_x && p1.pos_x - 4 < ball.pos_x) {
        // Head
        if (p1.pos_y - 14 <= ball.pos_y) {
            head_player();
        }
    }
    
}

void check_player2_ball_collision() { 
    
    // For Player 2
    if (p2.pos_x - 11 <= ball.pos_x && p2.pos_x - 6 >= ball.pos_x) {
        // Foot
        if (p2.pos_y - 6 <= ball.pos_y && p2.pos_y + 4 > ball.pos_y) {
            shoot(1);
        }
        // Front body
        else if (p2.pos_y - 13 <= ball.pos_y && p2.pos_y - 6 > ball.pos_y) {
            bounce_player(1);
        }
    }
    else if (p2.pos_x - 4 >= ball.pos_x && p2.pos_x <= ball.pos_x) {
        // Back body
        if (p2.pos_y - 13 <= ball.pos_y && p2.pos_y + 4 > ball.pos_y) {
            bounce_player(1);
        }
    }
    else if (p2.pos_x - 11 < ball.pos_x && p2.pos_x - 4 > ball.pos_x) {
        // Head
        if (p2.pos_y - 14 <= ball.pos_y) {
            head_player();
        }
    }
    
}