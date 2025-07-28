.ORIG x3000

; init
ADD R0, R0, #0 ; x
ADD R1, R1, #0 ; y
ADD R2, R2, #0 ; z
ADD R3, R3, #0 ; block = stone
ADD R4, R4, #0 ; height y loop counter
ADD R5, R5, #0 ; width x loop counter
ADD R6, R6, #0 ; length z loop counter
ADD R7, R7, #0

LD R3, STONE

; initial drawing position = x + 1 & z + 1
GETP
ADD R0, R0, #1 ; x += 1
ADD R2, R2, #1 ; z += 1

; store the current drawing positions 
ST R0, CURRENT_X
ST R1, CURRENT_Y
ST R2, CURRENT_Z

; set vars for height loop counter
LD R4, STAIRS_HEIGHT
LD R5, STAIRS_WIDTH
LD R6, STAIRS_LENGTH

LOOP_HEIGHT
    ; reset x
    LD R0, CURRENT_X

    ; reset z
    LD R2, CURRENT_Z

    ; minus 1 to z
    ADD, R2, R2, #-1

    ; +1 to y (height)
    LD R1, CURRENT_Y
    ADD R1, R1, #1
    ST R1, CURRENT_Y

    LOOP_WIDTH
        ; shift 1x position foward
        LD R0, CURRENT_X
        ADD R0, R0 #1
        ST R0, CURRENT_X

        ; reset z
        LD R2, CURRENT_Z

        LOOP_LENGTH
            SETB
            ADD R2, R2, #1 ; z += 1

            ADD R6, R6, #-1
            BRp LOOP_LENGTH


        ; in LOOP_WIDTH
        LD R6, STAIRS_LENGTH
        
        ADD R5, R5, #-1
        BRp LOOP_WIDTH

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


.END