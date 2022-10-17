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

char get_char_from_video_mem(int x, int y){
    return *(video_mem + 2*x + VGA_WIDTH*y*2);
}

void scroll_terminal(int n) {
    for(int j=1; j<=VGA_HEIGHT; j++){
        for(int i=0; i<VGA_WIDTH; i++){
            char c = get_char_from_video_mem(i,j);
            terminal_putchar(c, i, j-1);
        }
    }
}