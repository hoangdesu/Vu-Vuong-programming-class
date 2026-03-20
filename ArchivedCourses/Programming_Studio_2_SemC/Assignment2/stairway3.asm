.ORIG x3000

; init
AND R0, R0, #0 ; x
AND R1, R1, #0 ; y
AND R2, R2, #0 ; z
AND R3, R3, #0 ; block = stone
AND R4, R4, #0 ; height z loop counter
AND R5, R5, #0 ; width x loop counter
AND R6, R6, #0 ; length y loop counter
AND R7, R7, #0

LD R3, STONE

; initial drawing positions of first block
GETP
ADD R2, R2, #1 ; z += 1
ADD R0, R0, #1 ; x += 1


; store first block origin into variables
ST R0, ORIGIN_X
ST R1, ORIGIN_Y
ST R2, ORIGIN_Z ; store current player's Z to reset later


ST R2, CURRENT_Z 

; loop counters
LD R4, STAIRS_LENGTH
LD R5, STAIRS_WIDTH
LD R6, STAIRS_HEIGHT


LOOP_Y

    ADD R7, R7, #0 ; do nothing

    LOOP_X

        ADD R7, R7, #0 ; do nothing

        LOOP_Z
            SETB

            ADD R2, R2, #1 ; z += 1

            ADD R4, R4, #-1
            BRp LOOP_Z

        ; reset z
        LD R2, CURRENT_Z

        ; reset x: bug if x > 2
        ; LD R0, ORIGIN_X

        ; x += 1
        ADD R0, R0, #1 

        ; reset counter for Z
        LD R4, STAIRS_LENGTH


        ADD R5, R5, #-1
        BRp LOOP_X


    ; reset x, z
    LD R0, ORIGIN_X
    LD R2, CURRENT_Z

    ; z += 1 after every level
    ADD R2, R2, #1
    ST R2, CURRENT_Z 


    ; y += 1
    ADD R1, R1, #1

    ; decrease z counter on every level
    LD R4, STAIRS_LENGTH
    ADD R4, R4, #-1
    ST R4, STAIRS_LENGTH


    ; reset x counter
    LD R5, STAIRS_WIDTH

    ADD R6, R6, #-1
    BRp LOOP_Y




HALT

STONE           .FILL #57

STAIRS_WIDTH    .FILL #2
STAIRS_LENGTH   .FILL #4
STAIRS_HEIGHT   .FILL #3

ORIGIN_X        .FILL #0  
ORIGIN_Y        .FILL #0
ORIGIN_Z        .FILL #0


CURRENT_Z       .FILL #0


.END


; for y in range 3
    ; i = 0
; 	for x in range 2
; 		for z in range 4 - z_counter:



