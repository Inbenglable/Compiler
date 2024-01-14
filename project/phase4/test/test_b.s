.data
    reg_root: .space 56
    .globl main
    __prompt__: .asciiz "Enter an integer: "
    __lf__: .asciiz "\n"
.text

    fun4:
        addi $sp, $sp, -4
        sw $ra, 0($sp)
        lw $t0, reg_root
        lw $t0, 4($sp)
        lw $t1, reg_root + 4
        lw $t1, 8($sp)
        lw $t2, reg_root + 8
        add $t2, $t0, $t1
        move $a0, $t2
        li $v0, 1
        syscall
        la $a0, __lf__
        li $v0, 4
        syscall
        li $v0, 0
        lw $ra, 0($sp)
        addi $sp, $sp, 12
        jr $ra
    fun3:
        sw $t0, reg_root
        sw $t1, reg_root + 4
        sw $t2, reg_root + 8
        addi $sp, $sp, -4
        sw $ra, 0($sp)
        lw $t0, reg_root + 12
        lw $t0, 4($sp)
        lw $t1, reg_root + 16
        lw $t1, 8($sp)
        addi $sp, $sp, -4
        sw $t0, 0($sp)
        addi $sp, $sp, -4
        sw $t1, 0($sp)
        lw $t2, reg_root + 20
        addi $sp, $sp, -4
        sw $t2, 0($sp)
        li $a0, 85694
        addi $sp, $sp, -4
        sw $a0, 0($sp)
        li $a0, 33629
        addi $sp, $sp, -4
        sw $a0, 0($sp)
        sw $t0, reg_root + 12
        sw $t1, reg_root + 16
        sw $t2, reg_root + 20
        LABEL
        li $a0, 85694
        addi $sp, $sp, -4
        sw $a0, 0($sp)
        li $a0, 33629
        addi $sp, $sp, -4
        sw $a0, 0($sp)
        LABEL
        lw $t0, reg_root + 20
        lw $t1, reg_root + 12
        lw $t2, reg_root + 16
        add $t0, $t1, $t2
        move $a0, $t0
        li $v0, 1
        syscall
        la $a0, __lf__
        li $v0, 4
        syscall
        li $v0, 0
        lw $ra, 0($sp)
        addi $sp, $sp, 12
        jr $ra
    fun2:
        sw $t0, reg_root + 20
        sw $t1, reg_root + 12
        sw $t2, reg_root + 16
        addi $sp, $sp, -4
        sw $ra, 0($sp)
        lw $t0, reg_root + 24
        lw $t0, 4($sp)
        lw $t1, reg_root + 28
        lw $t1, 8($sp)
        li $a0, 56731
        addi $sp, $sp, -4
        sw $a0, 0($sp)
        li $a0, 13211
        addi $sp, $sp, -4
        sw $a0, 0($sp)
        sw $t0, reg_root + 24
        sw $t1, reg_root + 28
        LABEL
        li $a0, 56731
        addi $sp, $sp, -4
        sw $a0, 0($sp)
        li $a0, 13211
        addi $sp, $sp, -4
        sw $a0, 0($sp)
        LABEL
        lw $t0, reg_root + 32
        lw $t1, reg_root + 24
        lw $t2, reg_root + 28
        add $t0, $t1, $t2
        move $a0, $t0
        li $v0, 1
        syscall
        la $a0, __lf__
        li $v0, 4
        syscall
        li $v0, 0
        lw $ra, 0($sp)
        addi $sp, $sp, 12
        jr $ra
    fun1:
        sw $t0, reg_root + 32
        sw $t1, reg_root + 24
        sw $t2, reg_root + 28
        addi $sp, $sp, -4
        sw $ra, 0($sp)
        lw $t0, reg_root + 36
        lw $t0, 4($sp)
        lw $t1, reg_root + 40
        lw $t1, 8($sp)
        li $a0, 2310
        addi $sp, $sp, -4
        sw $a0, 0($sp)
        li $a0, 62000
        addi $sp, $sp, -4
        sw $a0, 0($sp)
        sw $t0, reg_root + 36
        sw $t1, reg_root + 40
        LABEL
        li $a0, 2310
        addi $sp, $sp, -4
        sw $a0, 0($sp)
        li $a0, 62000
        addi $sp, $sp, -4
        sw $a0, 0($sp)
        LABEL
        lw $t0, reg_root + 44
        lw $t1, reg_root + 36
        lw $t2, reg_root + 40
        add $t0, $t1, $t2
        move $a0, $t0
        li $v0, 1
        syscall
        la $a0, __lf__
        li $v0, 4
        syscall
        li $v0, 0
        lw $ra, 0($sp)
        addi $sp, $sp, 12
        jr $ra
    main:
        sw $t0, reg_root + 44
        sw $t1, reg_root + 36
        sw $t2, reg_root + 40
        li $a0, 810
        addi $sp, $sp, -4
        sw $a0, 0($sp)
        li $a0, 1919
        addi $sp, $sp, -4
        sw $a0, 0($sp)
        LABEL
        li $a0, 810
        addi $sp, $sp, -4
        sw $a0, 0($sp)
        li $a0, 1919
        addi $sp, $sp, -4
        sw $a0, 0($sp)
        LABEL
        lw $t0, reg_root + 48
        li $t0, 514
        lw $t1, reg_root + 52
        li $t1, 114
        li $a0, 628
        li $v0, 1
        syscall
        la $a0, __lf__
        li $v0, 4
        syscall
        li $v0, 10
        syscall
