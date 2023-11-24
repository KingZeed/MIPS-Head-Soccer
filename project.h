uint8_t display[32][128]; // pixel coordinate system

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

struct Ball ball = {0, 0, 0, 0};
struct Player p1 = {0, 0, 0};
struct Player p2 = {0, 0, 0};

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

	