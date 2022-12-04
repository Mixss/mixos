#include "tty.h"
#include "io.h"
#include "stdio.h"
#include "string.h"
#include <stdint.h>

void terminal_handler(){
    char key = get_key();
    if(key == 0) return;
    if(key == '\b'){
        if(command_length>0){
            command_length--;
            command_buffer[command_length] = 0;
            terminal_backspace();
        }
        return;
    }
    // run the command
    if(key == '\n'){
        command_length = 0;
        command_handler(command_buffer);
        start_new_command_entry();
        return;
    }

    command_buffer[command_length] = key;
    command_length++;
    putchar(key);

}

void command_handler(char* command){
    print("\n");
    //print(command_buffer);
    if((strcmp(command_buffer, "help")) == 1){
        print("Available programs:\n");
        for(int i=0; i < *program_count; i++)
        {
            print(program_names[i]);
            print("\n");
        }
    }
    else print("Command not recognized.");
}

void start_new_command_entry(){
    for(int i=0; i<MAX_COMMAND_LENGTH; i++){
        command_buffer[i] = 0;
    }
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
    update_cursor(0,0);
}

void update_cursor(int x, int y)
{
	uint16_t pos = y * VGA_WIDTH + x;
 
	outb(0x3D4, 0x0F);
	outb(0x3D5, (uint8_t) (pos & 0xFF));
	outb(0x3D4, 0x0E);
	outb(0x3D5, (uint8_t) ((pos >> 8) & 0xFF));
}

void terminal_backspace(){
    terminal_row = get_current_terminal_row();
    terminal_column = get_current_terminal_column();
    set_terminal_row(terminal_row - 1);
    terminal_putchar(' ', terminal_row - 1, terminal_column);
    update_cursor(terminal_row - 1, terminal_column);
}

void terminal_putchar(char c, int x, int y){
    *(video_mem + 2*x + VGA_WIDTH*y*2) = c;
    update_cursor(x+1, y);
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

void set_programs(void* addresses[], char names[][8], int *number_of_programs)
{
    program_addresses = addresses;
    for(int i=0; i<8; i++)
        program_names[i] = names[i];
    
    program_count = number_of_programs;

}