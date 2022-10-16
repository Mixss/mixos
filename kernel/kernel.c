#include "stdio/stdio.h"
#include "idt/idt.h"
#include "tty/tty.h"

extern void kernel_main(){
    terminal_init();
    idt_init();

    print("Welcome to mixOs!\n");
    
    return;
}