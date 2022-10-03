.global _start
.text

_start:

MOV x0, #1 //counter
MOV x1, #0 // first
MOV x2, #1 //second
MOV x3, #1 // third
Loop:
ADD x3, x1, x2
MOV x1, x2
MOV x2, x3
ADD x0, x0, #1
CMP x0, #40
B.LE Loop

Loopdone:

MOV x0, #0
MOV x8, #93
svc 0



