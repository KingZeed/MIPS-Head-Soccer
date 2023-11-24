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
    
    display[13][59] = dot_color;
    display[12][59] = dot_color;
    display[11][59] = dot_color;

    display[14][60] = dot_color;
    display[13][60] = dot_color;
    display[12][60] = dot_color;
    display[11][60] = dot_color;
    display[10][60] = dot_color;

    display[9][61] = dot_color;
    display[10][61] = dot_color;
    display[11][61] = dot_color;
    display[12][61] = dot_color;
    display[13][61] = dot_color;
    display[14][61] = dot_color;
    display[15][61] = dot_color;

    display[9][62] = dot_color;
    display[10][62] = dot_color;
    display[11][62] = dot_color;
    display[12][62] = dot_color;
    display[13][62] = dot_color;
    display[14][62] = dot_color;
    display[15][62] = dot_color;
    
    display[9][63] = dot_color;
    display[10][63] = dot_color;
    display[11][63] = dot_color;
    display[12][63] = dot_color;
    display[13][63] = dot_color;
    display[14][63] = dot_color;
    display[15][63] = dot_color;

    display[14][64] = dot_color;
    display[13][64] = dot_color;
    display[12][64] = dot_color;
    display[11][64] = dot_color;
    display[10][64] = dot_color;

    display[13][65] = dot_color;
    display[12][65] = dot_color;
    display[11][65] = dot_color;

    display_update();
};

void draw_player1_start_pos() {
    
    display[31][24] = dot_color;
    display[30][24] = dot_color;
    display[29][24] = dot_color;
    display[28][24] = dot_color;
    display[27][24] = dot_color;
    display[26][24] = dot_color;
    display[25][24] = dot_color;
    display[24][24] = dot_color;
    display[23][24] = dot_color;
    display[23][25] = dot_color;
    display[23][26] = dot_color;
    display[23][27] = dot_color;
    display[23][28] = dot_color;
    display[23][29] = dot_color;
    display[24][29] = dot_color;
    display[25][29] = dot_color;
    display[26][29] = dot_color;
    display[27][29] = dot_color;
    display[28][29] = dot_color;
    display[29][29] = dot_color;
    display[30][29] = dot_color;
    display[31][29] = dot_color;

    display[30][30] = dot_color;
    display[30][31] = dot_color;
    display[31][31] = dot_color;

    display[25][27] = dot_color;

    display[27][26] = dot_color;
    display[28][26] = dot_color;
    display[28][27] = dot_color;
    display[28][28] = dot_color;

    display_update();
};

void draw_player2() {
    
    display[31][103] = dot_color;
    display[30][103] = dot_color;
    display[29][103] = dot_color;
    display[28][103] = dot_color;
    display[27][103] = dot_color;
    display[26][103] = dot_color;
    display[25][103] = dot_color;
    display[24][103] = dot_color;
    display[23][103] = dot_color;
    display[23][102] = dot_color;
    display[23][101] = dot_color;
    display[23][100] = dot_color;
    display[23][99] = dot_color;
    display[23][98] = dot_color;
    display[24][98] = dot_color;
    display[25][98] = dot_color;
    display[26][98] = dot_color;
    display[27][98] = dot_color;
    display[28][98] = dot_color;
    display[29][98] = dot_color;
    display[30][98] = dot_color;
    display[31][98] = dot_color;

    display[30][97] = dot_color;
    display[30][96] = dot_color;
    display[31][96] = dot_color;

    display[25][100] = dot_color;

    display[27][101] = dot_color;
    display[28][101] = dot_color;
    display[28][100] = dot_color;
    display[28][99] = dot_color;

    display_update();
};
