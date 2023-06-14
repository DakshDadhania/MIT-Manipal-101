DATA SEGMENT
    dividend DW 5678h
    divisor DB 11
    quotient DW ?
    remainder DB ?
DATA ENDS

CODE SEGMENT
    ASSUME CS:CODE, DS:DATA
    START:
        MOV AX, DATA
        MOV DS, AX

        MOV AX, dividend
        MOV BL, divisor
        DIV BL
        MOV quotient, AX
        MOV remainder, DL

        MOV AH, 4CH
        INT 21H
CODE ENDS
END START