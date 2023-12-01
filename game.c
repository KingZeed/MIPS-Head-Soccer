#include <pic32mx.h>
#include <stdint.h>
#include "project.h"


/* void singleplayer(){
    clear_displaytext();
    display_string(0, "Singleplayer");
    display_string(1, "Work in progress");
    display_string(2, "Startscreen (1)");
    while(1) {
        string_update();
        if (get_button(1)) {
            while (get_button(1)) {}
            startscreen();
        }
    }
} */

void singleplayer() {

    while (1) {
        display_clear();
        draw_left_goal();
        draw_right_goal();
        draw_ball(ball.pos_x, ball.pos_y);
        draw_player1(p1.pos_x, p1.pos_y);
        draw_player2(p2.pos_x, p2.pos_y);
        check_barriar_collision();
        move_ball();
        hardbot_thinking();

        check_movement();
        
        display_update();
        delay(100000);
        }
}


void multiplayer(){
    clear_displaytext();
    display_string(0, "Multiplayer");
    display_string(1, "Work in progress");
    display_string(2, "Startscreen (1)");
    display_string(3, "Start game (2)");
    while(1) {
        string_update();
        if (get_button(1)) {
            while (get_button(1)) {}
            startscreen();
        }
        if (get_button(2)) {
            while (get_button(2)) {}
            multiplayer_game_loop();
        }
    }
}

multiplayer_game_loop() {
    while (1) {
		display_clear();
		draw_left_goal();
		draw_right_goal();
		draw_ball(ball.pos_x, ball.pos_y);
		draw_player1(p1.pos_x, p1.pos_y);
		draw_player2(p2.pos_x, p2.pos_y);
		check_movement();
		display_update();
		delay(100000);
	}
}







