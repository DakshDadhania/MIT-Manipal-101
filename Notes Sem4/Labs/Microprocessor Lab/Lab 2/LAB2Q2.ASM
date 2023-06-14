DATA SEGMENT
A DB 1,2,3,4,5,6,7,8,9,10
B DB 3 DUP(?)
DATA ENDS

CODE SEGMENT
ASSUME CS:CODE, DS: DATA
START:
        MOV AX, DATA
        MOV DS, AX

        LEA SI, A
        LEA DI, B
        ADD SI, 9
        ADD DI, 2
        MOV CX, 10
LOOP1:
        MOV AL, [SI]
        MOV [DI], AL
        DEC SI
        DEC DI
        LOOP LOOP1

        MOV AH, 4CH
        INT 21H
CODE ENDS
END START
