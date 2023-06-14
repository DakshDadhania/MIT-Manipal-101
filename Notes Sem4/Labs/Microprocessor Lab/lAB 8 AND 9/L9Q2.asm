print macro msg    ; Define a macro to print a message to the screen
    lea dx, msg    ; Load the address of the message into DX
    mov ah, 09h    ; Set AH register for output to screen
    int 21h    ; Call the DOS interrupt to display the message
endm    ; End of the macro

data segment    ; Define the data segment
    msg1 db 'Enter the String: $'    ; Message to prompt the user to enter a string
    right db 'Palindrome$'    ; Message to display if the string is a palindrome
    wrong db 'Not Palindrome$'    ; Message to display if the string is not a palindrome
    nln db 10, 13, '$'    ; Line feed, carriage return, and end of string character
    enter db 0Ah    ; The Enter key code
data ends    ; End of the data segment

code segment    ; Define the code segment
    assume cs:code, ds:data    ; Set the segment registers

start:    ; Start of the program
    mov ax, data    ; Move the address of the data segment into AX
    mov ds, ax    ; Move the address in AX into DS
    mov es, ax    ; Move the address in AX into ES

    cld    ; Clear the direction flag to ensure that the string is processed from beginning to end
    print msg1    ; Prompt the user to enter a string
    print nln    ; Move to the next line

    lea bx, enter    ; Load the address of the Enter key code into BX
    mov dx, bx    ; Move the value in BX into DX
    mov ah, 0Ah    ; Set AH register for buffered input from keyboard
    int 21h    ; Read input from keyboard
    mov si, dx    ; Move the address of the input string into SI
    inc si    ; Increment SI to ignore the length byte at the beginning of the input buffer

    mov ax, 0h    ; Initialize AX to zero
    mov al, [si]    ; Load the length of the input string into AL
    mov bl, 02h    ; Divide by 2 to compare only half of the string
    div bl    ; Divide AL by BL
    mov cx, 0h    ; Clear CX
    mov cl, al    ; Move the quotient (half the length of the string) into CL
    mov di, si    ; Move the address of the last character in the input string into DI
    mov dx, 0h    ; Initialize DX to zero
    mov dl, [si]    ; Move the length of the input string into DL
    add di, dx    ; Add DL to the address in DI to point to the last character in the input string
    inc si    ; Move SI to the first character in the input string

back:    ; Loop to compare characters from the beginning and the end of the string
    mov al, [si]    ; Load the character at the current position into AL
    cmp al, [di]    ; Compare it with the character at the other end of the string
    jne last    ; Jump to last if they are not equal
    inc si    ; Move SI to the next character
    dec di    ; Move DI to the previous character
    loop back    ; Decrement CX and loop until it reaches zero

print right:    ; Display the message that the string is a palindrome
    print right
    jmp exit    ; Jump to exit
last:
print wrong
exit:
mov ah,4ch
int 21h

code ends
end start