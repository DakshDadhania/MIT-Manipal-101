DATA SEGMENT
A DW 5555H
B DW 2222H
ANS DW 0
BORROW DB 0
DATA ENDS

CODE SEGMENT
ASSUME CS: CODE, DS: DATA
START:  MOV AX, DATA
        MOV DS, AX

        MOV AX, A
        SUB AX, B
        ADC BORROW, 0
        MOV ANS, AX

        MOV AH, 4CH
        INT 21H
CODE ENDS
END START
