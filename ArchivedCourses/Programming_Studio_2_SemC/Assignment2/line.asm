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

LD R3, GRASS


; R0, R1, R2
GETP

ADD R1, R1, #-1

SETB


; R0 += 1 => x += 1 
; ADD R0, R0, #1
; SETB

; ADD R0, R0, #1
; SETB

; ADD R0, R0, #1
; SETB

LD R4, Z_DIST

LOOP_X
    ; x += 1
    ADD R0, R0, #1
    SETB

    ADD R4, R4, #-1
    BRp LOOP_X


HALT
; Note: Please do not change the names of the constants below
Z_DIST .FILL #10

GRASS   .FILL #2

.END
