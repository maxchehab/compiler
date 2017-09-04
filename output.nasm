section .bss
digitSpace resb 100
digitSpacePos resb 8

XpWQHoCc resb 32
UpBhdxtj resb 32
qEROxgGu resb 32
dQfLmmAP resb 32
EAOrzZmT resb 32
cGuqNWcy resb 32
SXpavsEO resb 32
section .text
global _start
_start:

mov rax, 10
mov [XpWQHoCc], rax
mov rax, 15
mov [UpBhdxtj], rax
mov rax, 1
mov [qEROxgGu], rax
mov rax, 200
mov [dQfLmmAP], rax
mov rax, 1001
mov [cGuqNWcy], rax
mov rax, [EAOrzZmT]
add rax, [UpBhdxtj]
add rax, [qEROxgGu]
add rax, [dQfLmmAP]
mov [EAOrzZmT], rax
mov rax, [SXpavsEO]
add rax, [XpWQHoCc]
add rax, [EAOrzZmT]
add rax, [cGuqNWcy]
mov [SXpavsEO], rax
mov rax, [SXpavsEO]
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