DATA SEGMENT
        A1 DB 54H, 25H, 58H, 4AH, 34H, 78H, 7FH, 14H, 0ABH, 74H
        SUM DW ?
        DATA ENDS

CODE SEGMENT
        ASSUME CS:CODE DS:DATA

START:MOV AX,DATA
      MOV DS,AX
      MOV SI,0 ;[SI] STORING VALUES OF A1
      MOV AX,0 ;
      MOV CX,10 ;TO RUN IN 10 TIMES
      CLC

BACK:ADC AL,[SI]
     SBB AH,0
     INC SI
     LOOP BACK
     MOV SUM,AX ;STORING RESULT IN SUM

     MOV AH,4CH
     INT 21H

     CODE ENDS
     END START
