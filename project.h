uint8_t display[32][128]; // pixel coordinate system

void display_init();

void display_clear();

void display_dots();

void display_update();

void display_string(int line, char *s);

void string_update();

void main_menu();

int get_buttons(int button);

int get_switches(int button);
	