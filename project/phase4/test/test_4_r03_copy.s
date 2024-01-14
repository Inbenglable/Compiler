.data
    reg_root: .space 0
    .globl main
    __prompt__: .asciiz "Enter an integer: "
    __lf__: .asciiz "\n"
.text

    main:
        li $v1, 110
        li $v1, 97
        li $v1, 3
        sub $v1, $v1, $v1
        li $v1, 2
        mul $v1, $v1, $v1
        add $v1, $v1, $v1
        move $v1, $v1
        move $v1, $v1
        move $a0, $v1
        li $v0, 1
        syscall
        la $a0, __lf__
        li $v0, 4
        syscall
        li $v1, 0
        li $v0, 10
        syscall
