;To run this assembly code, save this text as output.nasm and run the following command:
;nasm -f elf64 -o output.o output.nasm && ld -o output output.o && ./output

section .bss
digitSpace resb 100
digitSpacePos resb 8

XpWQHoCc resb 32
LzeoMlfs resb 32
qEROxgGu resb 32
section .text
global _start
_start:

mov rax, 10
mov [XpWQHoCc], rax
mov rax, 12
mov [LzeoMlfs], rax
mov rax, [qEROxgGu]
add rax, [XpWQHoCc]
add rax, [LzeoMlfs]
mov [qEROxgGu], rax
mov rax, [qEROxgGu]
call _printRAX


	
mov rax, 60
     mov rdi, 0
     syscall


_printRAX:
     mov rcx, digitSpace
     mov rbx, 10
     mov [rcx], rbx
     inc rcx
     mov [digitSpacePos], rcx

_printRAXLoop:
     mov rdx, 0
     mov rbx, 10
     div rbx
     push rax
     add rdx, 48

     mov rcx, [digitSpacePos]
     mov [rcx], dl
     inc rcx
     mov [digitSpacePos], rcx

     pop rax
     cmp rax, 0
     jne _printRAXLoop

_printRAXLoop2:
     mov rcx, [digitSpacePos]

     mov rax, 1
     mov rdi, 1
     mov rsi, rcx
     mov rdx, 1
     syscall

     mov rcx, [digitSpacePos]
     dec rcx
     mov [digitSpacePos], rcx

     cmp rcx, digitSpace
     jge _printRAXLoop2

     ret