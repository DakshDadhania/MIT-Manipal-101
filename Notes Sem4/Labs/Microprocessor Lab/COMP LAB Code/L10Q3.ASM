print macro msg
lea dx,msg
mov ah,09
int 21h
endm

disp macro num
mov dx,num
and dx,0f0h
mov cl,04h
shr dx,cl
add dl,30h
mov ah,02h
int 21h

mov dx,num
and dx,0fh
add dl,30h
mov ah,02h
int 21h
endm

data segment
sec db 00h
min db 00h
hr db 00h
conv dw 00h
colon db ' : $'
data ends

code segment
assume cs:code,ds:data
start:
mov ax,data
mov ds,ax

mov ax,0003h
int 10h
call secf

mov ah,4ch
int 21h

pwatch proc
mov bx,0h
mov bl,hr
call convert
disp conv
print colon
mov bx,0h
mov bl,min
call convert
disp conv
print colon
mov bx,0h
mov bl,sec
call convert
disp conv
call delay
mov ax,0003h
int 10h
ret
pwatch endp

secf proc
inc sec
mov bx,0h
mov bl,sec
call convert
cmp conv,60h
jne a1
call minf
a1:
call pwatch
call secf
ret
secf endp

minf proc
inc min
mov sec,00h
mov bx,0h
mov bl,min
call convert
cmp conv,60h
jne a2
call hrf
a2:
call pwatch
call secf
ret
minf endp

hrf proc
inc hr
mov min,00h
mov bx,0h
mov bl,hr
call convert
cmp conv,24h
jne a3
call reset
a3:
call pwatch
call secf
ret
hrf endp

reset proc
mov hr,00h
mov min,00h
mov sec,0h
call secf
ret
reset endp


delay proc
push si 
push di
mov si,0013h
up:
mov di,0ffffh
up1:
dec di
jnz up1
dec si
jnz up
pop di
pop si
ret
delay endp

convert proc
push bx
mov conv,0h
mov cx,0h
mov ax,bx
L1:
	 mov bh,0h
	mov bl,0ah
        div bl
        cmp al,bl
        mov dx,0h
	mov dl,ah
	push dx
	inc cx
	mov ah,0h
        JAE L1
 	mov dx,0h
	mov dl,al
	push dx
	inc cx
	back1: 
		mov bx,cx
		pop dx
		mov cl,04h
		shl conv,cl
		add conv,dx
		mov cx,bx
	loop back1
pop bx	
ret 
convert endp

code ends
end start
