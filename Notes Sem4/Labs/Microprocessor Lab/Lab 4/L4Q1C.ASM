data segment
num1 dw 1234h
num2 dw 0fee0h
res db 0
data ends
code segment
assume cs:code,ds:data
start:
mov ax,data
mov ds,ax
mov ax,num1
mov bx,num2
imul bx
lea si,word ptr res
mov [si],ax
add si,2
mov [si],dx
mov ah,4ch
int 21h
code ends
end start
