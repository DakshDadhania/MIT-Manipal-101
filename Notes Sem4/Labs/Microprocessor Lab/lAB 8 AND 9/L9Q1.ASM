ORG 100h    ; Start of program

DATA SEGMENT
    password DB '1234'    ; The correct password
    input DB 5, ?, ?, ?, ?    ; Buffer for input characters
    prompt DB 'Enter password (4 digits): $'
    correct_msg DB 'Password accepted!$'
    incorrect_msg DB 'Incorrect password. Try again.$'
DATA ENDS

CODE SEGMENT
ASSUME CS:CODE, DS:DATA

START:
    MOV AX, DATA    ; Load data segment address into AX
    MOV DS, AX    ; Move data segment address into DS

    ; Prompt user to enter password
    MOV AH, 09h    ; Set AH register for output to screen
    MOV DX, OFFSET prompt    ; Load address of prompt message into DX
    INT 21h    ; Output prompt message to screen

    ; Read password from keyboard
    MOV AH, 0Ah    ; Set AH register for buffered input from keyboard
    MOV DX, OFFSET input    ; Load address of input buffer into DX
    INT 21h    ; Read input from keyboard
    MOV AL, input+2    ; Load first digit of input into AL
    CMP AL, password[0]    ; Compare with first digit of password
    JNE incorrect    ; Jump to incorrect message if not equal
    MOV AL, input+3    ; Load second digit of input into AL
    CMP AL, password[1]    ; Compare with second digit of password
    JNE incorrect    ; Jump to incorrect message if not equal
    MOV AL, input+4    ; Load third digit of input into AL
    CMP AL, password[2]    ; Compare with third digit of password
    JNE incorrect    ; Jump to incorrect message if not equal
    MOV AL, input+5    ; Load fourth digit of input into AL
    CMP AL, password[3]    ; Compare with fourth digit of password
    JNE incorrect    ; Jump to incorrect message if not equal

    ; Display correct message
    MOV AH, 09h    ; Set AH register for output to screen
    MOV DX, OFFSET correct_msg    ; Load address of correct message into DX
    INT 21h    ; Output correct message to screen
    JMP done    ; Jump to end of program

incorrect:
    ; Display incorrect message
    MOV AH, 09h    ; Set AH register for output to screen
    MOV DX, OFFSET incorrect_msg    ; Load address of incorrect message into DX
    INT 21h    ; Output incorrect message to screen

done:
    MOV AH, 4Ch    ; Set AH register for exit program
    INT 21h    ; Terminate program

CODE ENDS
END START    ; End of program
