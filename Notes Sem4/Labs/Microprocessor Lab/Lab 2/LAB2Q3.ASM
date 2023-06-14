DATA SEGMENT
A DW 1111H, 2222H, 3333H, 4444H, 5555H
B DW 3 DUP(0)
DATA ENDS

CODE SEGMENT
ASSUME CS: CODE, DS: DATA
START:
       MOV AX,DATA
       MOV DS,AX

       LEA SI, A
       LEA DI, B
       ADD SI, 8
       ADD DI, 4
       MOV CX, 5
L1:
       MOV BX, [SI]
       MOV [DI], BX
       DEC SI
       DEC SI
       DEC DI
       DEC DI
       LOOP L1
       MOV AH, 4CH
       INT 21H
CODE ENDS
END START
