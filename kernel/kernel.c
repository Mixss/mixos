#include "stdio/stdio.h"
#include "idt/idt.h"
#include "tty/tty.h"
#include "io/io.h"

extern void kernel_main(){
    idt_init();
    terminal_init();
    enable_interrupts();

    print("Welcome to mixOs!\n");
    
    return;
}