.text

    hanoi:
        lw $t0, 0($sp)
        addi $sp, $sp, 4
        lw $t1, 0($sp)
        addi $sp, $sp, 4
        lw $t2, 0($sp)
        addi $sp, $sp, 4
        lw $t3, 0($sp)
        addi $sp, $sp, 4
        li $a1, 1
        bne $t0, $a1, label_0
        mul $t4, $t1, 10000
        add $t5, $t4, $t3
        move $a0, $t5
        li $v0, 1
        syscall
        j label_1
    label_0:
        addi $t6, $t0, -1
        move $a0, $t2
        addi $sp, $sp, -4
        sw $a0, 0($sp)
        move $a0, $t3
        addi $sp, $sp, -4
        sw $a0, 0($sp)
        move $a0, $t1
        addi $sp, $sp, -4
        sw $a0, 0($sp)
        move $a0, $t6
        addi $sp, $sp, -4
        sw $a0, 0($sp)
        jal hanoi
        move $v1, $v0
        mul $t7, $t1, 10000
        add $s0, $t7, $t3
        move $a0, $s0
        li $v0, 1
        syscall
        move $s1, $t1
        move $s2, $t3
        move $a0, $s2
        addi $sp, $sp, -4
        sw $a0, 0($sp)
        move $a0, $s1
        addi $sp, $sp, -4
        sw $a0, 0($sp)
        move $a0, $t2
        addi $sp, $sp, -4
        sw $a0, 0($sp)
        move $a0, $t6
        addi $sp, $sp, -4
        sw $a0, 0($sp)
        jal hanoi
        move $v1, $v0
    label_1:
        li $v0, 0
        jr $ra
    main:
        li $s3, 3
        li $a0, 3
        addi $sp, $sp, -4
        sw $a0, 0($sp)
        li $a0, 2
        addi $sp, $sp, -4
        sw $a0, 0($sp)
        li $a0, 1
        addi $sp, $sp, -4
        sw $a0, 0($sp)
        li $a0, 3
        addi $sp, $sp, -4
        sw $a0, 0($sp)
        jal hanoi
        move $v1, $v0
        li $v0, 0
        jr $ra
