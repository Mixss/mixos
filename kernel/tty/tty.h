#ifndef TTY_H
#define TTY_H

#define MAX_COMMAND_LENGTH 128

static char* video_mem = (char*)0xb8000;
static const int VGA_WIDTH = 80;
static const int VGA_HEIGHT = 25;

static int terminal_row;
static int terminal_column;

static int command_length = 0;
static char command_buffer[MAX_COMMAND_LENGTH];

void terminal_init();
void terminal_putchar(char c, int x, int y);
char get_char_from_video_mem(int x, int y);
void scroll_terminal(int n); // scroll terminal n lines down
void terminal_handler();
void start_new_command_entry();
void terminal_backspace();
void command_handler(char* command);
void update_cursor(int x, int y);

#endif