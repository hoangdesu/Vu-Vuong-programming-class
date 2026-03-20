.ORIG x3000

; Registers usage
; R0 = X
; R1 = Y
; R2 = Z
; R3 = BLOCK type
; R4 = X counter
; R5 = Z counter
; R6 = Origin X
; R7 = Temp

; === Init ===
AND R0, R0, #0      ; x = 0
AND R1, R1, #0      ; y = 0
AND R2, R2, #0      ; z = 0
LD  R3, GRASS       ; block type

LD  R5, Z_DIST      ; z counter = 3
ADD R5, R5, #1      ; add 1 to include the origin

GETP                ; get player pos
ADD R6, R0, #0      ; save origin X

; --- Outer loop over Z ---
LOOP_Z
    ADD R4, R5, #0      ; set X counter = current z counter

    ; --- Inner loop over X ---
    LOOP_X
        SETB                ; place block at (R0,R1,R2)
        ADD R0, R0, #1      ; move x++
        ADD R4, R4, #-1
        BRp LOOP_X

    ; reset x to origin
    ADD R0, R6, #0

    ; z -= 1
    ADD R2, R2, #-1

    ; decrease z counter
    ADD R5, R5, #-1
    BRp LOOP_Z

; Reset 
AND R0, R0, #0      ; x = 0
AND R1, R1, #0      ; y = 0
AND R2, R2, #0      ; z = 0
LD  R3, GRASS       ; block type

; Draw triangle part on the right
LD  R5, Z_DIST      ; z counter = 3
ADD R5, R5, #1      ; add 1 to include the origin

GETP                ; get player pos
ADD R6, R0, #0      ; save origin X

LOOP_Z_RIGHT
    ADD R4, R5, #0      ; set X counter = current z counter

    ; --- Inner loop over X ---
    LOOP_X_RIGHT
        SETB                ; place block at (R0,R1,R2)
        ADD R0, R0, #1      ; move x++
        ADD R4, R4, #-1
        BRp LOOP_X_RIGHT

    ; reset x to origin
    ADD R0, R6, #0

    ; z += 1
    ADD R2, R2, #1

    ; decrease z counter
    ADD R5, R5, #-1
    BRp LOOP_Z_RIGHT


HALT

; === Constants ===
Z_DIST  .FILL #5
GRASS   .FILL #2

.END
