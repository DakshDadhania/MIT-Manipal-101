data segment
num1 dw,11B4h
data ends

code segment
assume cs:code,ds:data
start:
mov ax,data
mov ds,ax 

mov ax,num1
mov bx,ax

mov ah,4ch
int 21h
code ends
end start
