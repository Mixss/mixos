#ifndef TTY_H
#define TTY_H

static char* video_mem = (char*)0xb8000;
static const int VGA_WIDTH = 80;
static const int VGA_HEIGHT = 25;

static int terminal_row;
static int terminal_column;

void terminal_init();
void terminal_putchar(char c, int x, int y);
char get_char_from_video_mem(int x, int y);
void scroll_terminal(int n); // scroll terminal n lines down

#endif