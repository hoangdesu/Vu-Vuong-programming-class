.ORIG x3000

; Clear the registers
AND R0, R0, #0     ; Clear R0 (x = 0)
AND R1, R1, #0 
AND R2, R2, #0 
AND R3, R3, #0
AND R4, R4, #0

; Loop counter
; ADD R4, R4, #3
LD R4, LOOP_COUNT

AND R3, R3, #0

; Get the current player's position x, y, z
GETP

ADD R1, R1, #-1 ; push block to the ground

LOOP 
        ADD R0, R0, #1 ; x += 1
        LD R3, GRASS_BLOCK
        SETB

        ADD R4, R4, #-1
        BRp LOOP

HALT

GRASS_BLOCK      .FILL #2
LOOP_COUNT       .FILL #5
        .END

