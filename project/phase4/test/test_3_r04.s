.text

    mod:
        addi $sp, $sp, -4
        sw $ra, 0($sp)
        lw $t0, 4($sp)
        lw $t1, 8($sp)
        div $t2, $t0, $t1
        mul $t3, $t2, $t1
        sub $t4, $t0, $t3
        move $v0, $t4
        lw $ra, 0($sp)
        addi $sp, $sp, 12
        jr $ra
    isPerfectNumber:
        addi $sp, $sp, -4
        sw $ra, 0($sp)
        lw $t5, 4($sp)
        li $t6, 0
        li $t7, 1
    label_0:
        div $s0, $t5, 2
        bgt $t7, $s0, label_1
        move $a0, $t7
        addi $sp, $sp, -4
        sw $a0, 0($sp)
        move $a0, $t5
        addi $sp, $sp, -4
        sw $a0, 0($sp)
        jal mod
        move $s1, $v0
        li $a1, 0
        bne $s1, $a1, label_2
        add $t6, $t6, $t7
    label_2:
        addi $t7, $t7, 1
        j label_0
    label_1:
        bne $t6, $t5, label_3
        li $v0, 1
        lw $ra, 0($sp)
        addi $sp, $sp, 8
        jr $ra
        j label_4
    label_3:
        li $v0, 0
        lw $ra, 0($sp)
        addi $sp, $sp, 8
        jr $ra
    label_4:
    main:
        li $s2, 0
        li $s3, 1
    label_5:
        li $a1, 100
        bgt $s3, $a1, label_6
        move $a0, $s3
        addi $sp, $sp, -4
        sw $a0, 0($sp)
        jal isPerfectNumber
        move $s4, $v0
        li $a1, 1
        bne $s4, $a1, label_7
        move $a0, $s3
        li $v0, 1
        syscall
    label_7:
        addi $s3, $s3, 1
        j label_5
    label_6:
        li $v0, 10
        syscall
