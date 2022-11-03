#include "stdio/stdio.h"
#include "idt/idt.h"
#include "tty/tty.h"

#include "io/disk.h"
#include "memory/memory.h"

#include "filesystem/path.h"

extern void kernel_main(){
    init();
    print("Welcome to mixOs!\n");

	// Test new features here

	struct path_root* root_path = pathparser_parse("0:/bin/shell.exe", NULL);

	if(root_path){
        print_int(1);
	}

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
