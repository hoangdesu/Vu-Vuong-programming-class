.ORIG x3000
LEA R0, HW
CHAT

LD R0, NUMX      ; Load the value at label NUM60 into R0
LD R1, NUMY
LD R2, NUMZ

SETP

HALT

HW .STRINGZ "Hello, Minecraft!"

NUMX   .FILL #115     
NUMY   .FILL #100        
NUMZ   .FILL #-97
        .END

