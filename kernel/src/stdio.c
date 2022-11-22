#include "tty.h"
#include "stdio.h"

void putchar(char c){
    if(c == '\n') {
        terminal_column += 1;
        terminal_row = 0;
    }
    else {
        terminal_putchar(c, terminal_row, terminal_column);
        terminal_row++;
        if(terminal_row == VGA_WIDTH){
            terminal_column += 1;
            terminal_row = 0;
        }
    }
    if(terminal_column == VGA_HEIGHT+1) {
        scroll_terminal(1);
        terminal_column--;
    }
}
int get_current_terminal_row(){
    return terminal_row;
}
int get_current_terminal_column(){
    return terminal_column;
}

void set_terminal_row(int row){
    terminal_row = row;
}
void set_terminal_column(int column){
    terminal_column = column;
}

void print(char* s){
    while(*s!=0){
        putchar(*s);
        s++;
    }
}

void print_int(int value){
    if(value<0){
        putchar('-');
        value *= -1;
    }
    char digits[MAX_INT_PRINT_LENGHT]; 
    char n;
    char i=0;
    while(1){
        n = value % 10;
        digits[i] = (char)(n + 48);
        value /= 10;
        if(value == 0) break;
        i++;
    }
    for(;i>=0; i--){
        putchar(digits[i]);
    }
}