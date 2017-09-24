%include "io.inc"
section .data
    x0 dd 0
    x1 dd 0xFFFFFFFF
    y0 dd 0
    y1 dd 0xFFFFFFFF
section .bss
    a_11 resd 1
    a_12 resd 1
    a_21 resd 1
    a_22 resd 1
    b1 resd 1
    b2 resd 1
    mask1 resd 1
    mask2 resd 1
    mask3 resd 1
    x resd 1
    y resd 1

section .text
global CMAIN
CMAIN:
    mov ebp, esp; for correct debugging
    GET_UDEC 4, a_11
    GET_UDEC 4, a_12
    GET_UDEC 4, a_21
    GET_UDEC 4, a_22
    GET_UDEC 4, b1
    GET_UDEC 4, b2
    ;running throug 4 variants: (x,y)-> (0,0) (0,1) (1,0) (1,1)
    ;first one is useless
    ;getting mask1(for (0,1)):
    mov eax, dword[a_11]
    and eax, dword[x0]
    mov ebx, dword[a_12]
    and ebx, dword[y1]
    xor eax, ebx
    xor eax, dword[b1]
    
    mov ebx, dword[a_21]
    and ebx, dword[x0]
    mov ecx, dword[a_22]
    and ecx, dword[y1]
    xor ebx, ecx
    xor ebx, dword[b2]
    
    or eax, ebx
    not eax
    mov dword[mask1], eax
    ;getting mask1(for (1,0)):
    mov eax, dword[a_11]
    and eax, dword[x1]
    mov ebx, dword[a_12]
    and ebx, dword[y0]
    xor eax, ebx
    xor eax, dword[b1]
    
    mov ebx, dword[a_21]
    and ebx, dword[x1]
    mov ecx, dword[a_22]
    and ecx, dword[y0]
    xor ebx, ecx
    xor ebx, dword[b2]
    
    or eax, ebx
    not eax
    mov dword[mask2], eax
    ;getting mask1(for (1,1)):
    mov eax, dword[a_11]
    and eax, dword[x1]
    mov ebx, dword[a_12]
    and ebx, dword[y1]
    xor eax, ebx
    xor eax, dword[b1]
    
    mov ebx, dword[a_21]
    and ebx, dword[x1]
    mov ecx, dword[a_22]
    and ecx, dword[y1]
    xor ebx, ecx
    xor ebx, dword[b2]
    
    or eax, ebx
    not eax
    mov dword[mask3], eax
    ;now that we got all the masks, we hav to calculate x, y
    ;in masks we have '1', where bit value is right.
    ;so x = m3 | m2
    ;y = m3 | m1&~m2
    mov eax, dword[mask3]
    or eax, dword[mask2]
    mov dword[x], eax
    
    mov eax, dword[mask2]
    mov ebx, dword[mask3]
    not eax
    and eax, dword[mask1]
    or eax, ebx
    mov dword[y], eax
    PRINT_UDEC 4, x
    PRINT_CHAR ' '
    PRINT_UDEC 4, y
    xor eax, eax
    xor ebx, ebx
    xor ecx, ecx
    ret