numc macro a,b
mov bh,10h
mov cl,b
mov al,a
mul bh
mov dx,0h
mov ch,0h
mov dx,cx
add ax,dx
endm

data segment
num1 dw 0h
num2 dw 0h
num db 0h
diff dw 0h
first db 'Input First Number:$'
second db 'Input Second Number:$'
res db 'UP/DOWN COUNTER:$'
data ends

code segment
assume cs:code,ds:data
start:
mov ax,data
mov ds,ax

mov ax,0h
lea dx,first
mov ah,09
int 21h
call input
cmp al,41h
jl L000
sub al,37h
jmp E0
L000:
sub al,30h
E0:
mov bl,al
call input
cmp al,41h
jl L111
sub al,37h
jmp E1
L111:
sub al,30h
E1:
numc bl,al
mov num1,ax
mov dl,10
mov ah,02
int 21h


lea dx,second
mov ah,09
int 21h
call input
cmp al,41h
jl L222
sub al,37h
jmp E2
L222:
sub al,30h
E2:
mov bl,al
call input
cmp al,41h
jl L333
sub al,37h
jmp E3
L333:
sub al,30h
E3:
numc bl,al
mov num2,ax
mov dl,10
mov ah,02
int 21h


mov ax,num2
add ax,num1
mov diff,ax
inc diff


lea dx,res
mov ah,09
int 21h
mov dl,10
mov ah,02
int 21h

mov ax,0h
mov bx,num1
dec bx
call upc

mov ah,4ch
int 21h

input proc
mov ah,01
int 21h
ret
input endp

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

downc proc
dec bl
mov cx,bx
sub cx,num1
inc cx
back:
	push cx
	mov num,bl
	call disp
	dec bl
	call delay
	pop cx
MOV DL,0FFH
 MOV AH,06
 INT 21H
 JNZ DOWN 
	jmp l0
DOWN: 
	CMP AL,13
 	Jz l0
cmp al,30h
jne exit
inc bl
call upc
l0: 
loop back

exit:
mov ah,4ch
int 21h
ret 
downc endp

upc proc
inc bx
mov cx,num2
sub cx,bx
inc cx
back0:
	push cx
      mov num,bl
	call disp
	inc bl
	call delay
	pop cx
MOV DL,0FFH
 MOV AH,06
 INT 21H
JNZ DOWN0 
	jmp l
DOWN0: 
	CMP AL,13
 	JZ l
cmp al,30h
jne exit0
dec bl
call downc
l:
loop back0

exit0:
mov ah,4ch
int 21h
ret 
upc endp

disp proc
mov dl,num
and dl,0f0h
mov cl,04h
shr dl,cl
cmp dl,09h
ja p00
add dl,30h
jmp p11
p00:
add dl,37h
p11:
mov ah,02h
int 21h

mov dl,num
and dl,0fh
cmp dl,09h
ja p22
add dl,30h
jmp p33
p22:
add dl,37h
p33:
mov ah,02h
int 21h

mov dl,10
mov ah,02h
int 21h
ret
disp endp

code ends
end start
