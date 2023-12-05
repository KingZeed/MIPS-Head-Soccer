#include <pic32mx.h>
#include <stdint.h>
#include "project.h"

uint8_t dot_color = 1;
uint8_t left_goal[32][128];

void draw_left_goal() {
    display[31][0] = dot_color;
    display[30][0] = dot_color;
    display[29][0] = dot_color;
    display[28][0] = dot_color;
    display[27][0] = dot_color;
    display[26][0] = dot_color;
    display[25][0] = dot_color;
    display[24][0] = dot_color;
    display[23][0] = dot_color;
    display[22][0] = dot_color;
    display[21][0] = dot_color;
    display[20][0] = dot_color;
    display[19][0] = dot_color;
    display[18][0] = dot_color;
    display[17][0] = dot_color;
    display[16][0] = dot_color;
    display[15][0] = dot_color;
    display[14][0] = dot_color;
    display[13][0] = dot_color;
    display[12][0] = dot_color;
    display[12][1] = dot_color;
    display[12][2] = dot_color;
    display[12][3] = dot_color;
    display[12][4] = dot_color;
    display[11][4] = dot_color;
    display[11][5] = dot_color;
    display[11][6] = dot_color;
    display[11][7] = dot_color;
    display[11][8] = dot_color;
    display[10][8] = dot_color;
    display[10][9] = dot_color;
    display[10][10] = dot_color;
    display[10][11] = dot_color;
    display[10][12] = dot_color;

    display[10][12] = dot_color;
    display[11][12] = dot_color;
    display[12][12] = dot_color;
    display[13][12] = dot_color;
    display[14][12] = dot_color;
    display[15][12] = dot_color;
    display[16][12] = dot_color;
    display[17][12] = dot_color;
    display[18][12] = dot_color;
    display[19][12] = dot_color;
    display[20][12] = dot_color;
    display[21][12] = dot_color;
    display[22][12] = dot_color;
    display[23][12] = dot_color;
    display[24][12] = dot_color;
    display[25][12] = dot_color;
    display[26][12] = dot_color;
    display[27][12] = dot_color;
    display[28][12] = dot_color;
    display[29][12] = dot_color;
    display[30][12] = dot_color;
    display[31][12] = dot_color;

};

void draw_right_goal() {

    display[31][127] = dot_color;
    display[30][127] = dot_color;
    display[29][127] = dot_color;
    display[28][127] = dot_color;
    display[27][127] = dot_color;
    display[26][127] = dot_color;
    display[25][127] = dot_color;
    display[24][127] = dot_color;
    display[23][127] = dot_color;
    display[22][127] = dot_color;
    display[21][127] = dot_color;
    display[20][127] = dot_color;
    display[19][127] = dot_color;
    display[18][127] = dot_color;
    display[17][127] = dot_color;
    display[16][127] = dot_color;
    display[15][127] = dot_color;
    display[14][127] = dot_color;
    display[13][127] = dot_color;
    display[12][127] = dot_color;
    display[12][126] = dot_color;
    display[12][125] = dot_color;
    display[12][124] = dot_color;
    display[12][123] = dot_color;
    display[11][123] = dot_color;
    display[11][122] = dot_color;
    display[11][121] = dot_color;
    display[11][120] = dot_color;
    display[11][119] = dot_color;
    display[10][119] = dot_color;
    display[10][118] = dot_color;
    display[10][117] = dot_color;
    display[10][116] = dot_color;
    display[10][115] = dot_color;

    display[10][115] = dot_color;
    display[11][115] = dot_color;
    display[12][115] = dot_color;
    display[13][115] = dot_color;
    display[14][115] = dot_color;
    display[15][115] = dot_color;
    display[16][115] = dot_color;
    display[17][115] = dot_color;
    display[18][115] = dot_color;
    display[19][115] = dot_color;
    display[20][115] = dot_color;
    display[21][115] = dot_color;
    display[22][115] = dot_color;
    display[23][115] = dot_color;
    display[24][115] = dot_color;
    display[25][115] = dot_color;
    display[26][115] = dot_color;
    display[27][115] = dot_color;
    display[28][115] = dot_color;
    display[29][115] = dot_color;
    display[30][115] = dot_color;
    display[31][115] = dot_color;

};

void draw_ball(int x, int y) {
    
    display[y][x] = dot_color;      // Center pixel
    display[y - 1][x] = dot_color;
    display[y - 2][x] = dot_color;
    display[y - 3][x] = dot_color;
    display[y + 1][x] = dot_color;
    display[y + 2][x] = dot_color;
    display[y + 3][x] = dot_color;
    // Left side
    display[y][x - 1] = dot_color;
    display[y - 1][x - 1] = dot_color;
    display[y - 2][x - 1] = dot_color;
    display[y - 3][x - 1] = dot_color;
    display[y + 1][x - 1] = dot_color;
    display[y + 2][x - 1] = dot_color;
    display[y + 3][x - 1] = dot_color;
    display[y][x - 2] = dot_color;
    display[y - 1][x - 2] = dot_color;
    display[y - 2][x - 2] = dot_color;
    display[y + 1][x - 2] = dot_color;
    display[y + 2][x - 2] = dot_color;
    display[y][x - 3] = dot_color;
    display[y - 1][x - 3] = dot_color;
    display[y + 1][x - 3] = dot_color;
    // Right side
    display[y][x + 1] = dot_color;
    display[y - 1][x + 1] = dot_color;
    display[y - 2][x + 1] = dot_color;
    display[y - 3][x + 1] = dot_color;
    display[y + 1][x + 1] = dot_color;
    display[y + 2][x + 1] = dot_color;
    display[y + 3][x + 1] = dot_color;
    display[y][x + 2] = dot_color;
    display[y - 1][x + 2] = dot_color;
    display[y - 2][x + 2] = dot_color;
    display[y + 1][x + 2] = dot_color;
    display[y + 2][x + 2] = dot_color;
    display[y][x + 3] = dot_color;
    display[y - 1][x + 3] = dot_color;
    display[y + 1][x + 3] = dot_color;

};

void draw_player1(int x, int y) {
    
    display[y][x] = dot_color;      // Bottom left pixel
    display[y - 1][x] = dot_color;
    display[y - 2][x] = dot_color;
    display[y - 3][x] = dot_color;
    display[y - 4][x] = dot_color;
    display[y - 5][x] = dot_color;
    display[y - 6][x] = dot_color;
    display[y - 7][x] = dot_color;
    display[y - 8][x] = dot_color;
    display[y - 8][x + 1] = dot_color;
    display[y - 8][x + 2] = dot_color;
    display[y - 8][x + 3] = dot_color;
    display[y - 8][x + 4] = dot_color;
    display[y - 8][x + 5] = dot_color;
    display[y - 7][x + 5] = dot_color;
    display[y - 6][x + 5] = dot_color;
    display[y - 5][x + 5] = dot_color;
    display[y - 4][x + 5] = dot_color;
    display[y - 3][x + 5] = dot_color;
    display[y - 2][x + 5] = dot_color;
    display[y - 1][x + 5] = dot_color;
    display[y][x + 5] = dot_color;
    // Foot
    display[y][x + 7] = dot_color;
    display[y - 1][x + 7] = dot_color;
    display[y - 1][x + 6] = dot_color;
    // Mouth
    display[y - 4][x + 4] = dot_color;
    display[y - 4][x + 3] = dot_color;
    display[y - 4][x + 2] = dot_color;
    display[y - 5][x + 2] = dot_color;
    // Eye
    display[y - 6][x + 3] = dot_color;
};

void draw_player2(int x, int y) {
    
    display[y][x] = dot_color;      // Bottom right pixel
    display[y - 1][x] = dot_color;
    display[y - 2][x] = dot_color;
    display[y - 3][x] = dot_color;
    display[y - 4][x] = dot_color;
    display[y - 5][x] = dot_color;
    display[y - 6][x] = dot_color;
    display[y - 7][x] = dot_color;
    display[y - 8][x] = dot_color;
    display[y - 8][x - 1] = dot_color;
    display[y - 8][x - 2] = dot_color;
    display[y - 8][x - 3] = dot_color;
    display[y - 8][x - 4] = dot_color;
    display[y - 8][x - 5] = dot_color;
    display[y - 7][x - 5] = dot_color;
    display[y - 6][x - 5] = dot_color;
    display[y - 5][x - 5] = dot_color;
    display[y - 4][x - 5] = dot_color;
    display[y - 3][x - 5] = dot_color;
    display[y - 2][x - 5] = dot_color;
    display[y - 1][x - 5] = dot_color;
    display[y][x - 5] = dot_color;
    // Foot
    display[y][x - 7] = dot_color;
    display[y - 1][x - 7] = dot_color;
    display[y - 1][x - 6] = dot_color;
    // Mouth
    display[y - 4][x - 4] = dot_color;
    display[y - 4][x - 3] = dot_color;
    display[y - 4][x - 2] = dot_color;
    display[y - 5][x - 2] = dot_color;
    // Eye
    display[y - 6][x - 3] = dot_color;

};


