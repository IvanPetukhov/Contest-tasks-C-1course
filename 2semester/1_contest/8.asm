%include "io.inc"
section .bss
    a resd 1
    b resd 1
    c resd 1
    d resd 1
section .text
global CMAIN
CMAIN:
    ;d = (c & a) + (~c & b)
    GET_HEX 4, a
    GET_HEX 4, b
    GET_HEX 4, c
    mov eax, dword[a]
    and eax, dword[c]
    mov ecx, dword[c]
    not ecx
    mov ebx, dword[b]
    and ebx, ecx
    add eax, ebx
    mov dword[d], eax
    PRINT_HEX 4, eax
    xor eax, eax
    ret