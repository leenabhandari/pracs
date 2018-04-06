section .data

msg1 db "Enter string",10
msg1len equ $-msg1
msg2 db "entered string is: ",10
msg2len equ $-msg2
msg3 db "Length of sring is: ",10
msg3len equ $-msg3

section .bss
string resb 10
len_hex resb 1
len_ascii resb 1

section .text
global _start
_start:

mov eax,4
mov ebx,1
mov ecx,msg1
mov edx,msg1len
int 80h

mov eax,3
mov ebx,0
mov ecx,string
mov edx,10
int 80h

dec eax
mov[len_hex],eax
cmp eax,09h
jbe AA30
add eax,07h
AA30:add eax,30h
mov[len_ascii],eax

mov eax,4
mov ebx,1
mov ecx,msg2
mov edx,msg2len
int 80h

mov eax,4
mov ebx,1
mov ecx,string
mov edx,[len_hex]
int 80h

mov eax,4
mov ebx,1
mov ecx,msg3
mov edx,msg3len
int 80h

mov eax,4
mov ebx,1
mov ecx,len_ascii
mov edx,4
int 80h

mov eax,1
mov ebx,0
int 80h
