section .data
msg1 db "enter 1st number: ",10
msg1len equ $-msg1
msg2 db "enter 2nd number: ",10
msg2len equ $-msg2


section .bss

dispbuff resb 04
numascii resb 03
num1 resb 02
num2 resb 02
result resb 02

%macro display 2
mov rax,01
mov rdi,01
mov rsi,%1
mov rdx,%2
syscall
%endmacro

%macro accept 2
mov rax,00
mov rdi,00
mov rsi,%1
mov rdx,%2
syscall
%endmacro

section .text

global _start
_start:

display msg1,msg1len
accept numascii,03
call packnum
mov byte[num1],bl

display msg2,msg2len
accept numascii,03
call packnum
mov byte[num2],bl

mov al,[num1]
mov bl,[num2]
mov cl,00h
mov edx,08
pro1:
rcr al,01
jnc skipit
mov bh,00h
shl bx,cl
add [result],bx
mov bl,[num2]
skipit:
inc cl
dec edx
jnz pro1
mov bx,[result]
call disp16

mov rax,60
mov rdi,00
syscall



packnum:
mov ecx,02
mov esi,numascii
mov bx,00h
back22:
rol bx,04
mov al,[esi]
sub al,30h
cmp al,09h
jbe next2
sub al,07h
next2:
add bl,al
inc esi
loop back22
ret


disp16:
mov ecx,04
mov edi,dispbuff
loop3:
rol bx,04
mov dl,bl
and dl,0Fh
cmp dl,09h
jbe next
add dl,07h
next:
add dl,30h
mov [edi],dl
inc edi
loop loop3
display dispbuff,04
ret
