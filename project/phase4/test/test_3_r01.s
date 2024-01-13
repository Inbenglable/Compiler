.text

    pprriit:
        lw $t0, 0($sp)
        addi $sp, $sp, 4
        lw $t1, 0($sp)
        addi $sp, $sp, 4
        lw $t2, 0($sp)
        addi $sp, $sp, 4
        lw $t3, 0($sp)
        addi $sp, $sp, 4
        lw $t4, 0($sp)
        addi $sp, $sp, 4
        move $a0, $t0
        li $v0, 1
        syscall
        move $a0, $t1
        li $v0, 1
        syscall
        move $a0, $t2
        li $v0, 1
        syscall
        move $a0, $t3
        li $v0, 1
        syscall
        move $a0, $t4
        li $v0, 1
        syscall
        li $v0, 0
        jr $ra
    main:
        li $t5, 1
        li $t6, 2
        li $t7, 3
        li $s0, 4
        li $s1, 5
        li $a0, 5
        addi $sp, $sp, -4
        sw $a0, 0($sp)
        li $a0, 4
        addi $sp, $sp, -4
        sw $a0, 0($sp)
        li $a0, 3
        addi $sp, $sp, -4
        sw $a0, 0($sp)
        li $a0, 2
        addi $sp, $sp, -4
        sw $a0, 0($sp)
        li $a0, 1
        addi $sp, $sp, -4
        sw $a0, 0($sp)
        jal pprriit
        move $v1, $v0
        li $v0, 0
        jr $ra
