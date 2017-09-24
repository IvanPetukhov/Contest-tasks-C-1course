%include "io.inc"
section .text
global CMAIN
CMAIN:
    GET_DEC 4, eax
    GET_DEC 4, ebx
.cycle: 
        test ebx, ebx
        je .endcycle
        cdq
        idiv ebx
        mov eax, ebx
        mov ebx, edx
        jmp .cycle
.endcycle:
    PRINT_DEC 4, eax
    xor eax, eax
    ret