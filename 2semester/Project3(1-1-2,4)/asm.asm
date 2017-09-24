EXTERN _count_compare
EXTERN _count_move

global _timestamp
global _compare
global _swap

section .text
global _timestamp
_timestamp:
    RDTSC
    ret
    
global _compare
_compare:
    push ebp
    mov ebp, esp
    mov eax, dword[ebp + 8]
    mov ecx, dword[ebp + 12]
    cmp eax, ecx
    jge .return0
    mov eax, 1
    inc dword[_count_compare]
    mov esp, ebp
    pop ebp
    ret
.return0:
    mov eax, 0
    inc dword[_count_compare]
    mov esp, ebp
    pop ebp
    ret
    
global _swap
_swap:
    push ebp
    mov ebp, esp
    push ebx
    mov eax, dword[ebp + 8]
    mov edx, dword[eax]
    mov ecx, dword[ebp + 12]
    mov ebx, dword[ecx]
    mov dword[eax], ebx
    mov dword[ecx], edx
    inc dword[_count_move]
    push ebx
    mov esp, ebp
    pop ebp
    ret