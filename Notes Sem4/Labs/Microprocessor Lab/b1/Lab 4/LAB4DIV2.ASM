DATA SEGMENT
    dividend DW 1234h
    divisor DB 78h
    quotient DW ?
    remainder DB ?
DATA ENDS

CODE SEGMENT
    ASSUME CS:CODE, DS:DATA
    
    START:
        MOV AX, DATA     ; Initialize DS register
        MOV DS, AX


        MOV AX, dividend     ; Move dividend to AX register
        CBW                  ; Sign-extend AL into AX
        MOV BL, divisor      ; Move divisor to BL register
        CBW                  ; Sign-extend BL into BX
        IDIV BL              ; Divide AX register by BL register

      
        MOV quotient, AX  ; Move quotient to memory location
        MOV remainder, AH ; Move remainder to memory location
        
        MOV AH, 4CH       ; Exit program
        INT 21H
CODE ENDS
END START
