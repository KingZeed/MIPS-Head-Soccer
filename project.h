#define BALL_RADIUS 3
#define PLAYER_HEIGHT 9
#define PLAYER_WEIGHT 6
#define DISPLAY_WIDTH 127
#define DISPLAY_HEIGHT 31


uint8_t display[32][128]; // pixel coordinate system

struct Ball {
    int pos_x;
    int pos_y;
    double speed_x;
    double speed_y;
};

struct Player {
    int pos_x;
    int pos_y;
    int speed;
    int rising;
    int jumping;
};

extern struct Player p1;
extern struct Player p2;
extern struct Ball ball;

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

void enter_name(int points);

void setup_lists();

void startscreen();

void clear_displaytext();

void multiplayer();

void singleplayer();

void check_player1_ball_collision();

void check_player2_ball_collision();