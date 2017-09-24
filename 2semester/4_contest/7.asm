%include "io.inc"
section .bss
    strings resb 5500
    check resb 500
    n resd 1
section .data
    count dd 0
    length dd 0
    run dd 0
    result dd 0    
section .rodata
    fc db "%s", 0
    fd db "%d", 0

section .text
CEXTERN scanf
CEXTERN printf
CEXTERN strcmp
global CMAIN
CMAIN:
    mov ebp, esp
    and esp, -16
    sub esp, 16

    mov dword[esp], fd
    mov dword[esp+4], n
    call scanf

    dec dword[n]
.L:
    mov dword[esp], fc
    mov eax, dword[count]
    imul eax, 11
    lea ebx, [strings+eax]
    mov dword[esp+4], ebx
    call scanf

    inc dword[count]
    mov eax, dword[count]
    cmp eax, dword[n]
    jle .L

    mov dword[count], 0
.cmp_cycle:
    mov eax, dword[count]
    mov byte[check+eax], 0
    mov dword[run], eax
.lp:
    mov eax, dword[run]
    imul eax, 11
    lea ebx, [strings+eax]
    mov eax, dword[count]
    imul eax, 11
    lea eax, [strings+eax]
    mov dword[esp], ebx
    mov dword[esp+4], eax
    call strcmp

    jnz .l1p
    mov eax, dword[count]
    inc byte[check+eax]
.l1p:
    inc dword[run]
    mov eax, dword[run]
    cmp eax, dword[n]
    jg .end_little
    jmp .lp
.end_little:
    inc dword[count]
    mov eax, dword[count]
    cmp eax, dword[n]
    jg .end
    jmp .cmp_cycle
.end:
    mov dword[count], 0
.recheck:
    mov eax, dword[count]
    cmp byte[check+eax], 1
    jg .M
    inc dword[result]
.M:
    inc dword[count]
    mov eax, dword[count]
    cmp eax, dword[n]
    jle .recheck

    cmp dword[result], 0
    jne .print
    mov dword[esp], fd
    mov dword[esp+4], 1
    call printf
    jmp .final
    
.print:
    mov dword[esp], fd
    mov eax, dword[result]
    mov dword[esp+4], eax
    call printf

.final:
    add esp, 16
    mov esp, ebp
    xor eax, eax
    ret