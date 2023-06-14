data segment
    Fact dw 0005h
    ans db ?
data ends

code segment
    assume cs:code, ds:data
start:
    mov ax, data
    mov ds, ax
    mov ax, 0001h
    mov dx, 00h
    mov al, byte ptr [Fact]

    call fact       

    mov byte ptr [ans], dl 
    mov ah, 4ch     
    int 21h

fact proc:
    push ax         
    cmp al, 01h       
    jz down:         
    sub al, 1      
    call fact       
    pop bx         
    mul dl           
    ret
down:
    mov dl, al      
    pop ax         
fact endp

code ends
end start
