.data
    reg_root: .space 40
    .globl main
    __prompt__: .asciiz "Enter an integer: "
.text

    pprriit:
        addi $sp, $sp, -4
        sw $ra, 0($sp)
        lw $t0, reg_root
        lw $t0, 4($sp)
        lw $t1, reg_root + 4
        lw $t1, 8($sp)
        lw $t2, reg_root + 8
        lw $t2, 12($sp)
        lw $t3, reg_root + 12
        lw $t3, 16($sp)
        lw $t4, reg_root + 16
        lw $t4, 20($sp)
        move $a0, $t0
        li $v0, 1
        syscall
        move $a0, $t1
        li $v0, 1
        syscall
        move $a0, $t2
        li $v0, 1
        syscall
        move $a0, $t3
        li $v0, 1
        syscall
        move $a0, $t4
        li $v0, 1
        syscall
        li $v0, 0
        lw $ra, 0($sp)
        addi $sp, $sp, 24
        jr $ra
    main:
        sw $t0, reg_root
        sw $t1, reg_root + 4
        sw $t2, reg_root + 8
        sw $t3, reg_root + 12
        sw $t4, reg_root + 16
        lw $t0, reg_root + 20
        li $t0, 1
        lw $t1, reg_root + 24
        li $t1, 2
        lw $t2, reg_root + 28
        li $t2, 3
        lw $t3, reg_root + 32
        li $t3, 4
        lw $t4, reg_root + 36
        li $t4, 5
        addi $sp, $sp, -4
        sw $t0, 0($sp)
        addi $sp, $sp, -4
        sw $t1, 0($sp)
        addi $sp, $sp, -4
        sw $t2, 0($sp)
        addi $sp, $sp, -4
        sw $t3, 0($sp)
        addi $sp, $sp, -4
        sw $t4, 0($sp)
        li $a0, 5
        addi $sp, $sp, -4
        sw $a0, 0($sp)
        li $a0, 4
        addi $sp, $sp, -4
        sw $a0, 0($sp)
        li $a0, 3
        addi $sp, $sp, -4
        sw $a0, 0($sp)
        li $a0, 2
        addi $sp, $sp, -4
        sw $a0, 0($sp)
        li $a0, 1
        addi $sp, $sp, -4
        sw $a0, 0($sp)
        jal pprriit
        lw $t4, 0($sp)
        addi $sp, $sp, 4
        lw $t3, 0($sp)
        addi $sp, $sp, 4
        lw $t2, 0($sp)
        addi $sp, $sp, 4
        lw $t1, 0($sp)
        addi $sp, $sp, 4
        lw $t0, 0($sp)
        addi $sp, $sp, 4
        move $v1, $v0
        li $v0, 10
        syscall
