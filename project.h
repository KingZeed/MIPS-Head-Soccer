uint8_t display[32][128]; // pixel coordinate system

void delay(int cyc);

void display_init();

void display_clear();

void display_dots();

void display_update();

void display_string(int line, char *s);

void string_update();

void main_menu();

void draw_left_goal();

void draw_right_goal();

int get_button(int button_number);

int get_switchtoggle(int switch_number);

void show_leaderboard();

void enter_name(int points);