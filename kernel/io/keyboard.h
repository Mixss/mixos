#ifndef KEYBOARD_H
#define KEYBOARD_H
#include "../config.h"

// if function returns 0 it means that any key wasn't pressed/released
unsigned char get_keyboard_scancode();

#endif