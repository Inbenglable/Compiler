.data
    reg_root: .space 44
    .globl main
    __prompt__: .asciiz "Enter an integer: "
    __lf__: .asciiz "\n"
.text

    main:
        la $a0, __prompt__
        li $v0, 4
        syscall
        lw $t0, reg_root
        li $v0, 5
        syscall
        move $t0, $v0
        lw $t1, reg_root + 4
        move $t1, $t0
        lw $t2, reg_root + 8
        move $t2, $t1
        lw $t3, reg_root + 12
        li $t3, 0
        sw $t0, reg_root
        sw $t1, reg_root + 4
        sw $t2, reg_root + 8
        sw $t3, reg_root + 12
        lw $t0, reg_root + 8
        lw $t1, reg_root + 12
        bgt $t0, $t1, label0
        sw $t0, reg_root + 8
        sw $t1, reg_root + 12
        j label1
    label0:
        lw $t0, reg_root + 16
        li $t0, 1
        move $a0, $t0
        li $v0, 1
        syscall
        la $a0, __lf__
        li $v0, 4
        syscall
        sw $t0, reg_root + 16
        j label2
    label1:
        lw $t0, reg_root + 20
        lw $t1, reg_root + 4
        move $t0, $t1
        lw $t2, reg_root + 24
        li $t2, 0
        sw $t0, reg_root + 20
        sw $t1, reg_root + 4
        sw $t2, reg_root + 24
        lw $t0, reg_root + 20
        lw $t1, reg_root + 24
        blt $t0, $t1, label3
        sw $t0, reg_root + 20
        sw $t1, reg_root + 24
        j label4
    label3:
        lw $t0, reg_root + 28
        li $t0, 1
        lw $t1, reg_root + 32
        li $a0, 0
        sub $t1, $a0, $t0
        move $a0, $t1
        li $v0, 1
        syscall
        la $a0, __lf__
        li $v0, 4
        syscall
        sw $t0, reg_root + 28
        sw $t1, reg_root + 32
        j label5
    label4:
        lw $t0, reg_root + 36
        li $t0, 0
        move $a0, $t0
        li $v0, 1
        syscall
        la $a0, __lf__
        li $v0, 4
        syscall
        sw $t0, reg_root + 36
    label5:
    label2:
        lw $t0, reg_root + 40
        li $t0, 0
        li $v0, 10
        syscall
