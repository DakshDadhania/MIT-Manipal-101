data segment
num1 db 44h
num2 db 0e0h
res dw 0h
data ends

code segment
assume cs:code,ds:data
start:
mov ax,data
mov ds,ax
mov al,num1
mov bl,num2
imul bl
mov res,ax
mov ah,4ch
int 21h
code ends
end start
