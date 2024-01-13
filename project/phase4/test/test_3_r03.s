.data
    reg_root: .space 24
    .globl main
    __prompt__: .asciiz "Enter an integer: "
    __lf__: .asciiz "\n"
.text

    main:
        lw $t0, reg_root
        li $t0, 30
        lw $t1, reg_root + 4
        li $t1, 0
        lw $t2, reg_root + 8
        li $t2, 1
        lw $t3, reg_root + 12
        li $t3, 1
        sw $t0, reg_root
        sw $t1, reg_root + 4
        sw $t2, reg_root + 8
        sw $t3, reg_root + 12
    label_0:
        lw $t0, reg_root + 12
        lw $t1, reg_root
        bgt $t0, $t1, label_1
        sw $t0, reg_root + 12
        sw $t1, reg_root
    label_2:
        lw $t0, reg_root + 8
        lw $t1, reg_root + 12
        bgt $t0, $t1, label_3
        lw $t2, reg_root + 16
        div $t2, $t1, $t0
        lw $t3, reg_root + 20
        mul $t3, $t2, $t0
        sw $t0, reg_root + 8
        sw $t1, reg_root + 12
        sw $t2, reg_root + 16
        sw $t3, reg_root + 20
        lw $t0, reg_root + 12
        lw $t1, reg_root + 20
        bne $t0, $t1, label_4
        lw $t2, reg_root + 4
        addi $t2, $t2, 1
        sw $t0, reg_root + 12
        sw $t1, reg_root + 20
        sw $t2, reg_root + 4
    label_4:
        lw $t0, reg_root + 8
        addi $t0, $t0, 1
        sw $t0, reg_root + 8
        j label_2
    label_3:
        lw $t0, reg_root + 4
        li $a1, 2
        bne $t0, $a1, label_5
        lw $t1, reg_root + 12
        move $a0, $t1
        li $v0, 1
        syscall
        la $a0, __lf__
        li $v0, 4
        syscall
        sw $t0, reg_root + 4
        sw $t1, reg_root + 12
    label_5:
        lw $t0, reg_root + 8
        li $t0, 1
        lw $t1, reg_root + 4
        li $t1, 0
        lw $t2, reg_root + 12
        addi $t2, $t2, 1
        sw $t0, reg_root + 8
        sw $t1, reg_root + 4
        sw $t2, reg_root + 12
        j label_0
    label_1:
        li $v0, 10
        syscall
