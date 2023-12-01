#include <pic32mx.h>
#include <stdint.h>
#include "project.h"

void check_player_collision() {
    if (ball.pos_x <= 9 && ball.pos_y > 10) {
        PORTESET = 0b1;
    }
    else {
        PORTECLR = 0b1;
    }
}