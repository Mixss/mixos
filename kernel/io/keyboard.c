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

unsigned char get_key(){
    unsigned char scancode = get_keyboard_scancode();
    int* shift_pressed = KEYBOARD_SHIFT_HOLD_ADDRESS;

    if(scancode == 0) return 0;
    // handling shift holding
    if(scancode == SCAN_CODE_PRESSED_SHIFT_LEFT) {
        *shift_pressed = 1;
        return 0;
    }
    if(scancode == SCAN_CODE_RELEASED_LEFT_SHIFT) {
        *shift_pressed = 0;
        return 0;
    }

    if(*shift_pressed == 0) { //shift is not pressed
        if(scancode == SCAN_CODE_PRESSED_1) return '1';
        if(scancode == SCAN_CODE_PRESSED_2) return '2';
        if(scancode == SCAN_CODE_PRESSED_3) return '3';
        if(scancode == SCAN_CODE_PRESSED_4) return '4';
        if(scancode == SCAN_CODE_PRESSED_5) return '5';
        if(scancode == SCAN_CODE_PRESSED_6) return '6';
        if(scancode == SCAN_CODE_PRESSED_7) return '7';
        if(scancode == SCAN_CODE_PRESSED_8) return '8';
        if(scancode == SCAN_CODE_PRESSED_9) return '9';
        if(scancode == SCAN_CODE_PRESSED_0) return '0';
        if(scancode == SCAN_CODE_PRESSED_DASH) return '-';
        if(scancode == SCAN_CODE_PRESSED_EQUALS) return '=';
        if(scancode == SCAN_CODE_PRESSED_Q) return 'q';
        if(scancode == SCAN_CODE_PRESSED_W) return 'w';
        if(scancode == SCAN_CODE_PRESSED_E) return 'e';
        if(scancode == SCAN_CODE_PRESSED_R) return 'r';
        if(scancode == SCAN_CODE_PRESSED_T) return 't';
        if(scancode == SCAN_CODE_PRESSED_Y) return 'y';
        if(scancode == SCAN_CODE_PRESSED_U) return 'u';
        if(scancode == SCAN_CODE_PRESSED_I) return 'i';
        if(scancode == SCAN_CODE_PRESSED_O) return 'o';
        if(scancode == SCAN_CODE_PRESSED_P) return 'p';
        if(scancode == SCAN_CODE_PRESSED_OPEN_SQUARE_BRACKET) return '[';
        if(scancode == SCAN_CODE_PRESSED_CLOSE_SQUARE_BRACKET) return ']';
        if(scancode == SCAN_CODE_PRESSED_A) return 'a';
        if(scancode == SCAN_CODE_PRESSED_S) return 's';
        if(scancode == SCAN_CODE_PRESSED_D) return 'd';
        if(scancode == SCAN_CODE_PRESSED_F) return 'f';
        if(scancode == SCAN_CODE_PRESSED_G) return 'g';
        if(scancode == SCAN_CODE_PRESSED_H) return 'h';
        if(scancode == SCAN_CODE_PRESSED_J) return 'j';
        if(scancode == SCAN_CODE_PRESSED_K) return 'k';
        if(scancode == SCAN_CODE_PRESSED_L) return 'l';
        if(scancode == SCAN_CODE_PRESSED_SEMICOLON) return ';';
        if(scancode == SCAN_CODE_PRESSED_APOSTROPHE) return '\'';
        if(scancode == SCAN_CODE_PRESSED_GRAVIS) return '`';
        if(scancode == SCAN_CODE_PRESSED_Z) return 'z';
        if(scancode == SCAN_CODE_PRESSED_X) return 'x';
        if(scancode == SCAN_CODE_PRESSED_C) return 'c';
        if(scancode == SCAN_CODE_PRESSED_V) return 'v';
        if(scancode == SCAN_CODE_PRESSED_B) return 'b';
        if(scancode == SCAN_CODE_PRESSED_N) return 'n';
        if(scancode == SCAN_CODE_PRESSED_M) return 'm';
        if(scancode == SCAN_CODE_PRESSED_COMMA) return ',';
        if(scancode == SCAN_CODE_PRESSED_DOT) return '.';
        if(scancode == SCAN_CODE_PRESSED_SLASH) return '/';
        if(scancode == SCAN_CODE_PRESSED_BACKSLASH) return '\\';
    }
    else { //shift is pressed
        if(scancode == SCAN_CODE_PRESSED_1) return '!';
        if(scancode == SCAN_CODE_PRESSED_2) return '@';
        if(scancode == SCAN_CODE_PRESSED_3) return '#';
        if(scancode == SCAN_CODE_PRESSED_4) return '$';
        if(scancode == SCAN_CODE_PRESSED_5) return '%';
        if(scancode == SCAN_CODE_PRESSED_6) return '^';
        if(scancode == SCAN_CODE_PRESSED_7) return '&';
        if(scancode == SCAN_CODE_PRESSED_8) return '*';
        if(scancode == SCAN_CODE_PRESSED_9) return '(';
        if(scancode == SCAN_CODE_PRESSED_0) return ')';
        if(scancode == SCAN_CODE_PRESSED_DASH) return '_';
        if(scancode == SCAN_CODE_PRESSED_EQUALS) return '+';
        if(scancode == SCAN_CODE_PRESSED_Q) return 'Q';
        if(scancode == SCAN_CODE_PRESSED_W) return 'W';
        if(scancode == SCAN_CODE_PRESSED_E) return 'E';
        if(scancode == SCAN_CODE_PRESSED_R) return 'R';
        if(scancode == SCAN_CODE_PRESSED_T) return 'T';
        if(scancode == SCAN_CODE_PRESSED_Y) return 'Y';
        if(scancode == SCAN_CODE_PRESSED_U) return 'U';
        if(scancode == SCAN_CODE_PRESSED_I) return 'I';
        if(scancode == SCAN_CODE_PRESSED_O) return 'O';
        if(scancode == SCAN_CODE_PRESSED_P) return 'P';
        if(scancode == SCAN_CODE_PRESSED_OPEN_SQUARE_BRACKET) return '{';
        if(scancode == SCAN_CODE_PRESSED_CLOSE_SQUARE_BRACKET) return '}';
        if(scancode == SCAN_CODE_PRESSED_A) return 'A';
        if(scancode == SCAN_CODE_PRESSED_S) return 'S';
        if(scancode == SCAN_CODE_PRESSED_D) return 'D';
        if(scancode == SCAN_CODE_PRESSED_F) return 'F';
        if(scancode == SCAN_CODE_PRESSED_G) return 'G';
        if(scancode == SCAN_CODE_PRESSED_H) return 'H';
        if(scancode == SCAN_CODE_PRESSED_J) return 'J';
        if(scancode == SCAN_CODE_PRESSED_K) return 'K';
        if(scancode == SCAN_CODE_PRESSED_L) return 'L';
        if(scancode == SCAN_CODE_PRESSED_SEMICOLON) return ':';
        if(scancode == SCAN_CODE_PRESSED_APOSTROPHE) return '"';
        if(scancode == SCAN_CODE_PRESSED_GRAVIS) return '~';
        if(scancode == SCAN_CODE_PRESSED_Z) return 'Z';
        if(scancode == SCAN_CODE_PRESSED_X) return 'X';
        if(scancode == SCAN_CODE_PRESSED_C) return 'C';
        if(scancode == SCAN_CODE_PRESSED_V) return 'V';
        if(scancode == SCAN_CODE_PRESSED_B) return 'B';
        if(scancode == SCAN_CODE_PRESSED_N) return 'N';
        if(scancode == SCAN_CODE_PRESSED_M) return 'M';
        if(scancode == SCAN_CODE_PRESSED_COMMA) return '<';
        if(scancode == SCAN_CODE_PRESSED_DOT) return '>';
        if(scancode == SCAN_CODE_PRESSED_SLASH) return '?';
        if(scancode == SCAN_CODE_PRESSED_BACKSLASH) return '|';
    }
    
    if(scancode == SCAN_CODE_PRESSED_ESCAPE) return '\x1';
    if(scancode == SCAN_CODE_PRESSED_BACKSPACE) return '\b';
    if(scancode == SCAN_CODE_PRESSED_TAB) return '\t';
    if(scancode == SCAN_CODE_PRESSED_RETURN) return '\n';
    if(scancode == SCAN_CODE_PRESSED_CTRL) return '\x1d';
    if(scancode == SCAN_CODE_PRESSED_SHIFT_LEFT) return '\x2a';
    if(scancode == SCAN_CODE_PRESSED_SHIFT_RIGHT) return '\x36';
    if(scancode == SCAN_CODE_PRESSED_ALT) return '\x38';
    if(scancode == SCAN_CODE_PRESSED_SPACE) return ' ';
    if(scancode == SCAN_CODE_PRESSED_CAPS_LOCK) return '\x3a';
    if(scancode == SCAN_CODE_PRESSED_F1) return '\x3b';
    if(scancode == SCAN_CODE_PRESSED_F2) return '\x3c';
    if(scancode == SCAN_CODE_PRESSED_F3) return '\x3d';
    if(scancode == SCAN_CODE_PRESSED_F4) return '\x3e';
    if(scancode == SCAN_CODE_PRESSED_F5) return '\x3f';
    if(scancode == SCAN_CODE_PRESSED_6) return '\x40';
    if(scancode == SCAN_CODE_PRESSED_7) return '\x41';
    if(scancode == SCAN_CODE_PRESSED_8) return '\x42';
    if(scancode == SCAN_CODE_PRESSED_9) return '\x43';
    if(scancode == SCAN_CODE_PRESSED_F10) return '\x44';
    return 0; //if key press is not defined (or it is release) function returns value indicating that none key was pressed
}