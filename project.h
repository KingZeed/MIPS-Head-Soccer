#define BALL_RADIUS 3
#define PLAYER_HEIGHT 9
#define PLAYER_WEIGHT 6
#define GROUND_LEVEL 31


uint8_t display[32][128]; // pixel coordinate system

struct Ball {
    int pos_x;
    int pos_y;
    int speed_x;
    int speed_y;
    int acceleration_x;
    int acceleration_y;
    int gravity;
};

struct Player {
    int pos_x;
    int pos_y;
    int speed;
};

extern struct Player p1;
extern struct Player p2;
extern struct Ball ball;


void move_ball();

void check_ground_collision();

void display_init();

void display_clear();

void display_dots();

void display_update();

void display_string(int line, char *s);

void string_update();

void main_menu();

void draw_left_goal();

void draw_right_goal();

void draw_ball(int x, int y);

void draw_player1(int x, int y);

void draw_player2(int x, int y);

int get_button(int button_number);

int get_switchtoggle(int switch_number);

	