%include "io.inc"
section .data
    two dd 2
section .bss
    k resd 1
    x resd 1
    count resd 1
section .text
global CMAIN
CMAIN:
    mov ebp, esp; for correct debugging
    GET_DEC 4, k
    mov dword[x], 2
    mov dword[count], 1
    mov eax, dword[k]
    cmp  dword[count], eax
    jnl .endofcheck2
.cycle:
    mov eax, dword[x]
    push eax
    mov ebx, 0
    call check
    cmp eax, 1
    jne .nope
    inc dword[count]
    mov eax, dword[k]
    cmp  dword[count], eax
    jnl .endofcheck
    inc dword[x]
    pop eax
    jmp .cycle
.endofcheck:
    pop eax
 .endofcheck2:
    mov dword[x], eax
    PRINT_DEC 4, x
    xor eax, eax
    ret
    
    
.nope:
    pop eax
    inc dword[x]
    jmp .cycle
    
    
check:
    push ebp
    mov ebp, esp
    push ebx
    mov eax, [ebp+8]
    cdq
    idiv dword[two]   
    mov ecx, eax
    test ecx, ecx
    jne .L
    inc ecx
.L:
    mov eax, [ebp+8]
    cdq
    idiv ecx
    test edx, edx
    jne .p
    add ebx, ecx
.p:
    dec ecx
    cmp ecx, 0
    jg .L
    cmp ebx, [ebp+8]
    jge .zero
    mov eax, 1
    pop ebx
    mov esp, ebp
    pop ebp
    ret
.zero:
    xor eax, eax
    pop ebx
    mov esp, ebp
    pop ebp
    ret
    