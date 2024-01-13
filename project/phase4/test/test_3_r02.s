.data
    reg_root: .space 24
    .globl main
    __prompt__: .asciiz "Enter an integer: "
    __lf__: .asciiz "\n"
.text

    fact:
        addi $sp, $sp, -4
        sw $ra, 0($sp)
        lw $t0, reg_root
        lw $t0, 4($sp)
        sw $t0, reg_root
        lw $t0, reg_root
        li $a1, 1
        bne $t0, $a1, label_0
        move $v0, $t0
        lw $ra, 0($sp)
        addi $sp, $sp, 8
        jr $ra
        sw $t0, reg_root
        j label_1
    label_0:
        lw $t0, reg_root + 4
        lw $t1, reg_root
        addi $t0, $t1, -1
        addi $sp, $sp, -4
        sw $t1, 0($sp)
        addi $sp, $sp, -4
        sw $t0, 0($sp)
        lw $t2, reg_root + 8
        addi $sp, $sp, -4
        sw $t2, 0($sp)
        lw $t3, reg_root + 12
        addi $sp, $sp, -4
        sw $t3, 0($sp)
        move $a0, $t0
        addi $sp, $sp, -4
        sw $a0, 0($sp)
        jal fact
        lw $t3, 0($sp)
        addi $sp, $sp, 4
        lw $t2, 0($sp)
        addi $sp, $sp, 4
        lw $t0, 0($sp)
        addi $sp, $sp, 4
        lw $t1, 0($sp)
        addi $sp, $sp, 4
        move $t2, $v0
        mul $t3, $t1, $t2
        move $v0, $t3
        lw $ra, 0($sp)
        addi $sp, $sp, 8
        jr $ra
        sw $t0, reg_root + 4
        sw $t1, reg_root
        sw $t2, reg_root + 8
        sw $t3, reg_root + 12
    label_1:
    main:
        la $a0, __prompt__
        li $v0, 4
        syscall
        lw $t0, reg_root + 16
        li $v0, 5
        syscall
        move $t0, $v0
        sw $t0, reg_root + 16
        lw $t0, reg_root + 16
        li $a1, 1
        ble $t0, $a1, label_2
        addi $sp, $sp, -4
        sw $t0, 0($sp)
        lw $t1, reg_root + 20
        addi $sp, $sp, -4
        sw $t1, 0($sp)
        move $a0, $t0
        addi $sp, $sp, -4
        sw $a0, 0($sp)
        jal fact
        lw $t1, 0($sp)
        addi $sp, $sp, 4
        lw $t0, 0($sp)
        addi $sp, $sp, 4
        move $t1, $v0
        sw $t0, reg_root + 16
        sw $t1, reg_root + 20
        j label_3
    label_2:
        lw $t0, reg_root + 20
        li $t0, 1
        sw $t0, reg_root + 20
    label_3:
        lw $t0, reg_root + 20
        move $a0, $t0
        li $v0, 1
        syscall
        la $a0, __lf__
        li $v0, 4
        syscall
        li $v0, 10
        syscall
