#include "stdio/stdio.h"
#include "idt/idt.h"
#include "tty/tty.h"

#include "io/disk.h"
#include "memory/memory.h"

#include "io/diskstream.h"

extern void kernel_main(){
    init();
    print("Welcome to mixOs!\n");

	// Test new features here

    struct disk_stream* stream = diskstream_new(0);
    diskstreamer_seek(stream, 0x201);
    unsigned char c = 0;
    diskstreamer_read(stream, &c, 1);

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
