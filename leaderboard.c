#include <pic32mx.h>
#include <stdint.h>
#include "project.h"

char leaderboard_list[9][10];
char alphabet[26];

/* Clear all  strings in display */
void clear_displaytext() {
    display_string(0, " ");
    display_string(1, " ");
    display_string(2, " ");
    display_string(3, " ");
}

/* Resetting and setup leaderboard */
void clear_leaderboardlist() {
    int i, j;
    for(i = 0; i < 9; i++) {
        for(j = 0; j < 4;j++) {

            if(j == 0) {
                leaderboard_list[i][j] = 49+i; //converting i to a number
            }
            if(j == 1) {
                leaderboard_list[i][j] = '.';
            }
            if(j == 9) {
                leaderboard_list[i][j] = '\0';
            }
            else {
                 leaderboard_list[i][j] = ' ';
            }
           
        }
    }
}

/* Set up everything */
void setup_lists() {
    clear_displaytext();
    clear_leaderboardlist();
    sort_leaderboard();
    int i;
    // Insert letters in alphabet 
    for(i = 0; i < 26; i++){
        alphabet[i] = 65+i;
    }
}

/* Updates leaderboard on display */
void update_leaderboardlist(int line){
    display_string(0, leaderboard_list[line]);
    display_string(1, leaderboard_list[line+1]);
    display_string(2, leaderboard_list[line+2]);
    display_string(3, leaderboard_list[line+3]);
}

/* Function that display the leaderboard */
/* User can scroll through using BTN 1 and 2 */
void show_leaderboard() {

    int line = 0;

    update_leaderboardlist(line);

    while (1)
    {
        string_update();
        // Go down in leaderboard 
        if (get_button(1) && line != 5) { 
            while (get_button(1)){}
            line++;
            update_leaderboardlist(line);  
        }
        // Go upp in leaderboard 
        if (get_button(2) && line != 0) {
            while (get_button(2)){}
            line--;
            update_leaderboardlist(line);
        }
        if (get_button(3)) {
            while (get_button(3)){}
            main_menu();
            
        }
       
    }
    
}

/* Calculate the score from a user */
int list_points(char arr[10]) {
    int sum = 0;
    sum += arr[6] * 100;
    sum += arr[7] * 10;
    sum += arr[8];
    return sum;
}

/* translate a 3 digit positve int to a char list */
void int_to_char(int points, char *score) {
    int d1, d2, d3;
    d3 = (points % 10);
    d2 = (((points % 100) - d3) / 10);
    d1 = (points - d2 - d3) / 100;

    score[0] = d1+'0';
    score[1] = d2+'0';
    score[2] = d3+'0'; 
}

/* swap rows in leaderboard */
void swapRows(char arr[][10], int row1, int row2) {
    char temp[10];
    int i;
    for (i = 0; i < 10; ++i) {
        temp[i] = arr[row1][i];
        arr[row1][i] = arr[row2][i];
        arr[row2][i] = temp[i];
    }
}

/* Give each score a rank number */
void rank_leaderboard() {
    int i;
    for(i = 0; i < 9; i++){
        leaderboard_list[i][0] = i + '1';
        leaderboard_list[i][1] = '.';
    }
}

/* sort leaderboard using bubblesort */
void sort_leaderboard() {
    int i,j;
    int swapped;
    for(i = 0; i < 9; i++) {
        
        swapped = 0;
        for(j = 0; j < 9 - i - 1; j++) {
            if (list_points(leaderboard_list[j]) < list_points(leaderboard_list[j+1])) {
                swapRows(leaderboard_list, j, j+1);
                swapped = 1;
            }
        }
        if (!swapped) {
            break;
        }
            
    }
    rank_leaderboard();
}

/* Saves the name and inserts it to leaderboard */
void save_name(int points, char *name) {
    int i,j;
    char score[3];
    
    
    int_to_char(points, score);
    
    /* Put in the points and name in the last position in leaderboard */


    for(i = 0; i < 3; i++) {
        leaderboard_list[8][2+i] = name[i];
    }

    leaderboard_list[8][5] = ' ';
    leaderboard_list[8][6] = score[0];
    leaderboard_list[8][7] = score[1];
    leaderboard_list[8][8] = score[2];
    

    delay(10000);
    sort_leaderboard();
    show_leaderboard();
}

/* enter the name and insert in leaderboard list */
void enter_name(int points){

    int name_pos = 0;
    int alphabet_pos = 0;
    char name[4] = {'A',' ',' ','\0'};
    char current_char = alphabet[0];
    clear_displaytext();
    display_string(0, "Enter name");
    display_string(1, "BTN2 < > BTN1");
    display_string(2, " ");
    display_string(3, name);

    while(1) {
        
        string_update();
        
        if (get_button(4)){
            while (get_button(4)){}
            
            save_name(points, name);
            delay(50000);
        }
        else if(get_button(1) && name_pos < 3){
            while (get_button(1)){}
            if (alphabet_pos == 25){
                alphabet_pos = 0;
            }
            else {
                alphabet_pos++;
            }
            name[name_pos] = alphabet[alphabet_pos];
            display_string(3, name);
            string_update();
            delay(50000);
        }
        else if(get_button(2) && name_pos < 3){
            while (get_button(2)){}
            if (alphabet_pos == 0){
                alphabet_pos = 25;
            }
            else {
                alphabet_pos--;
            }
            
            name[name_pos] = alphabet[alphabet_pos];
            display_string(3, name);
            string_update();
            delay(50000);
        }
        else if(get_button(3) && name_pos < 3){
            while (get_button(3)){}
            name_pos++;
            alphabet_pos = 0;
            if(name_pos < 3){
                name[name_pos] = alphabet[alphabet_pos];
                display_string(3, name);
            }
           
            string_update();
            delay(50000);
        }
        
        
    }

}

int check_leaderboard(int points) {
        char score[3];
        int_to_char(points, score);

        int sum = 0;
        sum += score[0] * 100;
        sum += score[1] * 10;
        sum += score[2];

        if(sum > list_points(leaderboard_list[8])) {
            return 1;
        }
        return 0;
        
}










