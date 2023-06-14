;Additional exercise: Find the square of an unsigned two-digit hexadecimal number

DATA SEGMENT
hex_num DB 45h
result DW ?
DATA ENDS

CODE SEGMENT
ASSUME CS:CODE, DS:DATA
START:
MOV AX, DATA
MOV DS, AX



    MOV AL, hex_num
    CBW
    MOV BL, AL
    MOV BH, 0
    MUL BL
    MOV result, AX

    MOV AH, 4CH
    INT 21H
CODE ENDS
END START