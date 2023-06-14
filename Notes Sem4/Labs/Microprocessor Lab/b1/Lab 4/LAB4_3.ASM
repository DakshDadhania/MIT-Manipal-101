DATA SEGMENT
    num1 DW 1234h   ; First 16-bit number
    num2 DW 5678h   ; Second 16-bit number
    result DW ?     ; Resultant multiplication of num1 and num2
DATA ENDS

CODE SEGMENT
    ASSUME CS:CODE, DS:DATA
    START:
        MOV AX, DATA
        MOV DS, AX

        MOV BX, num1    ; Move num1 into BX
        MOV CX, num2    ; Move num2 into CX
        MOV DX, 0       ; Clear DX
        MOV result, DX  ; Clear the result

        LOOP_START:
            CMP BX, 0       ; Check if BX is zero
            JE EXIT_LOOP    ; Exit the loop if BX is zero
            JNC ADD_NUMS    ; Jump if carry flag is not set (i.e., least significant bit of BX is zero)
            ADD result, CX  ; Add CX to the result if least significant bit of BX is one
        ADD_NUMS:
            ADD CX, CX      ; Shift left CX by one bit
            SHR BX, 1       ; Shift right BX by one bit
            JMP LOOP_START  ; Jump back to the start of the loop

        EXIT_LOOP:
        MOV AH, 4CH
        INT 21H
CODE ENDS
END START