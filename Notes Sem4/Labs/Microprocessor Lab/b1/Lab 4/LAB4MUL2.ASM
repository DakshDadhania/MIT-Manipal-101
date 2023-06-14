DATA SEGMENT
    first_word DB 34h
    second_word DB 78h
    result DB ?
DATA ENDS

CODE SEGMENT
    ASSUME CS:CODE, DS:DATA
    
    START:
        MOV AX, DATA     ; Initialize DS register
        MOV DS, AX


	  MOV AL, first_word    ; Move first byte to AL register
	  CBW                  ; Sign-extend AL into AX
	  IMUL second_word     ; Multiply second byte with AX register
        MOV result, AX     ; Move result to memory location
        
        MOV AH, 4CH       ; Exit program
        INT 21H
CODE ENDS
END START
