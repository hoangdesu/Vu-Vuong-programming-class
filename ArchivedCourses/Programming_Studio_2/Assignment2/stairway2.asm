.ORIG x3000

; init
AND R0, R0, #0 ; x
AND R1, R1, #0 ; y
AND R2, R2, #0 ; z
AND R3, R3, #0 ; block = stone
AND R4, R4, #0 ; height y loop counter
AND R5, R5, #0 ; width x loop counter
AND R6, R6, #0 ; length z loop counter
AND R7, R7, #0

LD R3, STONE

; set vars for height loop counter
LD R4, STAIRS_HEIGHT
LD R5, STAIRS_WIDTH
LD R6, STAIRS_LENGTH

LOOP_HEIGHT
    GETP
    LD R7, Y_DISTANCE
    ADD R1, R1, R7 ; y += 1

    LOOP_WIDTH
        GETP
        ; ADD R0, R0, X_DISTANCE ; x += 1
        ; ADD R2, R2, Z_DISTANCE ; z += 1
        LD R7, X_DISTANCE
        ADD R0, R0, R7
        LD R7, Z_DISTANCE
        ADD R2, R2, R7

        LOOP_LENGTH
            SETB
            ADD R2, R2, #1 ; z += 1

            ADD R6, R6, #-1
            BRp LOOP_LENGTH

        ; reset counter for z
        LD R6, STAIRS_LENGTH

        ADD R0, R0, #1
        ST R0, X_DISTANCE

        ADD R5, R5, #-1
        BRp LOOP_WIDTH
        ; end LOOP_WIDTH

    ; reset counter for x
    LD R5, STAIRS_WIDTH

    ; reset x
    GETP
    AND R0, R0, #1
    ST R0, X_DISTANCE

    ; y += 1
    ADD R1, R1, #1
    ST R1, Y_DISTANCE

    ADD R4, R4, #-1
    BRp LOOP_HEIGHT


HALT
; Note: Please do not change the names of the constants below
STAIRS_WIDTH    .FILL #2
STAIRS_LENGTH   .FILL #4
STAIRS_HEIGHT   .FILL #3
STONE           .FILL #1

CURRENT_X       .FILL #0
CURRENT_Y       .FILL #0
CURRENT_Z       .FILL #0

X_DISTANCE       .FILL #1
Y_DISTANCE       .FILL #0
Z_DISTANCE       .FILL #1

.END