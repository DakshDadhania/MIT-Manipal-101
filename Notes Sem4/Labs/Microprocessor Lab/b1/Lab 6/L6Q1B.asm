DATA SEGMENT
Num1 DW 0096h
Num2 DW 003Ch
Ans DW ?
DATA ENDS
CODE SEGMENT
ASSUME CS: CODE, DS: DATA
START: 
MOV AX, DATA
MOV DS, AX

MOV AX, Num1 
MOV BX, Num2 
call GCD

MOV AH, 4CH
INT 21H

GCD Proc
FIRST: 
	CMP AX, BX 
	JA NEXT 
	XCHG AX, BX
NEXT:
	 MOV DX, 0000h
	DIV BX 
	CMP DX, 0000h 
	JE LAST 
	MOV AX, DX 
	JMP FIRST
LAST: 
	MOV Ans, BX 
RET
GCD ENDP

CODE ENDS
END START
