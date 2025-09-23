; terraform.asm
; Flattens a 3x3 area centered underneath the player
; Uses getHeight to find the target height at player position
; Builds up with dirt blocks (ID #3) or cuts down with air blocks (ID #0)

.ORIG x3000

; Get player position
GETP            ; Gets player position into R0, R1, R2

; Store player position
ST R0, PLAYER_X
ST R1, PLAYER_Y
ST R2, PLAYER_Z

; Get the target height at player position
; Use GETH to get height at (player_x, player_z)
GETH            ; getHeight(R0, R2) -> R1
ST R1, TARGET_HEIGHT

; Initialize loop counters for 3x3 area
; X offset: -1, 0, 1 (relative to player)
; Z offset: -1, 0, 1 (relative to player)

AND R3, R3, #0  ; R3 = X offset counter (-1 to 1)
ADD R3, R3, #-1 ; Start at -1

X_LOOP
    ; Check if X offset is done (> 1)
    AND R4, R4, #0
    ADD R4, R4, #2  ; R4 = 2
    NOT R4, R4
    ADD R4, R4, #1  ; R4 = -2
    ADD R4, R4, R3  ; R4 = R3 - 2
    BRzp X_LOOP_DONE

    ; Reset Z offset counter
    AND R5, R5, #0  ; R5 = Z offset counter (-1 to 1)
    ADD R5, R5, #-1 ; Start at -1

    Z_LOOP
        ; Check if Z offset is done (> 1)
        AND R6, R6, #0
        ADD R6, R6, #2  ; R6 = 2
        NOT R6, R6
        ADD R6, R6, #1  ; R6 = -2
        ADD R6, R6, R5  ; R6 = R5 - 2
        BRzp Z_LOOP_DONE

        ; Calculate current tile position
        LD R0, PLAYER_X
        ADD R0, R0, R3  ; X = player_x + x_offset
        LD R2, PLAYER_Z
        ADD R2, R2, R5  ; Z = player_z + z_offset

        ; Get height at this position
        GETH            ; getHeight(R0, R2) -> R1
        ST R1, CURRENT_HEIGHT

        ; Load target height for comparison
        LD R4, TARGET_HEIGHT
        LD R1, CURRENT_HEIGHT

        ; Compare current height with target height
        NOT R6, R4      ; R6 = -target_height
        ADD R6, R6, #1
        ADD R6, R1, R6  ; R6 = current_height - target_height

        BRz NEXT_TILE   ; If equal, skip this tile
        BRn BUILD_UP    ; If current < target, build up
        BRp CUT_DOWN    ; If current > target, cut down

BUILD_UP
        ; Build up from current_height+1 to target_height
        ; R1 = current height, R4 = target height
        ADD R1, R1, #1  ; Start from current_height + 1

BUILD_LOOP
        ; Check if we've reached target height
        NOT R6, R4      ; R6 = -target_height
        ADD R6, R6, #1
        ADD R6, R1, R6  ; R6 = current_y - target_height
        BRp NEXT_TILE   ; If current_y > target, we're done

        ; Check if block at this position is air before placing dirt
        ; R0 = x, R1 = y, R2 = z
        GETB            ; getBlock(R0, R1, R2) -> R3

        ; Only place dirt if current block is air (ID #0)
        ADD R3, R3, #0  ; Test if R3 is zero
        BRnp SKIP_PLACE ; If not air, skip placement

        ; Place dirt block (ID #3)
        AND R3, R3, #0
        ADD R3, R3, #3  ; Block ID = 3 (dirt)
        SETB            ; setBlock(R0, R1, R2, R3)

SKIP_PLACE
        ADD R1, R1, #1  ; Move to next Y level
        BR BUILD_LOOP

CUT_DOWN
        ; Cut down from current_height to target_height+1
        ; R1 = current height, R4 = target height
        ADD R1, R1, #0      ; No-op to separate labels

CUT_LOOP
        ; Check if we've reached target height
        NOT R6, R4      ; R6 = -target_height
        ADD R6, R6, #1
        ADD R6, R1, R6  ; R6 = current_y - target_height
        BRnz NEXT_TILE  ; If current_y <= target, we're done

        ; Replace block with air (ID #0)
        AND R3, R3, #0  ; Block ID = 0 (air)
        SETB            ; setBlock(R0, R1, R2, R3)

        ADD R1, R1, #-1 ; Move down one Y level
        BR CUT_LOOP

NEXT_TILE
        ; Increment Z offset
        ADD R5, R5, #1
        BR Z_LOOP

    Z_LOOP_DONE
        ; Increment X offset
        ADD R3, R3, #1
        BR X_LOOP

X_LOOP_DONE
    HALT

; Data storage
PLAYER_X        .FILL x0000
PLAYER_Y        .FILL x0000
PLAYER_Z        .FILL x0000
TARGET_HEIGHT   .FILL x0000
CURRENT_HEIGHT  .FILL x0000

.END


; build up: from user coords to upward

; while block is not air:
;         y++
;         set 3x3 block at y to be air


; build down
