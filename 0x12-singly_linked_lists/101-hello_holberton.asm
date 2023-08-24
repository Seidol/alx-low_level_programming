section .data
    format db `Hello, Holberton\n`, 0

section .text
    global _start

_start:
    mov   edi, format
    xor   eax, eax
    call  printf

    mov   eax, 1
    xor   edi, edi
    syscall

section .bss
    resb 1
