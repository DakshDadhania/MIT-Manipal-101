data segment
num1 dw 0ff34h
num2 db 0feh
quo db 0
rem db 0
data ends
code segment
assume cs:code,ds:data
start:
mov ax,data
mov ds,ax
mov ax,num1
mov bl,num2
idiv bl
mov quo,al
mov rem,ah
mov ah,4ch
int 21h
code ends
end start
