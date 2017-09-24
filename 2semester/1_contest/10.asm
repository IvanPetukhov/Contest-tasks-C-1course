%include "io.inc"
section .data
    two dd 2
    fo dd 41
section .bss
    n1 resd 1
    n2 resd 1
section .text
global CMAIN
CMAIN:
    GET_DEC 4, n1
    GET_DEC 4, n2
    mov eax, dword[n1]
    sub eax, 1
    cdq
    idiv dword[two]
    mov ebx, eax
    mov eax, dword[n1]
    sub eax, 1
    imul dword[fo]
    add eax, ebx
    add eax, dword[n2]
    PRINT_DEC 4, eax
    xor eax, eax
    xor ebx, ebx
    ret