.data
    reg_root: .space 24
    .globl main
    __prompt__: .asciiz "Enter an integer: "
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
        j label_1
    label_0:
        sw $t0, reg_root
        lw $t0, reg_root + 4
        lw $t1, reg_root
        addi $t0, $t1, -1
        addi $sp, $sp, -4
        sw $t0, 0($sp)
        addi $sp, $sp, -4
        sw $t1, 0($sp)
        move $a0, $t0
        addi $sp, $sp, -4
        sw $a0, 0($sp)
        jal fact
        lw $t0, 0($sp)
        addi $sp, $sp, 4
        lw $t1, 0($sp)
        addi $sp, $sp, 4
        lw $t2, reg_root + 8
        move $t2, $v0
        lw $t3, reg_root + 12
        mul $t3, $t1, $t2
        move $v0, $t3
        lw $ra, 0($sp)
        addi $sp, $sp, 8
        jr $ra
    label_1:
    main:
        sw $t0, reg_root + 4
        sw $t1, reg_root
        sw $t2, reg_root + 8
        sw $t3, reg_root + 12
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
        move $a0, $t0
        addi $sp, $sp, -4
        sw $a0, 0($sp)
        jal fact
        lw $t0, 0($sp)
        addi $sp, $sp, 4
        lw $t1, reg_root + 20
        move $t1, $v0
        j label_3
    label_2:
        sw $t0, reg_root + 16
        sw $t1, reg_root + 20
        lw $t0, reg_root + 20
        li $t0, 1
    label_3:
        move $a0, $t0
        li $v0, 1
        syscall
        li $v0, 10
        syscall
