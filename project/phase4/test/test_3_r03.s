.data
    reg_root: .space 24
    .globl main
    __prompt__: .asciiz "Enter an integer: "
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
    label_0:
        bgt $t3, $t0, label_1
        sw $t0, reg_root
        sw $t1, reg_root + 4
        sw $t2, reg_root + 8
        sw $t3, reg_root + 12
    label_2:
        lw $t0, reg_root + 8
        lw $t1, reg_root + 12
        bgt $t0, $t1, label_3
        sw $t0, reg_root + 8
        sw $t1, reg_root + 12
        lw $t0, reg_root + 16
        lw $t1, reg_root + 12
        lw $t2, reg_root + 8
        div $t0, $t1, $t2
        lw $t3, reg_root + 20
        mul $t3, $t0, $t2
        bne $t1, $t3, label_4
        sw $t0, reg_root + 16
        sw $t1, reg_root + 12
        sw $t2, reg_root + 8
        sw $t3, reg_root + 20
        lw $t0, reg_root + 4
        addi $t0, $t0, 1
    label_4:
        sw $t0, reg_root + 4
        lw $t0, reg_root + 8
        addi $t0, $t0, 1
        j label_2
    label_3:
        sw $t0, reg_root + 8
        lw $t0, reg_root + 4
        li $a1, 2
        bne $t0, $a1, label_5
        sw $t0, reg_root + 4
        lw $t0, reg_root + 12
        move $a0, $t0
        li $v0, 1
        syscall
    label_5:
        sw $t0, reg_root + 12
        lw $t0, reg_root + 8
        li $t0, 1
        lw $t1, reg_root + 4
        li $t1, 0
        lw $t2, reg_root + 12
        addi $t2, $t2, 1
        j label_0
    label_1:
        sw $t0, reg_root + 8
        sw $t1, reg_root + 4
        sw $t2, reg_root + 12
        li $v0, 10
        syscall
