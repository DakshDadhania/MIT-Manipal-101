disp macro num
mov dl,num
and dl,0f0h
mov cl,04h
shr dl,cl
cmp dl,09h
ja l00
add dl,30h
jmp l11
l00:
add dl,37h
l11:
mov ah,02h
int 21h

mov dl,num
and dl,0fh
cmp dl,09h
ja l22
add dl,30h
jmp l33
l22:
add dl,37h
l33:
mov ah,02h
int 21h

mov dl,10
mov ah,02h
int 21h
endm

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
diff dw 0h
first db 'Input First Number:$'
second db 'Input Second Number:$'
res db 'DOWN COUNTER:$'
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
jl L0
sub al,37h
jmp E0
L0:
sub al,30h
E0:
mov bl,al
call input
cmp al,41h
jl L1
sub al,37h
jmp E1
L1:
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
jl L2
sub al,37h
jmp E2
L2:
sub al,30h
E2:
mov bl,al
call input
cmp al,41h
jl L3
sub al,37h
jmp E3
L3:
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

mov bx,num1
mov cx,diff
back:
	push cx
	disp bl
	dec bl
	call delay
	pop cx
MOV DL,0FFH
 MOV AH,06
 INT 21H
 JNZ DOWN 
	JMP l
DOWN: 
	CMP AL,13
 	JNZ exit
l:
loop back

exit:
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

code ends
end start
