.data
    reg_root: .space 44
    .globl main
    __prompt__: .asciiz "Enter an integer: "
    __lf__: .asciiz "\n"
.text

    calculateBinomialCoefficient:
        addi $sp, $sp, -4
        sw $ra, 0($sp)
        lw $t0, reg_root
        lw $t0, 4($sp)
        lw $t1, reg_root + 4
        lw $t1, 8($sp)
        lw $t2, reg_root + 8
        li $t2, 1
        lw $t3, reg_root + 12
        li $t3, 0
        sw $t0, reg_root
        sw $t1, reg_root + 4
        sw $t2, reg_root + 8
        sw $t3, reg_root + 12
        lw $t0, reg_root
        lw $t1, reg_root + 4
        bge $t0, $t1, label_0
        li $v0, 0
        lw $ra, 0($sp)
        addi $sp, $sp, 12
        jr $ra
        sw $t0, reg_root
        sw $t1, reg_root + 4
    label_0:
        lw $t0, reg_root + 16
        lw $t1, reg_root
        lw $t2, reg_root + 4
        sub $t0, $t1, $t2
        sw $t0, reg_root + 16
        sw $t1, reg_root
        sw $t2, reg_root + 4
        lw $t0, reg_root + 4
        lw $t1, reg_root + 16
        ble $t0, $t1, label_1
        lw $t2, reg_root
        sub $t0, $t2, $t0
        sw $t0, reg_root + 4
        sw $t1, reg_root + 16
        sw $t2, reg_root
    label_1:
    label_2:
        lw $t0, reg_root + 12
        lw $t1, reg_root + 4
        bge $t0, $t1, label_3
        lw $t2, reg_root + 20
        lw $t3, reg_root
        sub $t2, $t3, $t0
        lw $t4, reg_root + 24
        lw $t5, reg_root + 8
        mul $t4, $t5, $t2
        lw $t6, reg_root + 28
        addi $t6, $t0, 1
        div $t5, $t4, $t6
        addi $t0, $t0, 1
        sw $t0, reg_root + 12
        sw $t1, reg_root + 4
        sw $t2, reg_root + 20
        sw $t3, reg_root
        sw $t4, reg_root + 24
        sw $t5, reg_root + 8
        sw $t6, reg_root + 28
        j label_2
    label_3:
        lw $t0, reg_root + 8
        move $v0, $t0
        lw $ra, 0($sp)
        addi $sp, $sp, 12
        jr $ra
    main:
        sw $t0, reg_root + 8
        la $a0, __prompt__
        li $v0, 4
        syscall
        lw $t0, reg_root + 32
        li $v0, 5
        syscall
        move $t0, $v0
        la $a0, __prompt__
        li $v0, 4
        syscall
        lw $t1, reg_root + 36
        li $v0, 5
        syscall
        move $t1, $v0
        addi $sp, $sp, -4
        sw $t0, 0($sp)
        addi $sp, $sp, -4
        sw $t1, 0($sp)
        lw $t2, reg_root + 40
        addi $sp, $sp, -4
        sw $t2, 0($sp)
        move $a0, $t1
        addi $sp, $sp, -4
        sw $a0, 0($sp)
        move $a0, $t0
        addi $sp, $sp, -4
        sw $a0, 0($sp)
        sw $t0, reg_root + 32
        sw $t1, reg_root + 36
        sw $t2, reg_root + 40
        LABEL
        lw $t0, reg_root + 40
        move $a0, $t0
        li $v0, 1
        syscall
        la $a0, __lf__
        li $v0, 4
        syscall
        li $v0, 10
        syscall
