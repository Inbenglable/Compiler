.data
    reg_root: .space 4
    .globl main
    __prompt__: .asciiz "Enter an integer: "
.text

    main:
        la $a0, __prompt__
        li $v0, 4
        syscall
        lw $t0, reg_root
        li $v0, 5
        syscall
        move $t0, $v0
        li $a1, 0
        ble $t0, $a1, label_0
        sw $t0, reg_root
        li $a0, 1
        li $v0, 1
        syscall
        j label_1
    label_0:
        lw $t0, reg_root
        li $a1, 0
        bge $t0, $a1, label_2
        sw $t0, reg_root
        li $a0, -1
        li $v0, 1
        syscall
        j label_3
    label_2:
        li $a0, 0
        li $v0, 1
        syscall
    label_3:
    label_1:
        li $v0, 10
        syscall
