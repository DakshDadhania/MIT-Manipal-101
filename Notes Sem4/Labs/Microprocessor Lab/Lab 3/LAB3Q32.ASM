DATA SEGMENT
A DD 91111111H
B DD 91111111H
SUM DD 0
CARRY DB 0
DATA ENDS

CODE SEGMENT
ASSUME CS: CODE, DS: DATA
START:  MOV AX, DATA
        MOV DS, AX

        MOV CX, 4
        CLC
        MOV SI, 0
NEXT:   MOV AL, BYTE PTR A[SI]
        ADC AL, BYTE PTR B[SI]
	  DAA
        MOV BYTE PTR SUM[SI], AL
        INC SI
        LOOP NEXT

        ADC CARRY, 0

        MOV AH, 4CH
        INT 21H
CODE ENDS
END START
