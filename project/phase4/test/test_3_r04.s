.data
    reg_root: .space 52
    .globl main
    __prompt__: .asciiz "Enter an integer: "
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
    label_0:
        lw $t3, reg_root + 32
        div $t3, $t0, 2
        bgt $t2, $t3, label_1
        sw $t0, reg_root + 20
        sw $t1, reg_root + 24
        sw $t2, reg_root + 28
        sw $t3, reg_root + 32
        lw $t0, reg_root + 28
        move $a0, $t0
        addi $sp, $sp, -4
        sw $a0, 0($sp)
        lw $t1, reg_root + 20
        move $a0, $t1
        addi $sp, $sp, -4
        sw $a0, 0($sp)
        jal mod
        lw $t2, reg_root + 36
        move $t2, $v0
        li $a1, 0
        bne $t2, $a1, label_2
        sw $t0, reg_root + 28
        sw $t1, reg_root + 20
        sw $t2, reg_root + 36
        lw $t0, reg_root + 24
        lw $t1, reg_root + 28
        add $t0, $t0, $t1
    label_2:
        sw $t0, reg_root + 24
        sw $t1, reg_root + 28
        lw $t0, reg_root + 28
        addi $t0, $t0, 1
        j label_0
    label_1:
        sw $t0, reg_root + 28
        lw $t0, reg_root + 24
        lw $t1, reg_root + 20
        bne $t0, $t1, label_3
        sw $t0, reg_root + 24
        sw $t1, reg_root + 20
        li $v0, 1
        lw $ra, 0($sp)
        addi $sp, $sp, 8
        jr $ra
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
    label_5:
        li $a1, 100
        bgt $t1, $a1, label_6
        sw $t0, reg_root + 40
        sw $t1, reg_root + 44
        lw $t0, reg_root + 44
        move $a0, $t0
        addi $sp, $sp, -4
        sw $a0, 0($sp)
        jal isPerfectNumber
        lw $t1, reg_root + 48
        move $t1, $v0
        li $a1, 1
        bne $t1, $a1, label_7
        sw $t0, reg_root + 44
        sw $t1, reg_root + 48
        lw $t0, reg_root + 44
        move $a0, $t0
        li $v0, 1
        syscall
    label_7:
        sw $t0, reg_root + 44
        lw $t0, reg_root + 44
        addi $t0, $t0, 1
        j label_5
    label_6:
        sw $t0, reg_root + 44
        li $v0, 10
        syscall
