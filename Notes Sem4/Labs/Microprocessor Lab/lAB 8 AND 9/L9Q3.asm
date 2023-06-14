; Define a macro for printing a message
print macro msg
    lea dx, msg    ; Load the offset of the message into DX
    mov ah, 09h    ; Set AH register for output to screen
    int 21h        ; Output the message to the screen
endm

data segment
    ; Define strings for messages and user input
    msg1 db 'Enter the String: $'
    msg2 db 'Enter the SubString: $'
    right db 'Found$'
    wrong db 'Not Found$'
    nln db 10, 13, '$'
    String db 15 dup(0Ah)   ; Allocate buffer for user input string
    SubString db 0Fh        ; Allocate buffer for user input substring
data ends

code segment
    assume cs:code, ds:data
start:
    ; Initialize data segment registers
    mov ax, data
    mov ds, ax
    mov es, ax

    cld    ; Clear the direction flag for forward string operations

    ; Prompt user to enter the main string
    print msg1
    print nln

    lea bx, String    ; Load the offset of the String buffer into BX
    mov dx, bx        ; Load the address of the String buffer into DX
    mov ah, 0Ah       ; Set AH register for buffered input
    int 21h           ; Read user input string into buffer

    mov si, dx        ; Copy the address of the String buffer into SI

    ; Prompt user to enter the substring
    print msg2
    print nln

    lea bx, SubString    ; Load the offset of the SubString buffer into BX
    mov dx, bx           ; Load the address of the SubString buffer into DX
    mov ah, 0Ah          ; Set AH register for buffered input
    int 21h              ; Read user input substring into buffer

    mov di, dx        ; Copy the address of the SubString buffer into DI
    inc si            ; Increment SI to skip the length byte of the String buffer
    inc di            ; Increment DI to skip the length byte of the SubString buffer

    ; Initialize CX with the difference between the lengths of the String and SubString
    mov dl, [si]    ; Load the length of the String buffer into DL
    mov dh, [di]    ; Load the length of the SubString buffer into DH
    mov cx, 0h      ; Initialize CX with 0
    mov cl, dl      ; Copy DL into CL
    sub cl, dh      ; Subtract DH from CL to get the difference between the lengths
    inc cx          ; Increment CX to adjust for the length byte of the SubString buffer
    inc si          ; Increment SI to point to the first byte of the String buffer
    inc di          ; Increment DI to point to the first byte of the SubString buffer

loop1:
    ; Store the current values of CX, SI, and DI on the stack
    push cx
    push si
    push di

    ; Compare bytes of String and SubString
    mov al, [si]    ; Load a byte from the String buffer into AL
    cmp al, [di]    ; Compare it with the corresponding byte from the SubString buffer
    jne endl        ; If they don't match, jump to the end of the loop

    ; If the bytes match, loop through the SubString buffer to check for a match
    mov cx, 0h      ; Initialize CX with 0
    mov cl, dh      ; Copy DH into
	loop2:
		mov al,[si]
		cmp al,[di]
		jne endl
		inc si
		inc di
		loop loop2
		print right
		jmp exit
	endl:
	pop di
	pop si
	pop cx
	inc si
loop loop1
print wrong
exit:
mov ah,4ch
int 21h

code ends
end start