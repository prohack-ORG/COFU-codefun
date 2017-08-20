// sample ADD kernel using armv7 assembly

.func SimpleADD_arm_asm
.global SimpleADD_arm_asm

SimpleADD_arm_asm:

MOV r0, #0

loop:
ADD r0, r0, #1
CMP r0, #10
BLT loop

.endfunc
.end
