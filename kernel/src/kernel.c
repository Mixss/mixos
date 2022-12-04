#include "stdio.h"
#include "idt.h"
#include "tty.h"

#include "disk.h"
#include "memory.h"

#include "program_finder.h"

extern void kernel_main(){
    init();
    print("Welcome to mixOs!!!\n");

	// Test new features here

    char program_names[MAX_NUMBER_OF_PROGRAMS][PROGRAM_NAME_SIZE];
    void *program_addresses[MAX_NUMBER_OF_PROGRAMS];
    int program_count = 0;

    unsigned char* ptr = 0x01000000;

    find_programs(0x01000000, program_addresses, program_names, &program_count);

    // int r = ((int(*)())ptr)();
    // print_int(r);
    
	// end of test area

    start_new_command_entry();

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
