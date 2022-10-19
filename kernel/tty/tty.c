#include "tty.h"
#include "../io/io.h"
#include "../stdio/stdio.h"
void terminal_handler(){
    char key = get_key_pressed();
    if(key == 0) return;
    if(key == '\b'){
        if(command_length>0){
            command_length--;
            terminal_backspace();
        }
        return;
    }
    command_length++;
    putchar(key);

}

void start_new_command_entry(){
    print("\n> ");
}

void terminal_init(){
    terminal_row = 0;
    terminal_column = 0;

    for(int i=0; i<VGA_HEIGHT; i++){
        for(int j=0; j<VGA_WIDTH; j++){
            terminal_putchar(' ', j, i);
        }
    }

    // disable cursor
    outb(0x3D4, 0x0A);
	outb(0x3D5, 0x20);
}

void terminal_backspace(){
    terminal_row = get_current_terminal_row();
    terminal_column = get_current_terminal_column();
    set_terminal_row(terminal_row - 1);
    terminal_putchar(' ', terminal_row - 1, terminal_column);
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