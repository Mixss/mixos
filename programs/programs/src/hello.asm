[BITS 32]
section .asm

hello:
    push ebp
    mov ebp, esp
    mov eax, 420
    pop ebp
    ret