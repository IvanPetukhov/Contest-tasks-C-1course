%include "io.inc"
section .data
    b dd 2011
section .bss
x resd 1
m resd 1
n resd 1
y resd 1
section .text
global CMAIN
CMAIN:
    mov ebp, esp; for correct debugging
    GET_DEC 4, x; reading x(a number of books that are already in the library)
    GET_DEC 4, n; reading n()
    GET_DEC 4, m
    GET_DEC 4, y
    mov ebx, dword[y]
    sub ebx, 2011
    mov eax, dword[n]
    sub eax, dword[m]
    imul ebx
    add eax, dword[x]
    PRINT_DEC 4, eax
    xor eax, eax
    ret