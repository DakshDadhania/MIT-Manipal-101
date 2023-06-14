print macro msg    ; Define a macro to print a message
lea dx,msg        ; Load the address of the message into DX
mov ah,09         ; Set the print function
int 21h           ; Print the message
endm              ; End the macro

data segment       ; Define the data segment
msg1 db 'Enter the String: $'  ; Prompt message for input
msg2 db 'After Toggle Case: $'  ; Output message
nln db 10,13,'$'   ; Define a newline character
enter db 20 dup(0ffh)  ; Define the input string variable
final db 0h        ; Define the output string variable
data ends         ; End the data segment

code segment       ; Define the code segment
assume cs:code,ds:data   ; Set the segment registers
start:            ; Start of the program

mov ax,data       ; Move the data segment address to AX
mov ds,ax         ; Move the value in AX to DS
mov es,ax         ; Move the value in AX to ES

lea di,final      ; Load the offset of final into DI
cld               ; Clear the direction flag

print msg1        ; Print the prompt for string input
print nln         ; Print a newline

lea bx,enter      ; Load the offset of enter into BX
mov dx,bx         ; Move the value in BX to DX
mov ah,0Ah        ; Set the input function
int 21h           ; Read a string from input
mov si,dx         ; Move the value in DX to SI

print msg2        ; Print the output message
print nln         ; Print a newline

inc si            ; Move the pointer to the next character
mov cx,0h         ; Initialize the counter to 0
mov cl,[si]       ; Move the length of the string to CL
inc si            ; Move the pointer to the next character

back:             ; Start of the loop
	mov al,[si]      ; Move the value at the current pointer to AL
	cmp al,60h       ; Compare the value in AL with 60h (lowercase)
	jl l0            ; Jump if AL is less than 60h
	sub al,20h       ; Subtract 20h from AL (toggle from uppercase to lowercase)
	jmp l1           ; Jump to the next iteration
	l0:
	add al,20h       ; Add 20h to AL (toggle from lowercase to uppercase)
	l1:
	mov [di],al      ; Move the value in AL to the current pointer in DI
	inc di           ; Move the output pointer to the next character
	inc si           ; Move the input pointer to the next character
loop back         ; Loop until the end of the string is reached

mov bl,'$'        ; Move a null terminator to BL
mov [di],bl       ; Move the null terminator to the end of the output string
print final       ; Print the output string

mov ah,4ch        ; Exit the program
int 21h           ; Call the DOS interrupt
code ends         ; End the code segment
end start         ; End the program
