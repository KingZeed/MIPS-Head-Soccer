#include <pic32mx.h>
#include <stdint.h>
#include "project.h"

void check_player_collision() {
    if (p1.pos_x <= 9) {
        PORTESET = 0b1;
    }
    else {
        PORTECLR = 0b1;
    }
}