.data
    reg_root: .space 52
    .globl main
    __prompt__: .asciiz "Enter an integer: "
    __lf__: .asciiz "\n"
.text

    mod:
        addi $sp, $sp, -4
        sw $ra, 0($sp)
        lw $t0, reg_root
        lw $t0, 4($sp)
        lw $t1, reg_root + 4
        lw $t1, 8($sp)
        lw $t2, reg_root + 8
        div $t2, $t0, $t1
        lw $t3, reg_root + 12
        mul $t3, $t2, $t1
        lw $t4, reg_root + 16
        sub $t4, $t0, $t3
        move $v0, $t4
        lw $ra, 0($sp)
        addi $sp, $sp, 12
        jr $ra
    isPerfectNumber:
        sw $t0, reg_root
        sw $t1, reg_root + 4
        sw $t2, reg_root + 8
        sw $t3, reg_root + 12
        sw $t4, reg_root + 16
        addi $sp, $sp, -4
        sw $ra, 0($sp)
        lw $t0, reg_root + 20
        lw $t0, 4($sp)
        lw $t1, reg_root + 24
        li $t1, 0
        lw $t2, reg_root + 28
        li $t2, 1
        sw $t0, reg_root + 20
        sw $t1, reg_root + 24
        sw $t2, reg_root + 28
    label_0:
        lw $t0, reg_root + 32
        lw $t1, reg_root + 20
        div $t0, $t1, 2
        sw $t0, reg_root + 32
        sw $t1, reg_root + 20
        lw $t0, reg_root + 28
        lw $t1, reg_root + 32
        bgt $t0, $t1, label_1
        lw $t2, reg_root + 20
        addi $sp, $sp, -4
        sw $t2, 0($sp)
        lw $t3, reg_root + 24
        addi $sp, $sp, -4
        sw $t3, 0($sp)
        addi $sp, $sp, -4
        sw $t0, 0($sp)
        addi $sp, $sp, -4
        sw $t1, 0($sp)
        lw $t4, reg_root + 36
        addi $sp, $sp, -4
        sw $t4, 0($sp)
        move $a0, $t0
        addi $sp, $sp, -4
        sw $a0, 0($sp)
        move $a0, $t2
        addi $sp, $sp, -4
        sw $a0, 0($sp)
        jal mod
        lw $t4, 0($sp)
        addi $sp, $sp, 4
        lw $t1, 0($sp)
        addi $sp, $sp, 4
        lw $t0, 0($sp)
        addi $sp, $sp, 4
        lw $t3, 0($sp)
        addi $sp, $sp, 4
        lw $t2, 0($sp)
        addi $sp, $sp, 4
        move $t4, $v0
        sw $t0, reg_root + 28
        sw $t1, reg_root + 32
        sw $t2, reg_root + 20
        sw $t3, reg_root + 24
        sw $t4, reg_root + 36
        lw $t0, reg_root + 36
        li $a1, 0
        bne $t0, $a1, label_2
        lw $t1, reg_root + 24
        lw $t2, reg_root + 28
        add $t1, $t1, $t2
        sw $t0, reg_root + 36
        sw $t1, reg_root + 24
        sw $t2, reg_root + 28
    label_2:
        lw $t0, reg_root + 28
        addi $t0, $t0, 1
        sw $t0, reg_root + 28
        j label_0
    label_1:
        lw $t0, reg_root + 24
        lw $t1, reg_root + 20
        bne $t0, $t1, label_3
        li $v0, 1
        lw $ra, 0($sp)
        addi $sp, $sp, 8
        jr $ra
        sw $t0, reg_root + 24
        sw $t1, reg_root + 20
        j label_4
    label_3:
        li $v0, 0
        lw $ra, 0($sp)
        addi $sp, $sp, 8
        jr $ra
    label_4:
    main:
        lw $t0, reg_root + 40
        li $t0, 0
        lw $t1, reg_root + 44
        li $t1, 1
        sw $t0, reg_root + 40
        sw $t1, reg_root + 44
    label_5:
        lw $t0, reg_root + 44
        li $a1, 100
        bgt $t0, $a1, label_6
        lw $t1, reg_root + 40
        addi $sp, $sp, -4
        sw $t1, 0($sp)
        addi $sp, $sp, -4
        sw $t0, 0($sp)
        lw $t2, reg_root + 48
        addi $sp, $sp, -4
        sw $t2, 0($sp)
        move $a0, $t0
        addi $sp, $sp, -4
        sw $a0, 0($sp)
        jal isPerfectNumber
        lw $t2, 0($sp)
        addi $sp, $sp, 4
        lw $t0, 0($sp)
        addi $sp, $sp, 4
        lw $t1, 0($sp)
        addi $sp, $sp, 4
        move $t2, $v0
        sw $t0, reg_root + 44
        sw $t1, reg_root + 40
        sw $t2, reg_root + 48
        lw $t0, reg_root + 48
        li $a1, 1
        bne $t0, $a1, label_7
        lw $t1, reg_root + 44
        move $a0, $t1
        li $v0, 1
        syscall
        la $a0, __lf__
        li $v0, 4
        syscall
        sw $t0, reg_root + 48
        sw $t1, reg_root + 44
    label_7:
        lw $t0, reg_root + 44
        addi $t0, $t0, 1
        sw $t0, reg_root + 44
        j label_5
    label_6:
        li $v0, 10
        syscall
