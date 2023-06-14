DATA SEGMENT
    bcd_num DB 12h, 34h ; BCD number
    hex_num DW ?       ; HEX number
DATA ENDS

CODE SEGMENT
    ASSUME CS:CODE, DS:DATA
    START:
        MOV AX, DATA
        MOV DS, AX

        MOV BL, bcd_num
        MOV BH, 0
        SHL BX, 4   ; Shift left by 4 bits
        MOV AL, bcd_num+1
        ADD BL, AL
        ADC BH, 0
        SHL BX, 4   ; Shift left by 4 bits
        MOV AL, bcd_num+2
        ADD BL, AL
        ADC BH, 0
        SHL BX, 4   ; Shift left by 4 bits
        MOV AL, bcd_num+3
        ADD BL, AL
        ADC BH, 0
        MOV hex_num, BX

        MOV AH, 4CH
        INT 21H
CODE ENDS
END START