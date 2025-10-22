; terraform.asm
; Flattens a 3x3 area centered underneath the player
; Uses getHeight to find the target height at player position
; Builds up with dirt blocks (ID #3) or cuts down with air blocks (ID #0)

.ORIG x3000

AND R0, R0, #0 ; x
AND R1, R1, #0 ; y
AND R2, R2, #0 ; z
AND R3, R3, #0 ; dis_x
AND R4, R4, #0 ; dis_y
AND R5, R5, #0 ; dis_z
AND R6, R6, #0 ; G_X, G_Y, G_Z
AND R7, R7, #0

; Get player position
; GETP            ; Gets player position into R0, R1, R2

; ; Store player position
; ST R0, PLAYER_X
; ST R1, PLAYER_Y
; ST R2, PLAYER_Z

; ; Get the target height at player position
; ; Use GETH to get height at (player_x, player_z)
; GETH            ; getHeight(R0, R2) -> R1
; ST R1, TARGET_HEIGHT

; ; Initialize loop counters for 3x3 area
; ; X offset: -1, 0, 1 (relative to player)
; ; Z offset: -1, 0, 1 (relative to player)

; AND R3, R3, #0  ; R3 = X offset counter (-1 to 1)
; ADD R3, R3, #-1 ; Start at -1

; X_LOOP
;     ; Check if X offset is done (> 1)
;     AND R4, R4, #0
;     ADD R4, R4, #2  ; R4 = 2
;     NOT R4, R4
;     ADD R4, R4, #1  ; R4 = -2
;     ADD R4, R4, R3  ; R4 = R3 - 2
;     BRzp X_LOOP_DONE

;     ; Reset Z offset counter
;     AND R5, R5, #0  ; R5 = Z offset counter (-1 to 1)
;     ADD R5, R5, #-1 ; Start at -1

;     Z_LOOP
;         ; Check if Z offset is done (> 1)
;         AND R6, R6, #0
;         ADD R6, R6, #2  ; R6 = 2
;         NOT R6, R6
;         ADD R6, R6, #1  ; R6 = -2
;         ADD R6, R6, R5  ; R6 = R5 - 2
;         BRzp Z_LOOP_DONE

;         ; Calculate current tile position
;         LD R0, PLAYER_X
;         ADD R0, R0, R3  ; X = player_x + x_offset
;         LD R2, PLAYER_Z
;         ADD R2, R2, R5  ; Z = player_z + z_offset

;         ; Get height at this position
;         GETH            ; getHeight(R0, R2) -> R1
;         ST R1, CURRENT_HEIGHT

;         ; Load target height for comparison
;         LD R4, TARGET_HEIGHT
;         LD R1, CURRENT_HEIGHT

;         ; Compare current height with target height
;         NOT R6, R4      ; R6 = -target_height
;         ADD R6, R6, #1
;         ADD R6, R1, R6  ; R6 = current_height - target_height

;         BRz NEXT_TILE   ; If equal, skip this tile
;         BRn BUILD_UP    ; If current < target, build up
;         BRp CUT_DOWN    ; If current > target, cut down

; BUILD_UP
;         ; Build up from current_height+1 to target_height
;         ; R1 = current height, R4 = target height
;         ADD R1, R1, #1  ; Start from current_height + 1

; BUILD_LOOP
;         ; Check if we've reached target height
;         NOT R6, R4      ; R6 = -target_height
;         ADD R6, R6, #1
;         ADD R6, R1, R6  ; R6 = current_y - target_height
;         BRp NEXT_TILE   ; If current_y > target, we're done

;         ; Check if block at this position is air before placing dirt
;         ; R0 = x, R1 = y, R2 = z
;         GETB            ; getBlock(R0, R1, R2) -> R3

;         ; Only place dirt if current block is air (ID #0)
;         ADD R3, R3, #0  ; Test if R3 is zero
;         BRnp SKIP_PLACE ; If not air, skip placement

;         ; Place dirt block (ID #3)
;         AND R3, R3, #0
;         ADD R3, R3, #3  ; Block ID = 3 (dirt)
;         SETB            ; setBlock(R0, R1, R2, R3)

; SKIP_PLACE
;         ADD R1, R1, #1  ; Move to next Y level
;         BR BUILD_LOOP

; CUT_DOWN
;         ; Cut down from current_height to target_height+1
;         ; R1 = current height, R4 = target height
;         ADD R1, R1, #0      ; No-op to separate labels

; CUT_LOOP
;         ; Check if we've reached target height
;         NOT R6, R4      ; R6 = -target_height
;         ADD R6, R6, #1
;         ADD R6, R1, R6  ; R6 = current_y - target_height
;         BRnz NEXT_TILE  ; If current_y <= target, we're done

;         ; Replace block with air (ID #0)
;         AND R3, R3, #0  ; Block ID = 0 (air)
;         SETB            ; setBlock(R0, R1, R2, R3)

;         ADD R1, R1, #-1 ; Move down one Y level
;         BR CUT_LOOP

; NEXT_TILE
;         ; Increment Z offset
;         ADD R5, R5, #1
;         BR Z_LOOP

;     Z_LOOP_DONE
;         ; Increment X offset
;         ADD R3, R3, #1
;         BR X_LOOP


; Get current player positions
GETP

; Store player position first
ST R0, PLAYER_X
ST R1, PLAYER_Y
ST R2, PLAYER_Z

; get the upper bound for y
GETH

; Store the upper bound height from GETH
ST R1, TARGET_HEIGHT

; Clear blocks above target height in 3x3 area
; Initialize X offset counter (-1 to 1)
AND R3, R3, #0
ADD R3, R3, #-1

X_CLEAR_LOOP
    ; Check if X offset is done (> 1)
    AND R4, R4, #0
    ADD R4, R4, #2      ; R4 = 2
    NOT R4, R4
    ADD R4, R4, #1      ; R4 = -2
    ADD R4, R4, R3      ; R4 = R3 - 2
    BRzp X_CLEAR_DONE

    ; Reset Z offset counter (-1 to 1)
    AND R5, R5, #0
    ADD R5, R5, #-1

    Z_CLEAR_LOOP
        ; Check if Z offset is done (> 1)
        AND R6, R6, #0
        ADD R6, R6, #2  ; R6 = 2
        NOT R6, R6
        ADD R6, R6, #1  ; R6 = -2
        ADD R6, R6, R5  ; R6 = R5 - 2
        BRzp Z_CLEAR_DONE

        ; Calculate X and Z positions
        LD R0, PLAYER_X
        ADD R0, R0, R3  ; X = player_x + x_offset
        LD R2, PLAYER_Z
        ADD R2, R2, R5  ; Z = player_z + z_offset

        ; Get the actual height at this position
        GETH            ; getHeight(R0, R2) -> R1
        ST R1, CURRENT_HEIGHT

        ; Store X offset for restoration
        ST R3, X_OFFSET_TEMP

        ; Compare this position's height with target height
        LD R4, TARGET_HEIGHT
        LD R1, CURRENT_HEIGHT
        NOT R6, R4      ; R6 = -target_height
        ADD R6, R6, #1
        ADD R6, R1, R6  ; R6 = current_height - target_height

        BRnz NEXT_POSITION  ; If current_height <= target, skip cutting

        ; Cut down: start from current height and go down to target+1
        LD R1, CURRENT_HEIGHT

        Y_CLEAR_LOOP
            ; Check if we've reached target height
            LD R6, TARGET_HEIGHT
            NOT R6, R6
            ADD R6, R6, #1      ; R6 = -target_height
            ADD R6, R1, R6      ; R6 = current_y - target_height
            BRnz Y_CLEAR_DONE   ; If current_y <= target, done with this column

            ; Place air block (ID #0)
            AND R7, R7, #0      ; Block ID = 0 (air)
            ADD R3, R7, #0      ; Move to R3 for SETB
            SETB                ; setBlock(R0, R1, R2, R3)

            ; Restore R3 (X offset) from memory
            LD R3, X_OFFSET_TEMP

            ; Move down one Y level
            ADD R1, R1, #-1
            BR Y_CLEAR_LOOP

        Y_CLEAR_DONE
            ADD R0, R0, #0      ; No-op instruction

        NEXT_POSITION
            ; Restore R3 for loop continuation
            LD R3, X_OFFSET_TEMP
            ; Increment Z offset
            ADD R5, R5, #1
            BR Z_CLEAR_LOOP

    Z_CLEAR_DONE
        ; Increment X offset
        ADD R3, R3, #1
        BR X_CLEAR_LOOP

X_CLEAR_DONE

; Second half: Fill air blocks underneath surface with dirt blocks
; Initialize X offset counter (-1 to 1)
AND R3, R3, #0
ADD R3, R3, #-1

X_FILL_LOOP
    ; Check if X offset is done (> 1)
    AND R4, R4, #0
    ADD R4, R4, #2      ; R4 = 2
    NOT R4, R4
    ADD R4, R4, #1      ; R4 = -2
    ADD R4, R4, R3      ; R4 = R3 - 2
    BRzp X_FILL_DONE

    ; Reset Z offset counter (-1 to 1)
    AND R5, R5, #0
    ADD R5, R5, #-1

    Z_FILL_LOOP
        ; Check if Z offset is done (> 1)
        AND R6, R6, #0
        ADD R6, R6, #2  ; R6 = 2
        NOT R6, R6
        ADD R6, R6, #1  ; R6 = -2
        ADD R6, R6, R5  ; R6 = R5 - 2
        BRzp Z_FILL_DONE

        ; Calculate X and Z positions
        LD R0, PLAYER_X
        ADD R0, R0, R3  ; X = player_x + x_offset
        LD R2, PLAYER_Z
        ADD R2, R2, R5  ; Z = player_z + z_offset

        ; Store X offset for restoration (use separate memory location)
        ST R3, X_OFFSET_TEMP

        ; Start Y from player position - 1 (go downward)
        LD R1, PLAYER_Y
        ADD R1, R1, #-1

        Y_FILL_LOOP
            ; Check if we've gone below Y=0 (reasonable lower bound)
            ADD R1, R1, #0  ; Test R1
            BRn Y_FILL_DONE ; If Y < 0, done with this column

            ; Check what block is currently at this position
            GETB            ; getBlock(R0, R1, R2) -> R3

            ; Only place dirt if current block is air (ID #0)
            ADD R3, R3, #0  ; Test if R3 is zero
            BRnp SKIP_FILL  ; If not air, skip placement

            ; Place dirt block (ID #3)
            AND R7, R7, #0
            ADD R7, R7, #3  ; Block ID = 3 (dirt)
            ADD R3, R7, #0  ; Move block ID to R3 for SETB
            SETB            ; setBlock(R0, R1, R2, R3)

        SKIP_FILL
            ; Restore R3 (X offset) from memory
            LD R3, X_OFFSET_TEMP

            ; Move to next Y level (downward)
            ADD R1, R1, #-1
            BR Y_FILL_LOOP

        Y_FILL_DONE
            ; Increment Z offset
            ADD R5, R5, #1
            BR Z_FILL_LOOP

    Z_FILL_DONE
        ; Increment X offset
        ADD R3, R3, #1
        BR X_FILL_LOOP

X_FILL_DONE
HALT

; Data storage
PLAYER_X        .FILL x0000
PLAYER_Y        .FILL x0000
PLAYER_Z        .FILL x0000
TARGET_HEIGHT   .FILL x0000 ; limit
CURRENT_HEIGHT  .FILL x0000 ; height -> if height < limit continue
X_OFFSET_TEMP   .FILL x0000

.END


; build up: from user coords to upward

; upper_range_y = GETH
; while upper_range_y >= player_y:
;         upper_range_y--;
;         set 3x3 block at y to be air


; build down
