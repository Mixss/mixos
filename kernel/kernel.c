#include "stdio/stdio.h"
#include "idt/idt.h"
#include "tty/tty.h"

extern void kernel_main(){
    init();
    print("Welcome to mixOs!\n");
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