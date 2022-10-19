#include "stdio/stdio.h"
#include "idt/idt.h"
#include "tty/tty.h"
#include "io/io.h"
#include "io/keyboard.h"



extern void kernel_main(){
    init();
    print("Welcome to mixOs!\n");
    int quit = 0;
    while(quit != 1) {
        
        int scancode = get_keyboard_scancode();
        if(scancode != 0){
            print_int(scancode);
            print("  ");
        }
   
    }
    
    return;
}



void init(){
    idt_init();
    terminal_init();
    enable_interrupts();
}