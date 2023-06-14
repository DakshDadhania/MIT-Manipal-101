; define a macro to print a string to the console
print macro msg
	mov dx, offset msg ; load the offset of the message into dx
	mov ah, 09h         ; set ah to 9 to print a string
	int 21h             ; print the string
endm

; define a macro to print a single character to the console
printc macro
	mov ah, 02h ; set ah to 2 to print a character
	int 21h     ; print the character
endm

data segment
	msg1 db 'Enter character without echo:$'
	msg2 db 'Character without echo is: $'
	msg3 db 'Enter character with echo:$'
	msg4 db 'Character with echo is: $'
	newline db 10, 13, '$' ; define a newline sequence
code segment
assume cs:code, ds:data
start:
	mov ax, data
	mov ds, ax ; set ds to point to the data segment

	; prompt the user to enter a character without echo
	print msg1
	call inputwoe
	print newline ; print a newline
	; display the entered character
	print msg2
	mov dl, al ; move the entered character to dl for printing
	printc 
	print newline ; print a newline
	print newline ; print an extra newline for spacing

	; prompt the user to enter a character with echo
	print msg3
	call inputwe
	print newline ; print a newline
	; display the entered character
	print msg4
	mov dl, al ; move the entered character to dl for printing
	printc 

	mov ah, 4Ch ; terminate the program
	int 21h

inputwoe proc ; procedure to accept user input without echo
	mov ah, 08h ; set ah to 8 to accept a single character without echo
	int 21h     ; accept the input
	ret
inputwoe endp

inputwe proc ; procedure to accept user input with echo
	mov ah, 01h ; set ah to 1 to accept a single character with echo
	int 21h     ; accept the input
	ret
inputwe endp

code ends
end start
