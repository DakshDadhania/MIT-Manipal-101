data segment
num1 dw 9876h,9354h
num2 dw 8235h,7342h
diff dw 2 dup(0)
borr db 0h
data ends

code segment
assume cs:code,ds:data
start:
mov ax,data
mov ds,ax
mov si,offset num1
mov di,offset num2
mov bx,offset diff
clc
mov ax,[si+2]
sub ax,[di+2]
das
mov [bx+2],ax
mov ax,[si]
sbb ax,[di]
das
mov [bx],ax
sbb borr,0
mov ah,4ch
int 21h 
code ends
end start
