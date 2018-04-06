section .data
msg db "enter 1 for hex2bcd and 2 for bcd2hex",10
msglen equ $-msg
bcd db "bcd val is: ",10
bcdlen equ $-bcd
hex db "hex num is: ",10
hexlen equ $-hex
bcdin db "enter bcd: ",10
bcdinlen equ $-bcdin

hexin db "enter hex: ",10
hexinlen equ $-hexin

section .bss

dispbuff resb 04
numascii resb 03
opbuff resb 05

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

display msg,msglen
accept numascii,2
cmp byte [numascii],'1'
jne not1
call hex2bcd
jmp not2
not1:
call bcd2hex
not2:

mov rax,60
mov rdi,00
syscall

bcd2hex:
display bcdin,bcdinlen
accept numascii,6

mov rsi,numascii
mov rcx,05
mov rax,00
mov ebx,0ah
bcag:
mov rdx,00h
mul ebx
mov dl,[rsi]
sub dl,30h
add rax,rdx
inc rsi
loop bcag
mov ebx,eax
call disp32
ret

packnum:
mov ecx,04
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

hex2bcd:
display hexin,hexinlen
accept numascii,5
call packnum
mov bx,ax
mov rcx,0
mov bx,10
rem:
mov dx,0
div bx
push rdx
inc rcx
cmp ax,0
jne rem
mov rdi,opbuff
there:
pop rdx
add dl,30h
mov [rdi],dl
inc rdi
loop there

display opbuff,5
ret 

disp32:
mov rcx,08
mov rdi,dispbuff
loop3:
rol ebx,04
mov dl,bl
and dl,0Fh
cmp dl,09h
jbe next
add dl,07h
next:
add dl,30h
mov [rdi],dl
inc rdi
loop loop3
display dispbuff,08
ret
