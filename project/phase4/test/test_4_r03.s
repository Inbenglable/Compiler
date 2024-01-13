main:
li $t0, 97
li $t1, 110
mul $t2, $t2, 3
addi $t3, $t2, 13
move $a0, $t3
addi $sp, $sp, -4
sw $a0, 0($sp)
jal write
lw $a0, 0($sp)
addi $sp, $sp, 4
li $v0, 0
jr $ra
