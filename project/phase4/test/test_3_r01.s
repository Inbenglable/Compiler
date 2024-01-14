.data
    reg_root: .space 48
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
    isPalindrome:
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
        move $t2, $t0
        lw $t3, reg_root + 32
        li $t3, 0
        sw $t0, reg_root + 20
        sw $t1, reg_root + 24
        sw $t2, reg_root + 28
        sw $t3, reg_root + 32
    label_0:
        lw $t0, reg_root + 20
        li $a1, 0
        beq $t0, $a1, label_1
        addi $sp, $sp, -4
        sw $t0, 0($sp)
        lw $t1, reg_root + 24
        addi $sp, $sp, -4
        sw $t1, 0($sp)
        lw $t2, reg_root + 28
        addi $sp, $sp, -4
        sw $t2, 0($sp)
        lw $t3, reg_root + 32
        addi $sp, $sp, -4
        sw $t3, 0($sp)
        lw $t4, reg_root + 36
        addi $sp, $sp, -4
        sw $t4, 0($sp)
        li $a0, 10
        addi $sp, $sp, -4
        sw $a0, 0($sp)
        move $a0, $t0
        addi $sp, $sp, -4
        sw $a0, 0($sp)
        sw $t0, reg_root + 20
        sw $t1, reg_root + 24
        sw $t2, reg_root + 28
        sw $t3, reg_root + 32
        sw $t4, reg_root + 36
        LABEL
        lw $t0, reg_root + 36
        lw $t1, reg_root + 24
        mul $t0, $t1, 10
        lw $t2, reg_root + 32
        add $t1, $t0, $t2
        lw $t3, reg_root + 20
        div $t3, $t3, 10
        sw $t0, reg_root + 36
        sw $t1, reg_root + 24
        sw $t2, reg_root + 32
        sw $t3, reg_root + 20
        j label_0
    label_1:
        lw $t0, reg_root + 24
        lw $t1, reg_root + 28
        bne $t0, $t1, label_2
        li $v0, 1
        lw $ra, 0($sp)
        addi $sp, $sp, 8
        jr $ra
        sw $t0, reg_root + 24
        sw $t1, reg_root + 28
        j label_3
    label_2:
        li $v0, 0
        lw $ra, 0($sp)
        addi $sp, $sp, 8
        jr $ra
    label_3:
    main:
        la $a0, __prompt__
        li $v0, 4
        syscall
        lw $t0, reg_root + 40
        li $v0, 5
        syscall
        move $t0, $v0
        move $a0, $t0
        addi $sp, $sp, -4
        sw $a0, 0($sp)
        sw $t0, reg_root + 40
        LABEL
        lw $t0, reg_root + 44
        li $a1, 1
        bne $t0, $a1, label_4
        li $a0, 1
        li $v0, 1
        syscall
        la $a0, __lf__
        li $v0, 4
        syscall
        sw $t0, reg_root + 44
        j label_5
    label_4:
        li $a0, -1
        li $v0, 1
        syscall
        la $a0, __lf__
        li $v0, 4
        syscall
    label_5:
        li $v0, 10
        syscall
