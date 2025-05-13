.ORIG x3000
LEA R0, HW
CHAT

LD R0, NUMX      ; Load the value at label NUM60 into R0
LD R1, NUMY
LD R2, NUMZ
LD R3, BL

; SETP
SETB

HALT

HW .STRINGZ "Hello, Minecraft!"

NUMX   .FILL #118
NUMY   .FILL #64       
NUMZ   .FILL #-87
BL      .FILL #78
        .END

