.data
    reg_root: .space 16
    .globl main
    __prompt__: .asciiz "Enter an integer: "
    __lf__: .asciiz "\n"
.text

    main:
        lw $t0, reg_root
        li $t0, 97
        lw $t1, reg_root + 4
        li $t1, 110
        lw $t2, reg_root + 8
        li $t2, 6
        lw $t3, reg_root + 12
        addi $t3, $t2, 13
        move $a0, $t3
        li $v0, 1
        syscall
        la $a0, __lf__
        li $v0, 4
        syscall
        li $v0, 10
        syscall
