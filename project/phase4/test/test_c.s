.data
    reg_root: .space 28
    .globl main
    __prompt__: .asciiz "Enter an integer: "
    __lf__: .asciiz "\n"
.text

    fast_pow:
        addi $sp, $sp, -4
        sw $ra, 0($sp)
        lw $t0, reg_root
        lw $t0, 4($sp)
        lw $t1, reg_root + 4
        lw $t1, 8($sp)
        lw $t2, reg_root + 8
        li $t2, 1
        sw $t0, reg_root
        sw $t1, reg_root + 4
        sw $t2, reg_root + 8
    label_0:
        lw $t0, reg_root + 4
        li $a1, 0
        ble $t0, $a1, label_1
        lw $t1, reg_root + 12
        div $t1, $t0, 2
        lw $t2, reg_root + 16
        mul $t2, $t1, 2
        lw $t3, reg_root + 20
        sub $t3, $t0, $t2
        sw $t0, reg_root + 4
        sw $t1, reg_root + 12
        sw $t2, reg_root + 16
        sw $t3, reg_root + 20
        lw $t0, reg_root + 20
        li $a1, 1
        bne $t0, $a1, label_2
        lw $t1, reg_root + 8
        lw $t2, reg_root
        mul $t1, $t1, $t2
        sw $t0, reg_root + 20
        sw $t1, reg_root + 8
        sw $t2, reg_root
    label_2:
        lw $t0, reg_root
        mul $t0, $t0, $t0
        lw $t1, reg_root + 4
        div $t1, $t1, 2
        sw $t0, reg_root
        sw $t1, reg_root + 4
        j label_0
    label_1:
        lw $t0, reg_root + 8
        move $v0, $t0
        lw $ra, 0($sp)
        addi $sp, $sp, 12
        jr $ra
    main:
        sw $t0, reg_root + 8
        lw $t0, reg_root + 24
        addi $sp, $sp, -4
        sw $t0, 0($sp)
        li $a0, 6
        addi $sp, $sp, -4
        sw $a0, 0($sp)
        li $a0, 3
        addi $sp, $sp, -4
        sw $a0, 0($sp)
        jal fast_pow
        lw $t0, 0($sp)
        addi $sp, $sp, 4
        move $t0, $v0
        move $a0, $t0
        li $v0, 1
        syscall
        la $a0, __lf__
        li $v0, 4
        syscall
        li $v0, 10
        syscall
