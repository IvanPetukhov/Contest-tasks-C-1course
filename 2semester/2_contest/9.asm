%include "io.inc"
section .bss
    x resd 4
    y resd 4
    x0 resd 1
    y0 resd 1
section .text
global CMAIN
CMAIN:
    mov ebp, esp; for correct debugging
    xor eax, eax
.read:
    GET_DEC 4, [x+4*eax]
    GET_DEC 4, [y+4*eax]
    inc eax
    cmp eax, 4
    jne .read
    
    GET_DEC 4, x0
    GET_DEC 4, y0
    
    mov eax, 0
    mov ebx, -1000
    mov ecx, 1000
.max_x:
    cmp ebx, dword[x+4*eax]
    cmovl ebx, dword[x+4*eax]
    inc eax
    cmp eax, 4
    jl .max_x
    
    cmp ebx, dword[x0]
    jle .nope
    
    mov eax, 0
.min_x:
    cmp ecx, dword[x+4*eax]
    cmovg ecx, dword[x+4*eax]
    inc eax
    cmp eax, 4
    jl .min_x
    
    cmp ecx, dword[x0]
    jge .nope
    
    mov eax, 0
    mov ebx, -1000
    mov ecx, 1000
.max_y:
    cmp ebx, dword[y+4*eax]
    cmovl ebx, dword[y+4*eax]
    inc eax
    cmp eax, 4
    jl .max_y
    
    cmp ebx, dword[y0]
    jle .nope
    
    mov eax, 0
.min_y:
    cmp ecx, dword[y+4*eax]
    cmovg ecx, dword[y+4*eax]
    inc eax
    cmp eax, 4
    jl .min_y
    
    cmp ecx, dword[y0]
    jge .nope
    
.yes:
    PRINT_CHAR 'Y'
    PRINT_CHAR 'E'
    PRINT_CHAR 'S'
    jmp .end
.nope:
    PRINT_CHAR 'N'
    PRINT_CHAR 'O'
.end:
    xor eax, eax
    ret