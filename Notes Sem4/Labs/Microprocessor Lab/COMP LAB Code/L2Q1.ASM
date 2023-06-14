data segment
array1 db 45h,0bh,79h,10h,9ah,11h,12h,13h,14h,15h
ct equ $-array1
org 1
array2 db ct dup(?)
data ends

code segment
assume cs:code,ds:data
start:
mov ax,data
mov ds,ax

mov si,offset array1
add si,ct
dec si
mov di,offset array2
add di,ct
dec di
mov cx,ct
back:
mov al,[si]
mov [di],al
dec si
dec di
loop back

mov ah,4ch
int 21h
code ends
end start
