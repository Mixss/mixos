#include "keyboard.h"

// if function returns 0 it means that any key wasn't pressed/released
unsigned char get_keyboard_scancode(){
    unsigned char* scancode_addr = KEYBOARD_SCAN_CODE_VALUE_ADDRESS;
    unsigned char key = *scancode_addr;
    if(key != 0){
        *scancode_addr = 0x00;
        return key;
    }
    return 0;
}