%include "io.inc"
section .data
    count dd 0
    two dd 2
section .bss
    n resd 1
    num resd 1
section .text
global CMAIN
CMAIN:
    mov ebp, esp; for correct debugging
    GET_DEC 4, n
    mov dword[num], 1
.L:
    call check
    add dword[count], eax
    inc dword[num]
    mov eax, dword[n]
    cmp eax, dword[count]
    jl .L
    PRINT_DEC 4, num
    xor eax, eax
    ret
    
check:
    mov ebx, dword[num]
    cdq
    idiv dword[two]
    inc eax
    mov ecx, eax; now go from 1 to ecx ebx/ecx putting ecx into summ
    xor esi, esi
    mov edi, 1
M:
    mov eax, ebx
    cdq
    idiv edi
    test edx, edx
    jne .continue
    add esi, edi
.continue:
    inc edi
    cmp edi, ecx
    jl M
    cmp ebx, esi
    jl .p
    mov eax, 0
    ret
.p:
    mov eax, 1
    ret