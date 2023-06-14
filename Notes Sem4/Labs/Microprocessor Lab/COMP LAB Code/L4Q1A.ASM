data segment
num1 dw 1234h
num2 dw 0fee0h
res dd 0
data ends

code segment
assume cs:code,ds:data
start:
mov ax,data
mov ds,ax
mov ax,num1
mov bx,num2
mul bx
lea si,word ptr res
mov [si],dx
add si,2
mov [si],ax
mov ah,4ch
int 21h
code ends
end start
