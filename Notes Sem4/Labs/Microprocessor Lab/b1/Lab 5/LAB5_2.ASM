DATA SEGMENT
    hex_num DB 27h  ; HEX number
    bcd_num DB ?   ; BCD number
DATA ENDS

CODE SEGMENT
    ASSUME CS:CODE, DS:DATA
    START:
        MOV AX, @DATA
        MOV DS, AX

        MOV AL, hex_num
        AND AL, 0FH    ; Lower nibble
        MOV bcd_num, AL
        MOV AL, hex_num
        SHR AL, 4      ; Upper nibble
        AND AL, 0FH
        SHL bcd_num, 4 ; Shift left by 4 bits
        OR bcd_num, AL ; Combine upper and lower nibble

        MOV AH, 4CH
        INT 21H
CODE ENDS
