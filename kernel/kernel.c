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
        
        char key = get_key_pressed();
        if(key != 0){
            putchar(key);
        }
   
    }
    
    return;
}



void init(){
    idt_init();
    terminal_init();
    enable_interrupts();
}