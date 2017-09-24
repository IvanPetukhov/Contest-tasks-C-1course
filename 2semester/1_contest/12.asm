%include "io.inc"
section .data
    K db 'S', 'C', 'D', 'H', 'H', 'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K' 
    thirteen dd 13
section .bss
    n resd 1
section .text
global CMAIN
CMAIN:
    mov ebp, esp; for correct debugging
    GET_DEC 4, n
    mov eax, dword[n]
    sub eax, 1
    mov edx, 0
    div dword[thirteen]
    mov cl, byte[K + eax]
    mov eax, dword[n]
    mov edx, 0
    div dword[thirteen]
    mov bl, byte[K + 5 + edx]
    PRINT_CHAR bl
    PRINT_CHAR cl
    xor eax, eax
    xor ebx, ebx
    ret