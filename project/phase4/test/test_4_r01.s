.data
    reg_root: .space 48
    .globl main
    __prompt__: .asciiz "Enter an integer: "
    __lf__: .asciiz "\n"
.text

    hanoi:
        addi $sp, $sp, -4
        sw $ra, 0($sp)
        lw $t0, reg_root
        lw $t0, 4($sp)
        lw $t1, reg_root + 4
        lw $t1, 8($sp)
        lw $t2, reg_root + 8
        lw $t2, 12($sp)
        lw $t3, reg_root + 12
        lw $t3, 16($sp)
        sw $t0, reg_root
        sw $t1, reg_root + 4
        sw $t2, reg_root + 8
        sw $t3, reg_root + 12
        lw $t0, reg_root
        li $a1, 1
        bne $t0, $a1, label_0
        lw $t1, reg_root + 16
        lw $t2, reg_root + 4
        mul $t1, $t2, 10000
        lw $t3, reg_root + 20
        lw $t4, reg_root + 12
        add $t3, $t1, $t4
        move $a0, $t3
        li $v0, 1
        syscall
        la $a0, __lf__
        li $v0, 4
        syscall
        sw $t0, reg_root
        sw $t1, reg_root + 16
        sw $t2, reg_root + 4
        sw $t3, reg_root + 20
        sw $t4, reg_root + 12
        j label_1
    label_0:
        lw $t0, reg_root + 24
        lw $t1, reg_root
        addi $t0, $t1, -1
        addi $sp, $sp, -4
        sw $t1, 0($sp)
        lw $t2, reg_root + 4
        addi $sp, $sp, -4
        sw $t2, 0($sp)
        lw $t3, reg_root + 8
        addi $sp, $sp, -4
        sw $t3, 0($sp)
        lw $t4, reg_root + 12
        addi $sp, $sp, -4
        sw $t4, 0($sp)
        lw $t5, reg_root + 16
        addi $sp, $sp, -4
        sw $t5, 0($sp)
        lw $t6, reg_root + 20
        addi $sp, $sp, -4
        sw $t6, 0($sp)
        addi $sp, $sp, -4
        sw $t0, 0($sp)
        lw $t7, reg_root + 28
        addi $sp, $sp, -4
        sw $t7, 0($sp)
        lw $s0, reg_root + 32
        addi $sp, $sp, -4
        sw $s0, 0($sp)
        lw $s1, reg_root + 36
        addi $sp, $sp, -4
        sw $s1, 0($sp)
        lw $s2, reg_root + 40
        addi $sp, $sp, -4
        sw $s2, 0($sp)
        move $a0, $t3
        addi $sp, $sp, -4
        sw $a0, 0($sp)
        move $a0, $t4
        addi $sp, $sp, -4
        sw $a0, 0($sp)
        move $a0, $t2
        addi $sp, $sp, -4
        sw $a0, 0($sp)
        move $a0, $t0
        addi $sp, $sp, -4
        sw $a0, 0($sp)
        sw $t0, reg_root + 24
        sw $t1, reg_root
        sw $t2, reg_root + 4
        sw $t3, reg_root + 8
        sw $t4, reg_root + 12
        sw $t5, reg_root + 16
        sw $t6, reg_root + 20
        sw $t7, reg_root + 28
        sw $s0, reg_root + 32
        sw $s1, reg_root + 36
        sw $s2, reg_root + 40
        LABEL
        lw $t0, reg_root + 28
        lw $t1, reg_root + 4
        mul $t0, $t1, 10000
        lw $t2, reg_root + 32
        lw $t3, reg_root + 12
        add $t2, $t0, $t3
        move $a0, $t2
        li $v0, 1
        syscall
        la $a0, __lf__
        li $v0, 4
        syscall
        lw $t4, reg_root + 36
        move $t4, $t1
        lw $t5, reg_root + 40
        move $t5, $t3
        move $a0, $t5
        addi $sp, $sp, -4
        sw $a0, 0($sp)
        move $a0, $t4
        addi $sp, $sp, -4
        sw $a0, 0($sp)
        lw $t6, reg_root + 8
        move $a0, $t6
        addi $sp, $sp, -4
        sw $a0, 0($sp)
        lw $t7, reg_root + 24
        move $a0, $t7
        addi $sp, $sp, -4
        sw $a0, 0($sp)
        sw $t0, reg_root + 28
        sw $t1, reg_root + 4
        sw $t2, reg_root + 32
        sw $t3, reg_root + 12
        sw $t4, reg_root + 36
        sw $t5, reg_root + 40
        sw $t6, reg_root + 8
        sw $t7, reg_root + 24
        LABEL
    label_1:
        li $v0, 0
        lw $ra, 0($sp)
        addi $sp, $sp, 20
        jr $ra
    main:
        lw $t0, reg_root + 44
        li $t0, 3
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
        sw $t0, reg_root + 44
        LABEL
        li $v0, 10
        syscall
