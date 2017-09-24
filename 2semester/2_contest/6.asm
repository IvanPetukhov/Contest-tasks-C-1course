%include "io.inc"

section .bss
    n resd 1
    k resd 1
    right resb 1
    
section .text
global CMAIN
CMAIN:
    GET_UDEC 4, n
    GET_DEC 4, k
    mov ecx, 32
    sub ecx, dword[k]
    mov ebx, 0
    mov esi, 0
    mov eax, dword[n]
    mov ebx, eax
    shl ebx, cl
    shr ebx, cl
    cmp ebx, esi
    cmovg esi, ebx
.L:  shr eax, 1    
    sub dword[n], 1
    mov ebx, eax
    shl ebx, cl
    shr ebx, cl
    cmp ebx, esi
    cmovg esi, ebx
    test eax, eax
    jne .L
    PRINT_DEC 4, esi
    xor eax, eax
    ret