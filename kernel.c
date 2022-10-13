static char* video_mem = (char*)0xb8000;
static const int VGA_WIDTH = 80;
static const int VGA_HEIGHT = 25;

int terminal_row;
int terminal_column;

void terminal_init(){
    terminal_row = 0;
    terminal_column = 1;
}

void putchar(char c){
    if(c == '\n') {
        terminal_column += 1;
        terminal_row = 0;
        return;
    }
    terminal_putchar(c, terminal_row, terminal_column);
    terminal_row++;
    if(terminal_row == VGA_WIDTH){
        terminal_column += 1;
        terminal_row = 0;
    }
}

void terminal_putchar(char c, int x, int y){
    *(video_mem + 2*x + VGA_WIDTH*y*2) = c;
}

void print(char* s){
    while(*s!=0){
        putchar(*s);
        s++;
    }
}

extern void kernel_main(){
    print("Notice how in the code you wished \nto use the common C function strlen, but this function is part \nof the C standard ");
    return;
}