#include "stdio/stdio.h"
#include "idt/idt.h"
#include "tty/tty.h"
#include "io/disk.h"

extern void kernel_main(){
    init();
    print("Welcome to mixOs!\n");
    start_new_command_entry();

    char buffer[512];
    disk_read_sector(0, 1, buffer);


    int quit = 0;
    while(quit != 1) {
        
        terminal_handler();
        
   
    }
    
    return;
}



void init(){
    idt_init();
    terminal_init();
    enable_interrupts();
}