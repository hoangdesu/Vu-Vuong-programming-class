; .ORIG x3000

; ; init
; AND R0, R0, #0 ; x
; AND R1, R1, #0 ; y
; AND R2, R2, #0 ; z
; AND R3, R3, #0 ; stone
; AND R4, R4, #0 ; x loop counter
; AND R5, R5, #0 ; z loop counter
; AND R6, R6, #0 ; 
; AND R7, R7, #0

; LD R3, STONE




; HALT
; ; your code here
; NUMBER_TO_CONVERT .FILL #237
; STONE             .FILL   #1

; .END


; num = 1010b = 10d

; ; Bit shifting:
; Left shift 1 = num x 2 = num << 1 => 10100b = 20d
; Right shift 1 = num / 2 = num >> 0101b = 5d




; write_binary.asm
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
    
    ; Extract the least significant bit using AND with 1
    AND R7, R3, #1      ; R7 = NUMBER_TO_CONVERT & 1
    
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
    
    ; Restore the number and perform right shift by 1
    LD R3, NUMBER_TO_CONVERT
    
    ; Simple right shift: divide by 2
    ; Handle sign extension for negative numbers
    BRn HANDLE_NEGATIVE
    
    ; For positive numbers, simple division by 2
    AND R6, R6, #0      ; R6 will hold the result
    AND R7, R7, #0      ; R7 is our bit counter
    
DIVIDE_LOOP
    ADD R3, R3, #-2     ; Subtract 2
    BRn DIVIDE_DONE     ; If negative, we're done
    ADD R6, R6, #1      ; Increment quotient
    BR DIVIDE_LOOP
    
DIVIDE_DONE
    ADD R3, R6, #0      ; Copy result back to R3
    BR STORE_SHIFTED
    
HANDLE_NEGATIVE
    ; For negative numbers, we need arithmetic right shift
    ; Add 1, divide by 2, then subtract 1 if original was odd negative
    AND R6, R3, #1      ; Save LSB
    
    ; Arithmetic right shift approximation
    ; For negative numbers: (n + 1) / 2 - 1 if n was odd
    ADD R3, R3, #1      ; Add 1
    
    ; Now divide by 2 (same as positive case)
    AND R7, R7, #0      ; R7 will hold the result  
    
NEG_DIVIDE_LOOP
    ADD R3, R3, #-2     ; Subtract 2
    BRn NEG_DIVIDE_DONE ; If negative, we're done
    ADD R7, R7, #1      ; Increment quotient
    BR NEG_DIVIDE_LOOP
    
NEG_DIVIDE_DONE
    ADD R3, R7, #0      ; Copy result to R3
    
    ; If original LSB was 1, subtract 1 to complete arithmetic shift
    ADD R6, R6, #0      ; Test saved LSB
    BRz STORE_SHIFTED   ; If LSB was 0, we're done
    ADD R3, R3, #-1     ; If LSB was 1, subtract 1
    
STORE_SHIFTED
    ; Store the shifted value back
    ST R3, NUMBER_TO_CONVERT
    
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
NUMBER_TO_CONVERT .FILL x0000   ; This will be set by the test system

.END