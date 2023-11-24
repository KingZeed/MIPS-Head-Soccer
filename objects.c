#include <pic32mx.h>
#include <stdint.h>
#include "project.h"

struct Ball {
    int pos_x;
    int pos_y;
    int speed;
    int acceleration;
};

struct Player {
    int pos_x;
    int pos_y;
    int speed;
};