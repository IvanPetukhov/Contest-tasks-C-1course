%include "io.inc"
section .bss
    N resd 1
section .text
global CMAIN
CMAIN:
    GET_DEC 4, N
    mov eax, dword[N]
    mov edx, eax
    sar edx, 31
    xor eax, edx
    sub eax, edx
    PRINT_DEC 4, eax
    xor eax, eax
    ret