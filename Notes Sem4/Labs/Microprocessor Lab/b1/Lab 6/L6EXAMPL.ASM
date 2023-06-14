DISP MACRO MSG
    MOV DX, OFFSET MSG
    MOV AH, 09
    INT 21H
ENDM
DATA SEGMENT
    A DB 'MANIPAL$'
DATA ENDS

CODE SEGMENT
    ASSUME CS:CODE, DS:DATA

START:
    MOV AX, DATA   ; Load the data segment address into AX
    MOV DS, AX     ; Move the data segment address into DS

    DISP A         ; Display the message defined in the A label

    MOV AH, 4CH    ; Terminate the program
    INT 21H



CODE ENDS
END START
