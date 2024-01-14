.data
    reg_root: .space 36
    .globl main
    __prompt__: .asciiz "Enter an integer: "
    __lf__: .asciiz "\n"
.text

    main:
        lw $t0, reg_root
        li $t0, 110
        lw $t1, reg_root + 4
        li $t1, 97
        lw $t2, reg_root + 8
        li $t2, 3
        lw $t3, reg_root + 12
        sub $t3, $t0, $t1
        lw $t4, reg_root + 16
        li $t4, 2
        lw $t5, reg_root + 20
        mul $t5, $t2, $t4
        lw $t6, reg_root + 24
        add $t6, $t3, $t5
        move $t2, $t6
        lw $t7, reg_root + 28
        move $t7, $t2
        move $a0, $t7
        li $v0, 1
        syscall
        la $a0, __lf__
        li $v0, 4
        syscall
        lw $s0, reg_root + 32
        li $s0, 0
        li $v0, 10
        syscall
