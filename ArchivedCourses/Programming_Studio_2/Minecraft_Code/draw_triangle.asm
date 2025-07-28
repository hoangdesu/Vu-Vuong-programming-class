.ORIG x3000

; Clear the registers
AND R0, R0, #0  ; x
AND R1, R1, #0  ; y
AND R2, R2, #0  ; z
AND R3, R3, #0
AND R4, R4, #0

; Loop counter
; ADD R4, R4, #3
LD R4, LOOP_COUNT

AND R3, R3, #0

; Get the current player's position x, y, z
GETP

ADD R1, R1, #-1 ; push block to the ground
LD R3, GRASS_BLOCK

; Draw middle line
LOOP1
        ADD R0, R0, #1 ; x += 1
        SETB

        ; REG

        ADD R4, R4, #-1
        BRp LOOP1

ADD R4, R4, #0
ADD R4, R4, #3  ; decrease the height

; Reset the player's position
GETP
ADD R1, R1, #-1  ; push block to the ground

LOOP2
        ADD R0, R0, #1 ; x += 1
        ADD R5, R2, #0   ; store the current z into tempZ R5

        ADD R2, R2, #1   ; Move to the right
        SETB ; draw on the right

        ; draw on the left
        ADD R2, R5, #0 ; reset the position
        ADD R2, R2, #-1
        SETB

        REG

        ADD R4, R4, #-1
        BRp LOOP2

HALT

; do {
; } while () {

; }

; Labels
GRASS_BLOCK      .FILL #2
LOOP_COUNT       .FILL #4
        .END

