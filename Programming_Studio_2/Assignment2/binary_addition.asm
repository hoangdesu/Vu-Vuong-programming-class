; Main program
    .ORIG x3000

    JSR RESET_REGS

    JSR SET_STONE_BLOCK
    
    ; JSR CLEAR_MAP ; util function for testing only

    JSR	DRAW_MAP

    JSR CALCULATE_FIRST_NUM

    REG

    HALT

; reset all registers
RESET_REGS
    AND R0, R0, #0
    AND R1, R1, #0
    AND R2, R2, #0
    AND R3, R3, #0
    AND R4, R4, #0
    AND R5, R5, #0
    AND R6, R6, #0
    ; AND R7, R7, #0 -> R7 is used to store the address of the main function to return to. Therefore we should not overwrite this in a function, otherwise we will be stuck.
    ; REG
    RET

; 
SET_STONE_BLOCK
    LD R3, STONE
    RET

;
CLEAR_MAP
    GETP
    LD R4, LOOP_COUNTER    
    LD R3, AIR

    LOOP1
        ADD R0, R0, #1
        SETB
        ADD R4, R4, #-1
        BRp LOOP1

    GETP
    LD R4, LOOP_COUNTER
    ADD R2, R2, #1
    
    LOOP2
        ADD R0, R0, #1
        SETB
        ADD R4, R4, #-1
        BRp LOOP2

    SET_STONE_BLOCK

    RET

; Draw map function
DRAW_MAP
    ; first row
    GETP
    ADD R0, R0, #1
    SETB
    ADD R0, R0, #2 
    SETB
    ADD R0, R0, #3
    SETB
    ADD R0, R0, #1
    SETB
    ADD R0, R0, #1
    SETB

    ; second row
    GETP
    ADD R2, R2, #1
    ADD R0, R0, #1
    SETB
    ADD R0, R0, #3
    SETB
    ADD R0, R0, #2
    SETB
    ADD R0, R0, #3
    SETB

    RET


; CALCULATE_FIRST_NUM
;     GETP
;     LD R4, LOOP_COUNTER ; loop counter = 16 (word length)
    
;     LOOP
;         ADD R0, R0, #1
;         GETB ; get the ID value of the current block

;         ; REG

;         AND R6, R6, #1

;         ADD R4, R4, #-1
;         BRp LOOP

;         ADD_NUM_BRANCH


;     RET

CALCULATE_FIRST_NUM
    GETP                ; initialize cursor position
    LD R4, LOOP_COUNTER ; R4 = 16 (bit count)
    AND R5, R5, #0      ; R5 = 0 (final result)
    AND R6, R6, #0
    ADD R6, R6, #1      ; R6 = 1 (binary weight)

    CALC_LOOP
        ADD R0, R0, #1      ; move right 1 block
        GETB                ; result in R3

        BRz SKIP_ADD        ; if R3 == 0, skip adding to result

        ADD R5, R5, R6      ; R5 += weight
        REG

    SKIP_ADD
        ADD R6, R6, R6      ; R6 *= 2 (next bit weight)
        ADD R4, R4, #-1     ; R4--
        BRp CALC_LOOP       ; loop if still more bits

    RET


; Variables
STONE .FILL #1
AIR .FILL #0
LOOP_COUNTER .FILL #16

    .END