#include <pic32mx.h>
#include <stdint.h>
#include "project.h"

u_int8_t dot_color = 0;
uint8_t left_goal[32][128];

void draw_left_goal() {

    left_goal[31][0] = dot_color;
    left_goal[30][0] = dot_color;
    left_goal[29][0] = dot_color;
    left_goal[28][0] = dot_color;
    left_goal[27][0] = dot_color;
    left_goal[26][0] = dot_color;
    left_goal[25][0] = dot_color;
    left_goal[24][0] = dot_color;
    left_goal[23][0] = dot_color;
    left_goal[23][1] = dot_color;
    left_goal[22][1] = dot_color;
    left_goal[22][1] = dot_color;
    left_goal[22][2] = dot_color;
    left_goal[22][3] = dot_color;
    left_goal[21][3] = dot_color;
    left_goal[21][4] = dot_color;
    left_goal[21][5] = dot_color;
    left_goal[20][5] = dot_color;
    left_goal[20][6] = dot_color;
    left_goal[20][7] = dot_color;
    left_goal[20][8] = dot_color;
    left_goal[20][9] = dot_color;
    left_goal[21][9] = dot_color;
    left_goal[22][9] = dot_color;
    left_goal[23][9] = dot_color;
    left_goal[24][9] = dot_color;
    left_goal[25][9] = dot_color;
    left_goal[26][9] = dot_color;
    left_goal[27][9] = dot_color;
    left_goal[28][9] = dot_color;
    left_goal[29][9] = dot_color;
    left_goal[30][9] = dot_color;
    left_goal[31][9] = dot_color;
};
