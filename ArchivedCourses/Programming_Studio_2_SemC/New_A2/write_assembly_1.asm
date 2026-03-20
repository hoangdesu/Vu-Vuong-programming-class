; write_assembly_1.asm
; Converts a number stored in memory into its binary representation in Minecraft
; Uses air blocks (ID #0) for 0s and stone blocks (ID #1) for 1s
; 16 bits total, least significant bit closest to player

.ORIG x3000

; Get player position first
GETP            ; Gets player position into R0, R1, R2

; Store player position for later use
ST R0, PLAYER_X
ST R1, PLAYER_Y
ST R2, PLAYER_Z

; Load the number to convert
LD R3, NUMBER_TO_CONVERT

; Initialize bit counter (16 bits to process)
AND R4, R4, #0      ; R4 = bit counter

; Initialize Z offset
AND R5, R5, #0      ; R5 = Z offset (starts at 1)
ADD R5, R5, #1

BIT_LOOP
    ; Check if we've processed all 16 bits
    AND R6, R6, #0
    ADD R6, R6, #15
    ADD R6, R6, #1      ; R6 = 16
    NOT R6, R6
    ADD R6, R6, #1      ; R6 = -16
    ADD R6, R6, R4      ; R6 = R4 - 16
    BRzp END_PROGRAM    ; If R4 >= 16, we're done

    ; Extract the current bit using mask approach
    ; We need to check bit position R4 in the number
    AND R7, R7, #0      ; R7 = current working copy of number
    ADD R7, R3, #0      ; Copy the number

    ; Right shift the number by R4 positions
    AND R6, R6, #0      ; R6 = shift counter

SHIFT_LOOP
    ; Check if we've shifted enough
    NOT R1, R4          ; R1 = -R4
    ADD R1, R1, #1
    ADD R1, R1, R6      ; R1 = R6 - R4
    BRzp SHIFT_DONE     ; If R6 >= R4, we're done shifting

    ; Right shift by 1: divide by 2 (only for positive numbers)
    ; For LC-3, we'll use a simple approach since we assume non-negative
    AND R1, R1, #0      ; R1 = quotient

DIVIDE_BY_2
    ADD R7, R7, #-2     ; Subtract 2
    BRn DIV_DONE        ; If negative, we're done
    ADD R1, R1, #1      ; Increment quotient
    BR DIVIDE_BY_2

DIV_DONE
    ADD R7, R1, #0      ; R7 = quotient (right shifted by 1)
    ADD R6, R6, #1      ; Increment shift counter
    BR SHIFT_LOOP

SHIFT_DONE
    ; Now R7 contains the number right-shifted by R4 positions
    ; Extract the least significant bit
    AND R1, R7, #1      ; R1 = LSB of shifted number

    ; Determine block type based on bit value
    BRz PLACE_AIR       ; If bit is 0, place air

PLACE_STONE
    AND R7, R7, #0      ; Clear R7
    ADD R7, R7, #1      ; Block ID = 1 (stone)
    BR PLACE_BLOCK

PLACE_AIR
    AND R7, R7, #0      ; Block ID = 0 (air)

PLACE_BLOCK
    ; Calculate block position
    LD R0, PLAYER_X     ; X = player X
    LD R1, PLAYER_Y     ; Y = player Y
    LD R2, PLAYER_Z     ; Z = player Z + offset
    ADD R2, R2, R5      ; Add Z offset

    ; Place the block (R7 contains block ID)
    ADD R3, R7, #0      ; Move block ID to R3 for SETB
    SETB                ; setBlock(R0, R1, R2, R3)

    ; Restore the original number
    LD R3, NUMBER_TO_CONVERT

    ; Increment Z offset for next bit
    ADD R5, R5, #1

    ; Increment bit counter
    ADD R4, R4, #1
    BR BIT_LOOP         ; Continue loop

END_PROGRAM
    HALT

; Data storage
PLAYER_X    .FILL x0000
PLAYER_Y    .FILL x0000
PLAYER_Z    .FILL x0000
NUMBER_TO_CONVERT .FILL #237   ; Default test value

.END