.data
    .globl main
    __prompt__: .asciiz "Enter an integer: "
.text

    hanoi:
        addi $sp, $sp, -4
        sw $ra, 0($sp)
        lw $t0, 4($sp)
        lw $t1, 8($sp)
        lw $t2, 12($sp)
        lw $t3, 16($sp)
        li $a1, 1
        bne $t0, $a1, label_0
        mul $t4, $t1, 1000000
        add $t5, $t4, $t3
        move $a0, $t5
        li $v0, 1
        syscall
        j label_1
    label_0:
        addi $t6, $t0, -1
        move $a0, $t2
        addi $sp, $sp, -4
        sw $a0, 0($sp)
        move $a0, $t3
        addi $sp, $sp, -4
        sw $a0, 0($sp)
        move $a0, $t1
        addi $sp, $sp, -4
        sw $a0, 0($sp)
        move $a0, $t6
        addi $sp, $sp, -4
        sw $a0, 0($sp)
        jal hanoi
        move $v1, $v0
        mul $t7, $t1, 1000000
        add $s0, $t7, $t3
        move $a0, $s0
        li $v0, 1
        syscall
        move $s1, $t1
        move $s2, $t3
        move $a0, $s2
        addi $sp, $sp, -4
        sw $a0, 0($sp)
        move $a0, $s1
        addi $sp, $sp, -4
        sw $a0, 0($sp)
        move $a0, $t2
        addi $sp, $sp, -4
        sw $a0, 0($sp)
        move $a0, $t6
        addi $sp, $sp, -4
        sw $a0, 0($sp)
        jal hanoi
        move $v1, $v0
    label_1:
        li $v0, 0
        lw $ra, 0($sp)
        addi $sp, $sp, 20
        jr $ra
    main:
        li $s3, 3
        li $a0, 3
        addi $sp, $sp, -4
        sw $a0, 0($sp)
        li $a0, 2
        addi $sp, $sp, -4
        sw $a0, 0($sp)
        li $a0, 1
        addi $sp, $sp, -4
        sw $a0, 0($sp)
        li $a0, 3
        addi $sp, $sp, -4
        sw $a0, 0($sp)
        jal hanoi
        move $v1, $v0
        li $v0, 10
        syscall
