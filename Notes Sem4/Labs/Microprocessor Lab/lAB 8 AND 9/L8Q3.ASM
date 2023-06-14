ORG 100h    ; Start of program

DATA SEGMENT
    num1 DB ?    ; First input number
    num2 DB ?    ; Second input number
    result DB 0  ; Result of addition
    prompt1 DB 'Enter first 2-digit decimal number: $'
    prompt2 DB 'Enter second 2-digit decimal number: $'
    output DB 'The sum is: $'
DATA ENDS

CODE SEGMENT
ASSUME CS:CODE, DS:DATA

START:
    MOV AX, DATA    ; Load data segment address into AX
    MOV DS, AX    ; Move data segment address into DS

    ; Prompt user to input first number
    MOV AH, 09h    ; Set AH register for output to screen
    MOV DX, OFFSET prompt1    ; Load address of first prompt message into DX
    INT 21h    ; Output first prompt message to screen

    ; Read first number from keyboard
    MOV AH, 01h    ; Set AH register for input from keyboard
    INT 21h    ; Read first character
    SUB AL, 30h    ; Convert from ASCII to binary
    MOV num1, AL    ; Save first digit
    MOV AH, 01h    ; Set AH register for input from keyboard
    INT 21h    ; Read second character
    SUB AL, 30h    ; Convert from ASCII to binary
    MOV BL, 10    ; Set BL register to 10
    MUL BL    ; Multiply first digit by 10
    ADD AL, BL    ; Add second digit to result
    MOV num1, AL    ; Save first number

    ; Prompt user to input second number
    MOV AH, 09h    ; Set AH register for output to screen
    MOV DX, OFFSET prompt2    ; Load address of second prompt message into DX
    INT 21h    ; Output second prompt message to screen

    ; Read second number from keyboard
    MOV AH, 01h    ; Set AH register for input from keyboard
    INT 21h    ; Read first character
    SUB AL, 30h    ; Convert from ASCII to binary
    MOV num2, AL    ; Save first digit
    MOV AH, 01h    ; Set AH register for input from keyboard
    INT 21h    ; Read second character
    SUB AL, 30h    ; Convert from ASCII to binary
    MOV BL, 10    ; Set BL register to 10
    MUL BL    ; Multiply first digit by 10
    ADD AL, BL    ; Add second digit to result
    MOV num2, AL    ; Save second number

    ; Add the numbers
    MOV AL, num1    ; Load first number into AL
    ADD AL, num2    ; Add second number
    MOV result, AL    ; Save result

    ; Display the result
    MOV AH, 09h    ; Set AH register for output to screen
    MOV DX, OFFSET output    ; Load address of output message into DX
    INT 21h    ; Output output message to screen
    MOV DL, result    ; Load result into DL
    ADD DL, 30h    ; Convert result to ASCII
    MOV AH, 02h    ; Set AH register for output character to screen
    INT 21h    ; Output result to screen

    MOV AH, 4Ch   
int 21h

code ends
end start