data segment
num1 dw 1234h,5678h
num2 dw 8765h,4321h
sum dw 2 dup(0)
carry db 0h
data ends

code segment
assume cs:code,ds:data
start:
mov ax,data
mov ds,ax
mov si,offset num1
mov di,offset num2
mov bx,offset sum
clc
mov ax,[si+2]
add ax,[di+2]
daa
mov [bx+2],ax
mov ax,[si]
adc ax,[di]
daa
mov [bx],ax
adc carry,0

mov ah,4ch
int 21h

code ends
end start
