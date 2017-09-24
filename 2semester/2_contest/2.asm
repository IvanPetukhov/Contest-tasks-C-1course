%include "io.inc"

section .bss
    a resd 1
section .text
global CMAIN
CMAIN:
    mov ebp, esp; for correct debugging
    GET_UDEC 4, a
    mov eax, dword[a]
    xor ebx, ebx
    mov ecx, 32
L:  bt eax, ecx
    adc ebx, 0
    loop L
    PRINT_DEC 4, ebx
    xor eax, eax
    ret