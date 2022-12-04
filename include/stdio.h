#ifndef _STDIO_H
#define _STDIO_H
#define MAX_INT_PRINT_LENGHT 32

void print(char* s);
void putchar(char c);
void print_int(int value);
void print_hex(int value);
int get_current_terminal_row();
int get_current_terminal_column();
void set_terminal_row(int row);
void set_terminal_column(int column);

#endif