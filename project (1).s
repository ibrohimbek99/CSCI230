.global _start
.text

_start:

LDR x1, =arr1
mov x2, #2 //counter
LDRB w3, [x1]  // a[0]
ADD x1, x1, #1  
LDRB w4, [x1]     // a[1]
ADD x1, x1, #1

CMP w3, w4
B.LT icheck
mov w11, w3
mov w3, w4
mov w4, w11   // values changed  since it is not smaller
 

icheck:
cmp x2, #6    //counter check
BNE loop1     //if not go to loop, if yes go to final
B final

loop1:
LDRB w5, [x1], #1 //a[2] getting incremented by 1
add x2, x2, #1 //counter
CMP w4, w5
B.LT icheck
B inside_if

inside_if:
CMP w3, w5
B.GT min10
mov w4, w5
B loop1

min10:
mov w10, w3
mov w3, w5
mov w4, w10
B icheck

final:
LDR x20, =min1
STR w3, [x20], #4
LDR x20, =min2
STR w4, [x20], #4  
finaldone:

mov x0, #0
mov x9, #93
svc 0

.data
arr1: .byte 4,2,3,6,1,7
min1: .word 0
min2: .word 0
