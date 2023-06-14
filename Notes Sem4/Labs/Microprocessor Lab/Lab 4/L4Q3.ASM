data segment
num1 dw 5678h
num2 dw 1234h
res dd 0
data ends
code segment
assume cs:code,ds:data
start:
mov ax,data
mov ds,ax
mov ax,0000h
mov dx,0000h
clc
mov cx,num2
back:
add ax,num1
adc dx,0
loop back
lea si,word ptr res
mov [si],ax
mov [si+2],dx
int 03h
code ends
end start

