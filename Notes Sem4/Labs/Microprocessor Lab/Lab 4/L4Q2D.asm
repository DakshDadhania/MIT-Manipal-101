data segment
num1 dd 70a0ff34h
num2 dw 0fff4h
quo dd 0h
rem dw 0h
data ends
code segment
assume cs:code,ds:data
start:
mov ax,data
mov ds,ax
mov dx,0000h
mov cx,num2
mov si,offset num1
mov ax,[si+2]
idiv cx
mov di,offset quo
mov [di+1],ax
mov ax,[si]
idiv cx
mov [di],ax
mov bx,offset rem
mov [bx],dx
mov ah,4ch
int 21h
code ends
end start
