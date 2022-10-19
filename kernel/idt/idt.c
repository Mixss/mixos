#include "idt.h"
#include "config.h"
#include "../stdio/stdio.h"
#include "memory/memory.h"
#include "../sysutils/sysutils.h"
#include "../io/io.h"

struct idt_desc idt_descriptors[512];
struct idtr_desc idtr_descriptor;

extern void idt_load(struct idtr_desc* ptr);

extern void int21();
extern void no_int();

void int21_handler(){
    
    unsigned char* scancode_address = KEYBOARD_SCAN_CODE_VALUE_ADDRESS;

    outb(0x20, 0x20);
    unsigned char code = insb(0x60);

    // putting scan code pressed to special address
    *scancode_address = code;
}

void no_interrupt_handler(){
    outb(0x20, 0x20);
}

void idt_zero()
{
    print("Division by zero!\n");
    panic();
}

void idt_set(int interrupt_no, void* address)
{
    struct idt_desc* desc = &idt_descriptors[interrupt_no];
    desc->offset_1 = (uint32_t) address & 0x0000ffff;
    desc->selector = KERNEL_CODE_SELECTOR;
    desc->zero = 0x00;
    desc->type_attr = 0xEE;
    desc->offset_2 = (uint32_t) address >> 16;
}

void idt_init()
{
    remap_PIC(32, 40);
    memset(idt_descriptors, 0, sizeof(idt_descriptors));
    idtr_descriptor.limit = sizeof(idt_descriptors) -1;
    idtr_descriptor.base = (uint32_t) idt_descriptors;

    for(int i=0; i<TOTAL_INTERRUPTS; i++){
        idt_set(i, no_int);
    }

    idt_set(0, idt_zero);
    idt_set(0x21, int21);

    idt_load(&idtr_descriptor);
}

static inline void io_wait(){
    outb(0x80, 0);
}

void remap_PIC(int offset1, int offset2){
    unsigned char a1, a2;

    a1 = insb(PIC1_DATA);
    a2 = insb(PIC2_DATA);

    outb(PIC1_COMMAND, ICW1_INIT | ICW1_ICW4);
    io_wait();
    outb(PIC2_COMMAND, ICW1_INIT | ICW1_ICW4);
    io_wait();
    outb(PIC1_DATA, offset1);                 // ICW2: Master PIC vector offset
	io_wait();
	outb(PIC2_DATA, offset2);                 // ICW2: Slave PIC vector offset
	io_wait();
    outb(PIC1_DATA, 4);                       // ICW3: tell Master PIC that there is a slave PIC at IRQ2 (0000 0100)
	io_wait();
	outb(PIC2_DATA, 2);                       // ICW3: tell Slave PIC its cascade identity (0000 0010)
	io_wait();
 
	outb(PIC1_DATA, ICW4_8086);
	io_wait();
	outb(PIC2_DATA, ICW4_8086);
	io_wait();
 
	outb(PIC1_DATA, a1);   // restore saved masks.
	outb(PIC2_DATA, a2);
}