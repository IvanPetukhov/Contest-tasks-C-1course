%include "io.inc"
section .bss
    s1 resd 101
    s2 resd 101
    symb resd 1
    length resd 1
    length2 resd 1
section .data
    fc1 db "%s", 0
    fc db "%c", 0
section .text
CEXTERN scanf
CEXTERN printf
CEXTERN malloc
CEXTERN strstr
CEXTERN strlen
global CMAIN
CMAIN:
    mov ebp, esp
    and esp, -16
    sub esp, 16
    
    mov dword[esp], 101
    call malloc
    mov dword[s1], eax
    
    mov ebx, dword[s1]
    mov dword[esp], fc1
    mov dword[esp+4], ebx
    call scanf
    
    mov dword[esp], 1001
    call malloc
    mov dword[s2], eax
    
    mov edx, dword[s2]
    mov dword[esp], fc1
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
    mov dword[esp], fc1
    mov dword[esp+4], ebx
    call printf
    jmp .end

.first_in_second:
    mov dword[symb], eax
    
    mov ebx, dword[s1]
    mov dword[esp], ebx
    call strlen
    mov dword[length], eax

    mov ebx, dword[s2]
    mov dword[esp], ebx
    call strlen
    mov dword[length2], eax
.put_before:    
    mov ebx, dword[s2]
    mov dword[esp], fc
    mov dword[esp+4], ebx
    call printf
    
    add dword[s2], 1
    mov ebx, dword[s2]
    cmp ebx, dword[symb]
    jl .put_before
    
    mov ebx, dword[s1]
    mov dword[ebx], '['
    mov dword[esp], fc
    mov dword[esp+4], ebx
    call printf
    
    mov eax, dword[strlen]
    add dword[symb], eax
    
.put_middle:
    mov ebx, dword[s2]
    mov dword[esp], fc
    mov dword[esp+4], ebx
    call printf
    
    add dword[s2], 1
    mov ebx, dword[s2]
    cmp ebx, dword[symb]
    jl .put_middle
    
    mov ebx, dword[s1]
    mov dword[ebx], ']'
    mov dword[esp], fc
    mov dword[esp+4], ebx
    call printf
    
    mov eax, dword[length2]
    mov dword[symb], eax
.put_end:
    mov ebx, dword[s2]
    mov dword[esp], fc
    mov dword[esp+4], ebx
    call printf
    
    add dword[s2], 1
    mov ebx, dword[s2]
    cmp ebx, dword[symb]
    jl .put_end
    
    jmp .end
    
.second_in_first:
    mov dword[symb], eax
    
    mov ebx, dword[s2]
    mov dword[esp], ebx
    call strlen
    mov dword[length], eax

    mov ebx, dword[s1]
    mov dword[esp], ebx
    call strlen
    mov dword[length2], eax
.putbefore:    
    mov ebx, dword[s1]
    mov dword[esp], fc
    mov dword[esp+4], ebx
    call printf
    
    add dword[s1], 1
    mov ebx, dword[s1]
    cmp ebx, dword[symb]
    jl .putbefore
    
    mov ebx, dword[s2]
    mov dword[ebx], '['
    mov dword[esp], fc
    mov dword[esp+4], ebx
    call printf
    
    mov eax, dword[strlen]
    add dword[symb], eax
    
.putmiddle:
    mov ebx, dword[s1]
    mov dword[esp], fc
    mov dword[esp+4], ebx
    call printf
    
    add dword[s1], 1
    mov ebx, dword[s1]
    cmp ebx, dword[symb]
    jl .putmiddle
    
    mov ebx, dword[s2]
    mov dword[ebx], ']'
    MOV DWORD[ESP], fc
    mov dword[esp+4], ebx
    call printf
    
    mov eax, dword[length2]
    mov dword[symb], eax
.putend:
    mov ebx, dword[s1]
    mov dword[esp], fc
    mov dword[esp+4], ebx
    call printf
    
    add dword[s1], 1
    mov ebx, dword[s1]
    cmp ebx, dword[symb]
    jl .putend
    
    jmp .end
    
.end:
    mov esp, ebp
    xor eax, eax
    ret