.global _start
.text

_start:


MOV X0, #1   //counter
MOV X1, #1   //first
MOV X2, #2   //second
Loop:
ADD X3, X1, X2  // adding first and second
MOV X1, X3      // changing the value of x1 to x3
ADD X2, X2, #1	// changing the value of x2 by 1
ADD X0, X0, #1 // i++
CMP X0, #100   // compare i and 100

B.LE Loop

Loopdone:

MOV x0, #0
MOV x8, #93
svc 0


