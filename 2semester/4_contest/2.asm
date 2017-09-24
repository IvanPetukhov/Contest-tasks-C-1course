%include "io.inc"
section .bss
    s1 resd 1001
    s2 resd 1001
section .data
    fc db "%s", 0
section .text
CEXTERN scanf
CEXTERN printf
CEXTERN malloc
CEXTERN strstr
global CMAIN
CMAIN:
    mov ebp, esp
    and esp, -16
    sub esp, 16
    
    mov dword[esp], 1001
    call malloc
    mov dword[s1], eax
    
    mov ebx, dword[s1]
    mov dword[esp], fc
    mov dword[esp+4], ebx
    call scanf
    
    mov dword[esp], 1001
    call malloc
    mov dword[s2], eax
    
    mov edx, dword[s2]
    mov dword[esp], fc
    mov dword[esp+4], edx
    call scanf
    
    mov ebx, dword[s1]
    mov edx, dword[s2]
    mov dword[esp], ebx
    mov dword[esp+4], edx
    call strstr
    cmp eax, 0
    jne .second_in_first
    
    mov ebx, dword[s1]
    mov edx, dword[s2]
    mov dword[esp], edx
    mov dword[esp+4], ebx
    call strstr
    cmp eax, 0
    jne .first_in_second
    
    mov ebx, dword[s1]
    mov dword[ebx], "0"
    mov dword[esp], fc
    mov dword[esp+4], ebx
    call printf
    jmp .end

.first_in_second:
    mov ebx, dword[s1]
    mov dword[ebx], "1 2"
    mov dword[esp], fc
    mov dword[esp+4], ebx
    call printf
    jmp .end
    
.second_in_first:
    mov ebx, dword[s1]
    mov dword[ebx], "2 1"
    mov dword[esp], fc
    mov dword[esp+4], ebx
    call printf
    jmp .end
    
.end:
    mov esp, ebp
    xor eax, eax
    ret