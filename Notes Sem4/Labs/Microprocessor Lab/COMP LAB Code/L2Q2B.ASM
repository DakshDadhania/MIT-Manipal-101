data segment
d1 dw 1234h,2345h,3456h,4567h,5678h
ct equ $-d1
d2 dw 5 dup(?)
S db 02h
data ends

code segment
assume cs:code,ds:data
start:
mov ax,data
mov ds,ax
mov ax,ct
div s;
mov dl,al
mov dh,00h
mov si,offset d1
add si,ct
dec si
dec si
mov di,offset d2
add di,ct
dec di
dec di
mov cx,dx
back:
mov ax,[si]
mov [di],ax
dec si
dec si
dec di
dec di
loop back
mov ah,4ch
int 21h
code ends
end start
