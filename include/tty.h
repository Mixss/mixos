#ifndef TTY_H
#define TTY_H

#define MAX_COMMAND_LENGTH 128
#define MAX_NUMBER_OF_PROGRAMS 16

static char* video_mem = (char*)0xb8000;
static const int VGA_WIDTH = 80;
static const int VGA_HEIGHT = 25;

static int terminal_row;
static int terminal_column;

static int command_length = 0;
static char command_buffer[MAX_COMMAND_LENGTH];

static char *program_names[8];
static void **program_addresses;
static int *program_count;

void terminal_init();
void terminal_putchar(char c, int x, int y);
char get_char_from_video_mem(int x, int y);
void scroll_terminal(int n); // scroll terminal n lines down
void terminal_handler();
void start_new_command_entry();
void terminal_backspace();
void command_handler(char* command);
void update_cursor(int x, int y);
void set_programs( void* program_addresses[], char program_names[][8], int *number_of_programs);

#endif