data segment
sum dw 0h
carry dw 0h
data ends

code segment
assume cs:code,ds:data
start:
mov ax,data
mov ds,ax
mov ax,1234h
mov bx,2345h
clc
add ax,bx
mov sum,ax
adc carry,0
	
mov ah,4ch
int 21h

code ends 
end start