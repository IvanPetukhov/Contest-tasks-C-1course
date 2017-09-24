%include "io.inc"
section .text
global CMAIN
CMAIN:
    mov ebp, esp; for correct debugging
    xor ecx, ecx
    call f
    xor eax, eax
    ret
    
f:
    GET_DEC 4, eax
    push eax
    test eax, eax
    je .end
    call f
    pop eax
    PRINT_DEC 4, eax
    PRINT_CHAR ' '
    ret
.end: 
    pop eax
    ret