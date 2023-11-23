uint8_t display[32][128];		// Readable for humans

void display_init();

void display_clear();

void display_dots();

void display_update();

void display_string(int line, char *s);

void string_update();

void main_menu();

void draw_left_goal();

void draw_right_goal();

void draw_ball_center();

void draw_player1_start_pos();

void draw_player2_start_pos();
	