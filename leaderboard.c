#include <pic32mx.h>
#include <stdint.h>
#include "project.h"

char leaderboard_list[10][6];
char alphabet[25];

void clear_displaytext() {
    display_string(0, " ");
    display_string(1, " ");
    display_string(2, " ");
    display_string(3, " ");
}

void clear_leaderboardlist() {
    int i, j;
    for(i = 0; i < 10; i++) {
        for(j = 0; j < 4;j++) {

            if(j == 0) {
                 leaderboard_list[i][j] = 49+i; //converting i to a number
            }
            if(j == 1) {
                 leaderboard_list[i][j] = '.';
            }
            if(j == 5) {
                 leaderboard_list[i][j] = '\0';
            }
           
        }
    }
}

void setup_lists() {
    clear_displaytext();
    clear_leaderboardlist();
    int i;
    for(i = 0; i < 25; i++){
        alphabet[i] = 65+i;
    }
}

void update_leaderboardlist(int line){
    display_string(0, leaderboard_list[line]);
    display_string(1, leaderboard_list[line+1]);
    display_string(2, leaderboard_list[line+2]);
    display_string(3, leaderboard_list[line+3]);
}

void show_leaderboard() {

    
    
    int line = 0;

    leaderboard_list[0][2] = 'f';
    leaderboard_list[0][3] = 'i';
    leaderboard_list[0][4] = 'r';
    leaderboard_list[0][5] = '\0';

    leaderboard_list[1][2] = 's';
    leaderboard_list[1][3] = 'e';
    leaderboard_list[1][4] = 'c';
    leaderboard_list[1][5] = '\0';

    leaderboard_list[2][2] = 't';
    leaderboard_list[2][3] = 'h';
    leaderboard_list[2][4] = 'i';
    leaderboard_list[2][5] = '\0';

    leaderboard_list[3][2] = 'f';
    leaderboard_list[3][3] = 'o';
    leaderboard_list[3][4] = 'u';
    leaderboard_list[3][5] = '\0';

    leaderboard_list[4][2] = 'f';
    leaderboard_list[4][3] = 'i';
    leaderboard_list[4][4] = 'f';
    leaderboard_list[4][5] = '\0';

    update_leaderboardlist(line);

    while (1)
    {
        string_update();
        /* Go down in leaderboard */
        if (get_button(1) && line != 5) { 
            line++;
            update_leaderboardlist(line);  
        }
        /* Go upp in leaderboard */
        if (get_button(2) && line != 0) {
            line--;
            update_leaderboardlist(line);
        }
        delay(500000);
    }
    
}


void enter_name(){

    setup_lists();
    int name_pos = 0;
    int alphabet_pos = 0;
    char name[4] = {65,32,32,'\0'};
    char current_char = alphabet[0];
    clear_displaytext();
    display_string(0, "Enter name");
    display_string(1, "BTN2 < > BTN1");
    display_string(2, "BTN3 to store");
    display_string(3, name);

    while(1) {
        
        string_update();
        
        if (get_button(3) && name_pos == 3){
            save_name();
        }
        else if(get_button(1) && alphabet_pos != 24){
            alphabet_pos++;
            name[name_pos] = alphabet[alphabet_pos];
            display_string(3, name);
        }
        else if(get_button(2) && alphabet_pos != 0){
            alphabet_pos--;
            name[name_pos] = alphabet[alphabet_pos];
            display_string(3, name);
        }
        else if(get_button(3)){
            name_pos++;
            alphabet_pos = 0;
            name[name_pos] = alphabet[alphabet_pos];
        }
        
        delay(700000);
    }

}


void save_name() {
    display_string(0, "SAVED");
    
    while (1)
    {
        string_update();
    }
    
}





