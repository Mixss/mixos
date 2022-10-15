#include "tty.h"

void terminal_init(){
    terminal_row = 0;
    terminal_column = 0;

    for(int i=0; i<VGA_HEIGHT; i++){
        for(int j=0; j<VGA_WIDTH; j++){
            terminal_putchar(' ', j, i);
        }
    }
}

void terminal_putchar(char c, int x, int y){
    *(video_mem + 2*x + VGA_WIDTH*y*2) = c;
}