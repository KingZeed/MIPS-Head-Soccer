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
    display[14][1] = dot_color;
    display[13][1] = dot_color;
    display[13][2] = dot_color;
    display[13][3] = dot_color;
    display[13][4] = dot_color;
    display[13][5] = dot_color;
    display[12][5] = dot_color;
    display[12][6] = dot_color;
    display[12][7] = dot_color;
    display[12][8] = dot_color;
    display[12][9] = dot_color;
    display[11][9] = dot_color;
    display[11][10] = dot_color;
    display[11][11] = dot_color;
    display[11][12] = dot_color;
    display[11][13] = dot_color;
    display[10][13] = dot_color;
    display[10][14] = dot_color;
    display[10][15] = dot_color;
    display[10][16] = dot_color;
    display[10][17] = dot_color;
    display[11][17] = dot_color;
    display[12][17] = dot_color;
    display[13][17] = dot_color;
    display[14][17] = dot_color;
    display[15][17] = dot_color;
    display[16][17] = dot_color;
    display[17][17] = dot_color;
    display[18][17] = dot_color;
    display[19][17] = dot_color;
    display[20][17] = dot_color;
    display[21][17] = dot_color;
    display[22][17] = dot_color;
    display[23][17] = dot_color;
    display[24][17] = dot_color;
    display[25][17] = dot_color;
    display[26][17] = dot_color;
    display[27][17] = dot_color;
    display[28][17] = dot_color;
    display[29][17] = dot_color;
    display[30][17] = dot_color;
    display[31][17] = dot_color;

    display_update();
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
    display[14][126] = dot_color;
    display[13][126] = dot_color;
    display[13][125] = dot_color;
    display[13][124] = dot_color;
    display[13][123] = dot_color;
    display[13][122] = dot_color;
    display[12][122] = dot_color;
    display[12][121] = dot_color;
    display[12][120] = dot_color;
    display[12][119] = dot_color;
    display[12][118] = dot_color;
    display[11][118] = dot_color;
    display[11][117] = dot_color;
    display[11][116] = dot_color;
    display[11][115] = dot_color;
    display[11][114] = dot_color;
    display[10][114] = dot_color;
    display[10][113] = dot_color;
    display[10][112] = dot_color;
    display[10][111] = dot_color;
    display[10][110] = dot_color;
    display[11][110] = dot_color;
    display[12][110] = dot_color;
    display[13][110] = dot_color;
    display[14][110] = dot_color;
    display[15][110] = dot_color;
    display[16][110] = dot_color;
    display[17][110] = dot_color;
    display[18][110] = dot_color;
    display[19][110] = dot_color;
    display[20][110] = dot_color;
    display[21][110] = dot_color;
    display[22][110] = dot_color;
    display[23][110] = dot_color;
    display[24][110] = dot_color;
    display[25][110] = dot_color;
    display[26][110] = dot_color;
    display[27][110] = dot_color;
    display[28][110] = dot_color;
    display[29][110] = dot_color;
    display[30][110] = dot_color;
    display[31][110] = dot_color;

    display_update();
};

void draw_ball(int x, int y) {
    
    display[13 + y][59 + x] = dot_color;
    display[12 + y][59 + x] = dot_color;
    display[11 + y][59 + x] = dot_color;
    display[14 + y][60 + x] = dot_color;
    display[13 + y][60 + x] = dot_color;
    display[12 + y][60 + x] = dot_color;
    display[11 + y][60 + x] = dot_color;
    display[10 + y][60 + x] = dot_color;
    display[9 + y][61 + x] = dot_color;
    display[10 + y][61 + x] = dot_color;
    display[11 + y][61 + x] = dot_color;
    display[12 + y][61 + x] = dot_color;
    display[13 + y][61 + x] = dot_color;
    display[14 + y][61 + x] = dot_color;
    display[15 + y][61 + x] = dot_color;
    display[9 + y][62 + x] = dot_color;
    display[10 + y][62 + x] = dot_color;
    display[11 + y][62 + x] = dot_color;
    display[12 + y][62 + x] = dot_color;
    display[13 + y][62 + x] = dot_color;
    display[14 + y][62 + x] = dot_color;
    display[15 + y][62 + x] = dot_color;
    display[9 + y][63 + x] = dot_color;
    display[10 + y][63 + x] = dot_color;
    display[11 + y][63 + x] = dot_color;
    display[12 + y][63 + x] = dot_color;
    display[13 + y][63 + x] = dot_color;
    display[14 + y][63 + x] = dot_color;
    display[15 + y][63 + x] = dot_color;
    display[14 + y][64 + x] = dot_color;
    display[13 + y][64 + x] = dot_color;
    display[12 + y][64 + x] = dot_color;
    display[11 + y][64 + x] = dot_color;
    display[10 + y][64 + x] = dot_color;
    display[13 + y][65 + x] = dot_color;
    display[12 + y][65 + x] = dot_color;
    display[11 + y][65 + x] = dot_color;

    display_update();
};

void draw_player1(int x, int y) {
    
    display[31 + y][24 + x] = dot_color;
    display[30 + y][24 + x] = dot_color;
    display[29 + y][24 + x] = dot_color;
    display[28 + y][24 + x] = dot_color;
    display[27 + y][24 + x] = dot_color;
    display[26 + y][24 + x] = dot_color;
    display[25 + y][24 + x] = dot_color;
    display[24 + y][24 + x] = dot_color;
    display[23 + y][24 + x] = dot_color;
    display[23 + y][25 + x] = dot_color;
    display[23 + y][26 + x] = dot_color;
    display[23 + y][27 + x] = dot_color;
    display[23 + y][28 + x] = dot_color;
    display[23 + y][29 + x] = dot_color;
    display[24 + y][29 + x] = dot_color;
    display[25 + y][29 + x] = dot_color;
    display[26 + y][29 + x] = dot_color;
    display[27 + y][29 + x] = dot_color;
    display[28 + y][29 + x] = dot_color;
    display[29 + y][29 + x] = dot_color;
    display[30 + y][29 + x] = dot_color;
    display[31 + y][29 + x] = dot_color;

    display[30 + y][30 + x] = dot_color;
    display[30 + y][31 + x] = dot_color;
    display[31 + y][31 + x] = dot_color;

    display[25 + y][27 + x] = dot_color;

    display[27 + y][26 + x] = dot_color;
    display[28 + y][26 + x] = dot_color;
    display[28 + y][27 + x] = dot_color;
    display[28 + y][28 + x] = dot_color;

    display_update();
};

void draw_player2(int x, int y) {
    
    display[31 + y][103 + x] = dot_color;
    display[30 + y][103 + x] = dot_color;
    display[29 + y][103 + x] = dot_color;
    display[28 + y][103 + x] = dot_color;
    display[27 + y][103 + x] = dot_color;
    display[26 + y][103 + x] = dot_color;
    display[25 + y][103 + x] = dot_color;
    display[24 + y][103 + x] = dot_color;
    display[23 + y][103 + x] = dot_color;
    display[23 + y][102 + x] = dot_color;
    display[23 + y][101 + x] = dot_color;
    display[23 + y][100 + x] = dot_color;
    display[23 + y][99 + x] = dot_color;
    display[23 + y][98 + x] = dot_color;
    display[24 + y][98 + x] = dot_color;
    display[25 + y][98 + x] = dot_color;
    display[26 + y][98 + x] = dot_color;
    display[27 + y][98 + x] = dot_color;
    display[28 + y][98 + x] = dot_color;
    display[29 + y][98 + x] = dot_color;
    display[30 + y][98 + x] = dot_color;
    display[31 + y][98 + x] = dot_color;

    display[30 + y][97 + x] = dot_color;
    display[30 + y][96 + x] = dot_color;
    display[31 + y][96 + x] = dot_color;

    display[25 + y][100 + x] = dot_color;

    display[27 + y][101 + x] = dot_color;
    display[28 + y][101 + x] = dot_color;
    display[28 + y][100 + x] = dot_color;
    display[28 + y][99 + x] = dot_color;

    display_update();
};
