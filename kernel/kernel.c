#include "tty.h"
#include "stdio.h"

extern void kernel_main(){
    terminal_init();
    print("Notice how in the code you wished \nto use the common C function strlen, but this function is part \nof the C standard ");
    return;
}