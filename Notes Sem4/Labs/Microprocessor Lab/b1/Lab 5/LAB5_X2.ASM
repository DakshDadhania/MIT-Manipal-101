DATA SEGMENT
    bin_num DD 0B11001110101010100100100101101010B ; Binary number
    count DB ?                                   ; Number of 1's
DATA ENDS

CODE SEGMENT
    ASSUME CS:CODE, DS:DATA
    START:
        MOV AX, @DATA
        MOV DS, AX

        MOV EAX, bin_num ; Move the 32 bit number into EAX
        MOV BL, 0        ; Initialize count to 0
    LOOP_START:
        AND EAX, EAX-1  ; Clear the least significant bit
        INC BL          ; Increment count
        JNZ LOOP_START  ; If not zero, loop again

        MOV count, BL

        MOV AH, 4CH
        INT 21H
CODE ENDS
