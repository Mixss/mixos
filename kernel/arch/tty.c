#include <tty.h>

void terminal_init(){
    terminal_row = 0;
    terminal_column = 1;
}

void terminal_putchar(char c, int x, int y){
    *(video_mem + 2*x + VGA_WIDTH*y*2) = c;
}