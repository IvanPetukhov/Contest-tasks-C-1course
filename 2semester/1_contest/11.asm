%include "io.inc"
section .data
    max db 'H'
    eight db '8'
    two dd 2
section .bss
    a resb 1
    b resb 1
    c resd 1
section .text
global CMAIN
CMAIN:
    ;(('H' - a)*('8' - b))/2
    GET_CHAR a
    GET_CHAR b
    GET_CHAR c
    movzx ebx, byte[b]
    movzx ecx, byte[c]
    movzx edx, byte[a]
    movzx eax, byte[max]
    sub eax, edx
    movzx edx, byte[eight]
    sub edx, ebx
    mov ebx, edx
    mov edx, 0
    imul ebx
    cdq
    idiv dword[two]
    PRINT_DEC 4, eax
    xor eax, eax
    xor ebx, ebx
    xor ecx, ecx
    xor edx, edx
    ret