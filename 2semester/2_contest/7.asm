%include "io.inc"
section .bss
    n resd 1
    a resd 10000
section .text
global CMAIN
CMAIN:
    GET_DEC 4, n
    xor eax, eax
.L: GET_DEC 4, [a+4*eax]
    inc eax
    cmp eax, dword[n]
    jne .L
    mov ecx, dword[n]
.c1:
    dec ecx
    mov eax, 0
    cmp ecx, 0
    je .end
.c2:
    mov edi, dword[a+4*eax]
    cmp edi, dword[a+4*eax+4]
    jle .c3
    mov esi, dword[a+4*eax+4]
    mov dword[a+4*eax], esi
    mov dword[a+4*eax+4], edi
.c3:
    inc eax
    cmp eax, ecx
    jnge .c2
    je .c1
    mov eax, 0
.end:
.print: 
    PRINT_DEC 4, [a+4*eax]
    PRINT_CHAR ' '
    inc eax
    cmp eax, dword[n]
    jne .print
    xor eax, eax
    ret