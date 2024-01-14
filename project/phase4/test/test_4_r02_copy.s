.data
    reg_root: .space 0
    .globl main
    __prompt__: .asciiz "Enter an integer: "
    __lf__: .asciiz "\n"
.text

    main:
        la $a0, __prompt__
        li $v0, 4
        syscall
        li $v0, 5
        syscall
        move $v1, $v0
        move $v1, $v1
        move $v1, $v1
        li $v1, 0
        bgt $v1, $v1, label0
        j label1
    label0:
        li $v1, 1
        move $a0, $v1
        li $v0, 1
        syscall
        la $a0, __lf__
        li $v0, 4
        syscall
        j label2
    label1:
        move $v1, $v1
        li $v1, 0
        blt $v1, $v1, label3
        j label4
    label3:
        li $v1, 1
        addi $v1, $v1, 0
        move $a0, $v1
        li $v0, 1
        syscall
        la $a0, __lf__
        li $v0, 4
        syscall
        j label5
    label4:
        li $v1, 0
        move $a0, $v1
        li $v0, 1
        syscall
        la $a0, __lf__
        li $v0, 4
        syscall
    label5:
    label2:
        li $v1, 0
        li $v0, 10
        syscall
