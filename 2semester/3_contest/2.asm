%include "io.inc"
section .data
    three dd 3
    s dd 0
section .bss
    x resd 1
section .text
global CMAIN
CMAIN:
    GET_UDEC 4, x
    mov ecx, dword[x]
    mov edx, dword[s]
    sub esp, 8
    mov dword[esp], ecx
    mov dword[esp+4], edx
    call f
    add esp, 8
    PRINT_DEC 4, s
    xor eax, eax
    ret
f:
    push ebp
    mov ebp, esp
    mov eax, [ebp+8]
    mov edx, 0
    div dword[three]
    cmp edx, 1
    jne .l
    inc dword[s]
.l: 
    cmp eax, 0
    je .end
    sub esp, 4
    mov [esp], eax
    call f
    add esp, 4
.end:
    pop ebp
    ret