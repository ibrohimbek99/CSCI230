.global _start

.text
_start:
 LDR x1, =arr1
 LDR x2, =sum
 MOV w3, #9
 MOV w4, #0
 MOV x5, #0
loop:
 LDRB w0, [x1]
 ADD x1, x1, #1
 ADD w5,w5,w0
 ADD w4, w4, #1
 CMP w3, w4
 B.GT loop
 STR x5, [x2]
 MOV x0, #0
 MOV x8, #93
 SVC 0
.data
arr1: .byte 4,2,3,6,1,5,7,9,8
sum: .word 0
