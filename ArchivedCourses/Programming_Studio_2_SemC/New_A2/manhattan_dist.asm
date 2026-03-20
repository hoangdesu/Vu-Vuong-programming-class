.ORIG x3000

; init
AND R0, R0, #0 ; x
AND R1, R1, #0 ; y
AND R2, R2, #0 ; z
AND R3, R3, #0 ; dis_x
AND R4, R4, #0 ; dis_y
AND R5, R5, #0 ; dis_z
AND R6, R6, #0 ; G_X, G_Y, G_Z
AND R7, R7, #0

; your code here
GETP

; | playerPos. x − G_X |
; R3 = | R0 - R6 |
LD R6, G_X

NOT R3, R6       ; R3 = NOT R6
ADD R3, R3, #1   ; R3 = -R6
ADD R3, R0, R3   ; R3 = R0 - R6

BRzp DONE_X        ; if R3 >= 0, we're done
NOT R3, R3       ; else negate it
ADD R3, R3, #1


DONE_X

LD R6, G_Y

NOT R4, R6       
ADD R4, R4, #1   
ADD R4, R1, R4   

BRzp DONE_Y        
NOT R4, R4      
ADD R4, R4, #1

DONE_Y

LD R6, G_Z

NOT R5, R6       
ADD R5, R5, #1   
ADD R5, R2, R5   

BRzp DONE_Z        
NOT R5, R5      
ADD R5, R5, #1


DONE_Z

; R6 = R3 + R4 + R5
ADD R6, R3, R4
ADD R6, R6, R5

REG

LD R7, GOAL_DIST
NOT R7, R7 ; R7 = NOT(R7) = -R7 (= -11) => (not equal to 10 due to Two's Complement rule)
ADD R7, R7, #1 ; add 1 after flipping the bit
ADD R7, R6, R7 ; R7: signal to branch

BRnz IS_INBOUND


; ELSE block: IS_OUTBOUND
; >>> your else code here <<<
LEA R0, OUTBOUNDS
BRnzp END


IS_INBOUND
    LEA R0, INBOUNDS

END

PUTS
CHAT

HALT

; Note: Please do not change the names of the constants below
G_X .FILL #120
G_Y .FILL #100
G_Z .FILL #60
GOAL_DIST .FILL #10

INBOUNDS .STRINGZ "The player is within distance of the goal"
OUTBOUNDS .STRINGZ "The player is outside the goal bounds"
.END