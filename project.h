#define BALL_RADIUS 3
#define PLAYER_HEIGHT 9
#define PLAYER_WIDTH 6
#define DISPLAY_WIDTH 127
#define DISPLAY_HEIGHT 31

uint8_t display[32][128]; // pixel coordinate system

struct Ball {
    int pos_x;
    int pos_y;
    float speed_x;
    float speed_y;
};

struct Player {
    int pos_x;
    int pos_y;
    int speed;
};

extern struct Player p1;
extern struct Player p2;
extern struct Ball ball;

void check_jump_player1();

void check_jump_player2();

void delay(int cyc);

void check_barriar_collision();

void move_ball();

void hardbot_thinking();

void easybot_thinking();

void display_init();

void display_clear();

void display_dots();

void display_update();

void display_string(int line, char *s);

void string_update();

void draw_left_goal();

void draw_right_goal();

void draw_ball(int x, int y);

void draw_player1(int x, int y);

void draw_player2(int x, int y);

int get_button(int button_number);

int get_button(int button_number);

int get_switchtoggle(int switch_number);

void show_leaderboard();

void check_player1_inputs();

void check_player2_inputs();

int check_leaderboard(int points);

void int_to_char(int points, char *score);

void enter_name(int points);

void setup_lists();

void startscreen();

void clear_displaytext();

void multiplayer();

void singleplayer();

void goal(int player);

void reset_pos(int player);
void check_player1_ball_collision();

void check_player2_ball_collision();

void check_player1_inputs_singleplayer();
