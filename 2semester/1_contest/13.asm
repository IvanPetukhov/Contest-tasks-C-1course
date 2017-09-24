%include "io.inc"
section .data
    H db 'H'
    eight db '8'
section .bss
    a_l resb 1
    a_n resb 1
    b_l resb 1
    b_n resb 1
section .text
;abs(- a + b))+abs(- a + b))
global CMAIN
CMAIN:
    GET_CHAR a_l
    GET_CHAR a_n
    GET_CHAR b_l
    GET_CHAR b_l
    GET_CHAR b_n
    movzx eax, byte[b_l]
    movzx ebx, byte[a_l]
    sub eax, ebx; b_l - a_l
    mov edx, eax; abs(b_l - a_l)
    sar edx, 31
    xor eax, edx
    sub eax, edx
    movzx ecx, byte[b_n]
    movzx edx, byte[a_n]
    sub ecx, edx; b_n - a_n
    mov ebx, ecx; abs(b_n - a_n)
    sar ebx, 31
    xor ecx, ebx
    sub ecx, ebx
    add eax, ecx
    PRINT_DEC 4, eax
    xor eax, eax
    xor ebx, ebx
    xor ecx, ecx
    xor edx, edx
    ret