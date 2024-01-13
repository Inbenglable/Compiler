main:
li $t0, 1
li $t1, 2
li $t2, 3
li $t3, 1
li $t4, 1
addi $sp, $sp, -4
sw $t5, 0($sp)
jal read
lw $t5, 0($sp)
addi $sp, $sp, 4
li $a1, 1
bge $t5, $a1, label_0
li $a0, 0
addi $sp, $sp, -4
sw $a0, 0($sp)
jal write
lw $a0, 0($sp)
addi $sp, $sp, 4
j label_1
label_0:
li $a1, 1
beq $t5, $a1, label_4
li $a1, 2
bne $t5, $a1, label_2
label_4:
li $a0, 1
addi $sp, $sp, -4
sw $a0, 0($sp)
jal write
lw $a0, 0($sp)
addi $sp, $sp, 4
j label_3
label_2:
li $a1, 2
ble $t5, $a1, label_5
li $t6, 3
label_6:
bgt $t6, $t5, label_7
add $t7, $t3, $t4
move $t3, $t4
move $t4, $t7
addi $t6, $t6, 1
j label_6
label_7:
move $a0, $t7
addi $sp, $sp, -4
sw $a0, 0($sp)
jal write
lw $a0, 0($sp)
addi $sp, $sp, 4
label_5:
label_3:
label_1:
li $v0, 0
jr $ra
