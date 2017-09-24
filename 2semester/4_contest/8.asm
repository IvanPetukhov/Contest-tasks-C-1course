%include "io.inc"
section .bss
    x resd 1000
    n resd 1
    f_in resd 1
    f_out resd 1
section .data
    count dd 0
section .rodata
    fname_in db "input.txt", 0
    fmode_in db "r", 0
    fmt_in db "%d", 0
    fname_out db "output.txt", 0
    fmode_out db "w", 0
    fmt_out db "%d ", 0
section .text
compare:
    push ebp
    mov ebp, esp
    mov eax, dword [ebp + 12]
    mov eax, dword [eax]
    mov ecx, dword [ebp + 8]
    mov ecx, dword [ecx]
    cmp eax, ecx
    jl .next_greater
    je .next_equal
    
    mov eax, -1
    jmp .end
.next_greater:
    mov eax, 1
    jmp .end
.next_equal:
    xor eax, eax
.end:
    mov esp, ebp
    pop ebp
    ret
    
global CMAIN
CEXTERN fopen
CEXTERN fclose
CEXTERN fscanf
CEXTERN fprintf
CEXTERN qsort

CMAIN:
    mov ebp, esp
    
    and esp, -16
    sub esp, 16
    
    mov dword[esp], fname_in
    mov dword[esp+4], fmode_in
    call fopen
    mov dword[f_in], eax

    mov dword[esp], fname_out
    mov dword[esp+4], fmode_out
    call fopen
    mov dword[f_out], eax
.scan:
    mov eax, dword[f_in]
    mov dword[esp], eax
    mov dword[esp+4], fmt_in
    mov ebx, dword[count]
    lea eax, [x + 4*ebx]
    mov dword[esp+8], eax
    call fscanf
    cmp eax, -1
    je .end_of_scan
    inc dword[count]
    jmp .scan
    
.end_of_scan:
    mov eax, dword[count]
    mov dword[n], eax
    
    mov dword[esp], x
    mov eax, dword[n]
    mov dword[esp+4], eax
    mov dword[esp+8], 4 
    mov dword[esp+12], compare
    call qsort
    
    dec dword[n]
    mov dword[count], 0
    
.print:
    mov eax, dword[f_out]
    mov dword[esp], eax
    mov dword[esp + 4], fmt_out
    mov eax, dword[count]
    mov eax, [x+4*eax]
    mov dword[esp + 8], eax
    call fprintf
    mov eax, dword[n]
    cmp eax, dword[count]
    je .final
    inc dword[count]
    jmp .print
     
.final:  
    mov eax, dword[f_in]      
    mov dword[esp], eax
    call fclose
    
    mov eax, dword[f_out]
    mov dword[esp], eax
    call fclose
    
    add esp, 16
    mov esp, ebp
    xor eax, eax
    ret