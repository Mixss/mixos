#include "sysutils.h"
#include "../stdio/stdio.h"

void panic(){
    print("\nkernel panic!\n\n");
    asm volatile("hlt");
}