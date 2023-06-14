DATA SEGMENT
    num DW 1234h  ; Number to check
    result DB ?   ; 0 if even, 1 if odd
DATA ENDS

CODE SEGMENT
    ASSUME CS:CODE, DS:DATA
    START:
        MOV AX, @DATA
        MOV DS, AX

        MOV AX, num
        AND AX, 1     ; Check the least significant bit
        MOV result, AL

        MOV AH, 4CH
        INT 21H
CODE ENDS
