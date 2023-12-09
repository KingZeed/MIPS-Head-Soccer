#include <pic32mx.h>
#include <stdint.h>
#include "project.h"

int p1_score = 0;
int p2_score = 0;

int playing_singleplayer = 0;
int playing_multiplayer = 0;
int bot_difficulty;

void singleplayer() {

    clear_displaytext();
    display_string(0, "Choose difficulty");
    display_string(1, "Easy (3)");
    display_string(2, "Hard (2)");
    display_string(3, "Startscreen (1)");
    while(1) {
        string_update();
        if (get_button(1)) {
            while (get_button(1)) {}
            startscreen();
        }
        if (get_button(2)) {
            while (get_button(2)) {}
            playing_singleplayer = 1;
            bot_difficulty = 1;
            singleplayer_game_loop();
        }
        if (get_button(3)) {
            while (get_button(3)) {}
            playing_singleplayer = 1;
            bot_difficulty = 0;
            singleplayer_game_loop();
        }
    }
}

void multiplayer(){
    clear_displaytext();
    display_string(0, "Multiplayer");
    display_string(1, "");
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
            playing_multiplayer = 1;
            multiplayer_game_loop();
        }
    }
}

multiplayer_game_loop() {
        
    while (1) {

        display_clear();
        draw_left_goal();
        draw_right_goal();

        move_ball();
    
        check_player1_inputs();
        check_player2_inputs();

        check_barriar_collision();
        check_goal();
        check_player1_ball_collision();
        check_player2_ball_collision();

        check_jump_player1();
        check_jump_player2();

        draw_ball(ball.pos_x, ball.pos_y);
        draw_player1(p1.pos_x, p1.pos_y);
        draw_player2(p2.pos_x, p2.pos_y);
        
        display_update();
        display_score();

        delay(100000);
	}
}

singleplayer_game_loop() {
    
    while (1) {
        display_clear();
        draw_left_goal();
        draw_right_goal();

        move_ball();

        check_player1_inputs_singleplayer();
        bot_thinking(&bot_difficulty);

        check_barriar_collision();
        check_goal();
        check_player1_ball_collision();
        check_player2_ball_collision();

        check_jump_player1();
        check_jump_player2();

        draw_ball(ball.pos_x, ball.pos_y);
        draw_player1(p1.pos_x, p1.pos_y);
        draw_player2(p2.pos_x, p2.pos_y);

        display_update();
        display_score();

        delay(100000);
    }
}

void end_game(int winner) {

    if(playing_singleplayer) {
        game_over_animation(p1_score);
    }

    if(playing_multiplayer) {
        result_animation(winner);
    }
    int new_score = p1_score;
    // Reset things
    int played_singleplayer = playing_singleplayer;
    playing_multiplayer = 0;
    playing_singleplayer = 0;
    p1_score = 0;
    p2_score = 0;
    reset_pos(1);
    int top9 = check_leaderboard(new_score);
    if(played_singleplayer && top9) {
        enter_name(new_score);
    }
    else {
        startscreen();
    }
    
}

void goal(int player){
    // When player1 scores
    if(player == 1){
        p1_score++;
        if(playing_multiplayer && p1_score == 3){
            end_game(1);
        }
    }
    // When player2 scores
    else {
        p2_score++;
        if(playing_singleplayer){
            end_game(2);
        }
        if(playing_multiplayer && p2_score == 3){
            end_game(2);
        }
    }
    
    display_goal_animation();
    if(playing_singleplayer){
        reset_pos(2);
    }
    else {
        reset_pos(player);
    }

    if (playing_singleplayer) {
        singleplayer_game_loop();
    }
    else {
        multiplayer_game_loop();
    }
    
}

void display_score() {
    
    if(playing_multiplayer){
        int p1_binary = calculate_binary(p1_score);
        int p2_binary = calculate_binary(p2_score);

        int scoreboard_leds = 0b00000000;
        scoreboard_leds |= p2_binary;
        scoreboard_leds |= (p1_binary << 5);

        PORTESET = scoreboard_leds;
    }

    else if (playing_singleplayer) {
        PORTESET = p1_score;
    }
    
}

int calculate_binary(score) {

    if(score <= 1) {
        return score;
    }
    else if (score == 2) {
        return 3;
    }
    else {
        return 7;
    }

}

void display_goal_animation() {
    int i;
    clear_displaytext();
    display_string(0, "    <<GOAL>>");
    display_string(1, "    <<GOAL>>");
    display_string(2, "    <<GOAL>>");
    display_string(3, "    <<GOAL>>");

    for(i = 0; i < 7; i++) {
        delay(1000000);
        PORTESET = 0b11111111;
        string_update();
        delay(1000000);
        PORTECLR = 0b11111111;
    }
}

void int_to_char2(int points, char *score) {
    int d1, d2, d3;
    d3 = (points % 10);
    d2 = (((points % 100) - d3) / 10);
    d1 = (points - d2 - d3) / 100;

    score[0] = d1+'0';
    score[1] = d2+'0';
    score[2] = d3+'0'; 
    score[3] = '\0'; 
}

void game_over_animation(score) {
    int i;
    char display_score[4]; 
    int_to_char2(score, display_score);
    clear_displaytext();
    display_string(0, "    GAME OVER");
    display_string(1, "");
    display_string(2, "SCORE:");
    display_string(3, display_score);

    for(i = 0; i < 5; i++) {
        delay(1000000);
        PORTESET = 0b11111111;
        string_update();
        delay(1000000);
        PORTECLR = 0b11111111;
    }
}

void result_animation(winner) {
    int i;
    
    clear_displaytext();
    display_string(0, "    GAME OVER");
    display_string(1, "    WINNER:");

    if(winner == 1){
        display_string(2, "    PLAYER1");
    }
    else {
        display_string(2, "    PLAYER2");
    }
    display_string(3, "");

    for(i = 0; i < 5; i++) {
        delay(1000000);
        PORTESET = 0b11111111;
        string_update();
        delay(1000000);
        PORTECLR = 0b11111111;
    }
}
