uint8_t display[32][128]; // pixel coordinate system

void display_init();

void display_clear();

void display_dots();

void display_update();

void display_string(int line, char *s);

void string_update();

void main_menu();

void draw_left_goal();

void draw_right_goal();

void draw_ball();

void draw_player1();

void draw_player2();

int get_button(int button_numbe);

int get_switchtoggle(int switch_number);

	