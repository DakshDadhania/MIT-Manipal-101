DATA SEGMENT
    first_word DW 1234h
    second_word DW 5678h
    result DW ?
DATA ENDS

CODE SEGMENT
    ASSUME CS:CODE, DS:DATA
    
    START:
        MOV AX, DATA     ; Initialize DS register
        MOV DS, AX

        MOV AX, first_word   ; Move first word to AX register
        CWD                  ; Sign-extend AX into DX:AX
        IMUL second_word     ; Multiply second word with DX:AX register


    
        MOV result, AX     ; Move result to memory location
        
        MOV AH, 4CH       ; Exit program
        INT 21H
CODE ENDS
END START
