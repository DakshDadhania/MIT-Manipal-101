data segment
num1 db 25h
num2 db 75h
sum db 0h
carry db 0h
data ends

code segment
assume cs:code,ds:data
start:
mov ax,data
mov ds,ax
mov al,num1
mov bl,num2
clc
add al,bl
daa
mov sum,al
adc carry,0

mov ah,4ch
int 21h

code ends
end start