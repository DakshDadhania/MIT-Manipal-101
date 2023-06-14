DATA SEGMENT
        ARRAY1 DW 1111H,2222H,3333H,4444H,5555H
        ARRAY2 DW 5 DUP(0)
        COUNT DB 05H
        DATA ENDS
CODE SEGMENT
ASSUME CS:CODE, DS:DATA
START:   MOV AX,DATA;
MOV DS,AX;
         LEA SI,ARRAY1;                           X
         LEA DI,ARRAY2;
       MOV CH,00H
       MOV CL,COUNT
         ADD SI,0008H ;
         ADD DI,0004H
         
         
         
         NEXT:MOV AX,[SI];
         MOV [DI],AX;
         DEC DI;
         DEC DI;
         DEC SI;
         DEC SI;

LOOP NEXT;
MOV AH,4CH;


INT 21H

CODE ENDS
END START
