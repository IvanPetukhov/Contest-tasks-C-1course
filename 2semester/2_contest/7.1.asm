%include "io.inc"
section .bss 
    array resd 10000
    n resd 1
section .text
global CMAIN
CMAIN:
    GET_DEC 4, eax
    mov eax, dword[n]
    mov ecx, 0
.read:
    GET_DEC 4, [array+4*ecx]
    inc ecx
    cmp ecx, eax
    jl .read
    mov esi, 0
    mov edi, 0
    dec eax
    test eax, eax
    je .output
.l1:	
    mov edi, 0
    mov edx, eax
    sub edx, esi
.l2:
    mov ebx, dword[array+4*edi]
    cmp ebx, dword[array+4*edi+4]
    jle .l3
    mov ecx, dword[array+4*edi+4]
    mov dword[array+4*edi], ecx
    mov dword[array+4*edi+4], ebx
.l3:
    inc edi
    cmp edi, edx
    jl .l2
    inc esi
    cmp esi, eax
    jl .l1
    mov esi, 0
.output:
    PRINT_DEC 4, [array+4*esi]
    PRINT_CHAR ' '
    inc esi
    cmp esi, eax
    jle .output
    xor eax, eax
    ret
