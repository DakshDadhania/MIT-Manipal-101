data segment
diff dw 0h
borr db 0h
data ends

code segment
assume cs:code,ds:data
start:
mov ax,data
mov ds,ax
mov si,[0005]
mov [si],1234h
mov di,[0007]
mov [di],4565h
mov ax,[di]
mov dx,[si]
clc
sub ax,dx
sbb borr,0
mov diff,ax

mov ah,4ch
int 21h
code ends
end start
