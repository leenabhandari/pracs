section .data
nline db 10,10
nline_len equ $-nline
arr dd -11111111H,22222222H,-33333333H,44444444H,-55555555H
arr_size equ 5

pmsg db 10,10,"Positiver numbers: "
pmsg_len equ $-pmsg
nmsg db 10,10,"Negetive numbers: "
nmsg_len equ $-nmsg

section .bss
p_count resq 1
n_count resq 1
dispbuff resb 08

%macro display 2
mov rax,01
mov rdi,01
mov rsi,%1
mov rdx,%2
syscall
%endmacro

section .text
global _start
_start:

mov esi,arr
mov ecx,5
mov ebx,0
mov edx,0

next_num:
mov eax,[esi]
rol eax,1
jc negetive

positive:
inc ebx
jmp next
negetive:
inc edx
next:
add esi,4
loop next_num
mov [p_count],ebx
mov [n_count],edx
display pmsg,pmsg_len
mov ebx,[p_count]
call disp32_proc

display nmsg,nmsg_len
mov ebx,[n_count]
call disp32_proc
display nline,nline_len

exit: mov rax,60
mov rbx,00
syscall

disp32_proc:
mov edi,dispbuff
mov ecx,08

dispup1:
rol ebx,4
mov dl,bl
and dl,0fh
add dl,30h
cmp dl,39h
jbe dispskip1
add dl,07h

dispskip1:
mov [edi],dl
inc edi
loop dispup1
display dispbuff,8
ret

