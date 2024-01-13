.data
    reg_root: .space 32
    .globl main
    __prompt__: .asciiz "Enter an integer: "
    __lf__: .asciiz "\n"
.text

    main:
        lw $t0, reg_root
        li $t0, 1
        lw $t1, reg_root + 4
        li $t1, 2
        lw $t2, reg_root + 8
        li $t2, 3
        lw $t3, reg_root + 12
        li $t3, 1
        lw $t4, reg_root + 16
        li $t4, 1
        la $a0, __prompt__
        li $v0, 4
        syscall
        lw $t5, reg_root + 20
        li $v0, 5
        syscall
        move $t5, $v0
        sw $t0, reg_root
        sw $t1, reg_root + 4
        sw $t2, reg_root + 8
        sw $t3, reg_root + 12
        sw $t4, reg_root + 16
        sw $t5, reg_root + 20
        lw $t0, reg_root + 20
        li $a1, 1
        bge $t0, $a1, label_0
        li $a0, 0
        li $v0, 1
        syscall
        la $a0, __lf__
        li $v0, 4
        syscall
        sw $t0, reg_root + 20
        j label_1
    label_0:
        lw $t0, reg_root + 20
        li $a1, 1
        beq $t0, $a1, label_4
        sw $t0, reg_root + 20
        lw $t0, reg_root + 20
        li $a1, 2
        bne $t0, $a1, label_2
        sw $t0, reg_root + 20
    label_4:
        li $a0, 1
        li $v0, 1
        syscall
        la $a0, __lf__
        li $v0, 4
        syscall
        j label_3
    label_2:
        lw $t0, reg_root + 20
        li $a1, 2
        ble $t0, $a1, label_5
        lw $t1, reg_root + 24
        li $t1, 3
        sw $t0, reg_root + 20
        sw $t1, reg_root + 24
    label_6:
        lw $t0, reg_root + 24
        lw $t1, reg_root + 20
        bgt $t0, $t1, label_7
        lw $t2, reg_root + 28
        lw $t3, reg_root + 12
        lw $t4, reg_root + 16
        add $t2, $t3, $t4
        move $t3, $t4
        move $t4, $t2
        addi $t0, $t0, 1
        sw $t0, reg_root + 24
        sw $t1, reg_root + 20
        sw $t2, reg_root + 28
        sw $t3, reg_root + 12
        sw $t4, reg_root + 16
        j label_6
    label_7:
        lw $t0, reg_root + 28
        move $a0, $t0
        li $v0, 1
        syscall
        la $a0, __lf__
        li $v0, 4
        syscall
        sw $t0, reg_root + 28
    label_5:
    label_3:
    label_1:
        li $v0, 10
        syscall
