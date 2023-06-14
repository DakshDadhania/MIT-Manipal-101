DATA SEGMENT
A DB 1,2,3,4,5,6,7,8,9,10
B DB 11,12,13,14,15,16,17,18,19,20
DATA ENDS

CODE SEGMENT
ASSUME CS: CODE, DS: DATA
START:
        MOV AX, DATA
        MOV DS, AX

        LEA SI, A
        LEA DI, B
        MOV CX, 10
L1:
        MOV AL, [SI]
        MOV BL, [DI]
        MOV [SI], BL
        MOV [DI], AL
        INC SI
        INC DI
        LOOP L1
        MOV AH, 4CH
        INT 21H
CODE ENDS
END START
