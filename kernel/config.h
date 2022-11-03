#ifndef CONFIG_H
#define CONFIG_H

#define KERNEL_CODE_SELECTOR 0x08
#define KERNEL_DATA_SELECTOR 0x10

#define TOTAL_INTERRUPTS 255

#define OS_MEMORY_START_ADDRESS 0x7E00
#define KEYBOARD_SCAN_CODE_VALUE_ADDRESS 0x7E00
#define KEYBOARD_CAPS_LOCK_ON_ADDRESS 0x7E04
#define KEYBOARD_SHIFT_HOLD_ADDRESS 0x7E08

#define MAX_PATH_LENGTH 127

#endif