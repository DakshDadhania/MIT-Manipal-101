data segment
num1 db 21h,22h,23h,24h,25h,26h,27h,28h,29h,30h
num2 db 11h,12h,13h,14h,15h,16h,17h,18h,19h,20h
diff db 10 dup(0)
borr db 0h
ct dw 0010h
data ends

code segment
assume cs:code,ds:data
start:
mov ax,data
mov ds,ax
mov si,offset num1
mov di,offset num2
mov bx,offset diff
mov cx,0000h
clc
mov cx,ct
back:
mov al,[si]
mov dl,[di]
sbb al,dl
das
mov [bx],al
dec si
dec di
dec bx
loop back
sbb borr,0
mov ah,4ch
int 21h
code ends
end start
