%include "io.inc"
section .bss
     n resd 1
     x resd 1
     y resd 1
     x1 resd 1
     y1 resd 1
     c resd 1
     
section .text
GLOBAL CMAIN
CMAIN:
    mov ebp, esp; for correct debugging
    GET_DEC 4, n
    mov ecx, dword[n]
    dec ecx
    GET_DEC 4, x
    GET_DEC 4, y
    cmp ecx, 0
    je .onlyend
.L:
    GET_DEC 4, x1
    GET_DEC 4, y1
    mov eax, dword[y]
    mov ebx, dword[y1]
    call f
    mov dword[c], eax
    mov eax, dword[x1]
    imul dword[y]
    cdq
    idiv dword[c]
    mov esi, eax
    mov eax, dword[x]
    imul dword[y1]
    cdq
    idiv dword[c]
    add esi, eax
    mov eax, dword[y1]
    imul dword[y]
    cdq
    idiv dword[c]
    mov edi, eax
    dec ecx
    mov dword[x], esi
    mov dword[y], edi
    cmp ecx, 0
    jne .L
    
    mov eax, dword[x]
    mov ebx, dword[y]
    
    call f
    
    mov dword[c], eax
    
    mov eax, dword[x]
    cdq
    idiv dword[c]
    PRINT_DEC 4, eax
    PRINT_CHAR ' '
    
    mov eax, dword[y]
    cdq
    idiv dword[c]
    PRINT_DEC 4, eax
    xor eax, eax
    ret
    
.onlyend:
    PRINT_DEC 4, x
    PRINT_CHAR ' '
    PRINT_DEC 4, y
    xor eax, eax
    ret
   
f:
.cycle:
    test ebx, ebx
    je .endcycle
    cdq
    idiv ebx
    mov eax, ebx
    mov ebx, edx
    jmp .cycle
.endcycle:
    ret