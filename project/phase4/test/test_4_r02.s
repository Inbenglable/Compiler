main:
addi $sp, $sp, -4
sw $t0, 0($sp)
jal read
lw $t0, 0($sp)
addi $sp, $sp, 4
li $a1, 0
ble $t0, $a1, label_0
li $a0, 1
addi $sp, $sp, -4
sw $a0, 0($sp)
jal write
lw $a0, 0($sp)
addi $sp, $sp, 4
j label_1
label_0:
li $a1, 0
bge $t0, $a1, label_2
li $a0, -1
addi $sp, $sp, -4
sw $a0, 0($sp)
jal write
lw $a0, 0($sp)
addi $sp, $sp, 4
j label_3
label_2:
li $a0, 0
addi $sp, $sp, -4
sw $a0, 0($sp)
jal write
lw $a0, 0($sp)
addi $sp, $sp, 4
label_3:
label_1:
li $v0, 0
jr $ra
