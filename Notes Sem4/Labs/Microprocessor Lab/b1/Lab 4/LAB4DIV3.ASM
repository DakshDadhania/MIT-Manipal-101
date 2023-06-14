DATA SEGMENT
    dividend DD 12345678h
    divisor DW 5678h
    quotient DD ?
    remainder DW ?
DATA ENDS

CODE SEGMENT
    ASSUME CS:CODE, DS:DATA
    START:
        MOV AX, DATA
        MOV DS, AX

        MOV AX, WORD PTR dividend+2
        MOV DX, WORD PTR dividend
        MOV BX, divisor
        DIV BX
        MOV quotient, EAX
        MOV remainder, DX

        MOV AH, 4CH
        INT 21H
CODE ENDS
END START