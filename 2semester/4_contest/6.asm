%include "io.inc"
section .bss
    f_in resd 1
    f_out resd 1
    x resd 1
section .data
section .rodata
    fname_in db "input.bin", 0
    fname_out db "output.bin", 0
    fmode_in db "rb", 0
    fmode_out db "wb", 0
section .text
CEXTERN fopen
CEXTERN fclose
CEXTERN fread
CEXTERN fwrite
CEXTERN malloc
;CEXTERN free
global CMAIN
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
        
    
    add esp, 16
    mov esp, ebp
    xor eax, eax
    ret