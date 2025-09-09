.ORIG x3000

; init
AND R0, R0, #0 ; x
AND R1, R1, #0 ; y
AND R2, R2, #0 ; z
AND R3, R3, #0 ; block = stone
AND R4, R4, #0 ; x loop counter
AND R5, R5, #0 ; z loop counter
AND R6, R6, #0 ; 
AND R7, R7, #0

LD R3, GRASS

; R0, R1, R2
; GETP

; SETB


; R0 += 1 => x += 1 
; ADD R0, R0, #1
; SETB

; ADD R0, R0, #1
; SETB

; ADD R0, R0, #1
; SETB


; x counter
LD R4, Z_DIST

; z counter
LD R5, Z_DIST

LD R7, Z_DIST


; 1. GETP: reset position
; 2. LOOP X from P to Z_DIST
; 3. Move left Z_DIST

; origin block
GETP

; store origin X to R6
ADD R6, R0, #0


; push y 1 down: y -= 1
ADD R1, R1, #-1
SETB

LOOP_Z
    ADD R1, R1, #0
    ; REG

    LOOP_X
        ; x += 1
        ADD R0, R0, #1
        SETB

        REG

        ADD R4, R4, #-1
        BRp LOOP_X

    ; z -= 1

    ; GETP
    ; ; z -= 1
    ; ADD R2, R2, 
    ; ; y -= 1
    ; ADD R1, R1, #-1

    ; reset x
    ADD R0, R6, #0

    ; z -= 1
    ADD R2, R2, #-1
    SETB

    ; reset x counter
    ; LD R4, Z_DIST
    ADD R7, R7, #-1
    ADD R7, R4, #0

    ; z_counter -= 1
    ADD R5, R5, #-1
    BRp LOOP_Z



HALT
; Note: Please do not change the names of the constants below
Z_DIST .FILL #3

GRASS   .FILL #2

.END

