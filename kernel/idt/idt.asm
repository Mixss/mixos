section .asm

extern int21_handler

global enable_interrupts
enable_interrupts:
    sti
    ret

global disable_interrupts
disable_interrupts:
    cli
    ret

global idt_load
idt_load:
    push ebp
    mov ebp, esp

    mov ebx, [ebp+8]
    lidt [ebx]
    pop ebp
    ret

global int21
int21:
    cli
    pushad
    call int21_handler
    popad
    sti
    iret

global no_int
no_int:
    push ebp
    mov ebp, esp
    mov dx, 0x20
    mov al, 0x20

    out dx, al
    pop ebp
    iret
