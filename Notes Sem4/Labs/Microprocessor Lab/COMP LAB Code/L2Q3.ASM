data segment
a1 db 10h,11h,12h,13h,14h,15h,16h,17h,18h,19h
a2 db 20h,21h,22h,23h,24h,25h,26h,27h,28h,29h
ct db 10
data ends

code segment
assume cs:code,ds:data
start:
mov ax,data
mov ds,ax
mov si,offset a1
mov di,offset a2
mov cx,ct
exchange:
mov al,[si]
mov bl,[di]
mov [si],bl
mov [di],al
inc si
inc di
loop exchange
mov ah,4ch
int 21h
code ends
end start
