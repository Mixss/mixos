#include "tty.h"

void print(char* s){
    while(*s!=0){
        putchar(*s);
        s++;
    }
}

void putchar(char c){
    if(c == '\n') {
        terminal_column += 1;
        terminal_row = 0;
        return;
    }
    terminal_putchar(c, terminal_row, terminal_column);
    terminal_row++;
    if(terminal_row == VGA_WIDTH){
        terminal_column += 1;
        terminal_row = 0;
    }
}