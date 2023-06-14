DATA SEGMENT
    hex_num DW 1234h ; HEX number
    bcd_num DB ?    ; BCD number
DATA ENDS

CODE SEGMENT
    ASSUME CS:CODE, DS:DATA
    START:
        MOV AX, DATA
        MOV DS, AX

        MOV BX, hex_num
        MOV BL, BH
        AND BL, 0FH    ; Lower nibble of least significant byte
        MOV bcd_num, BL
        SHR BH, 4      ; Upper nibble of least significant byte
        MOV BL, BH
        AND BL, 0FH    ; Lower nibble of second least significant byte
        SHL bcd_num, 4 ; Shift left by 4 bits
        OR bcd_num, BL ; Combine lower nibbles
        SHR BH, 4      ; Upper nibble of second least significant byte
        MOV BL, BLH
        AND BL, 0FH    ; Lower nibble of second most significant byte
        SHL bcd_num, 4 ; Shift left by 4 bits
        OR bcd_num, BL ; Combine lower nibbles
        SHR BLH, 4     ; Upper nibble of second most significant byte
        MOV BL, BH
        AND BL, 0FH    ; Lower nibble of most significant byte
        SHL bcd_num, 4 ; Shift left by 4 bits
        OR bcd_num, BL ; Combine lower nibbles
        SHR BH, 4      ; Upper nibble of most significant byte

       
        MOV AH, 4CH
        INT 21H
CODE ENDS