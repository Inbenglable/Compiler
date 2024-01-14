.data
    reg_root: .space 0
    .globl main
    __prompt__: .asciiz "Enter an integer: "
    __lf__: .asciiz "\n"
.text

    hanoi:
        addi $sp, $sp, -4
        sw $ra, 0($sp)
        lw $v1, 4($sp)
        lw $v1, 8($sp)
        lw $v1, 12($sp)
        lw $v1, 16($sp)
        move $v1, $v1
        li $v1, 1
        beq $v1, $v1, label0
        j label1
    label0:
        move $v1, $v1
        li $v1, 10000
        mul $v1, $v1, $v1
        move $v1, $v1
        add $v1, $v1, $v1
        move $a0, $v1
        li $v0, 1
        syscall
        la $a0, __lf__
        li $v0, 4
        syscall
        j label2
    label1:
        move $v1, $v1
        li $v1, 1
        sub $v1, $v1, $v1
        move $v1, $v1
        move $v1, $v1
        move $v1, $v1
        move $a0, $v1
        addi $sp, $sp, -4
        sw $a0, 0($sp)
        move $a0, $v1
        addi $sp, $sp, -4
        sw $a0, 0($sp)
        move $a0, $v1
        addi $sp, $sp, -4
        sw $a0, 0($sp)
        move $a0, $v1
        addi $sp, $sp, -4
        sw $a0, 0($sp)
        jal hanoi
        move $v1, $v0
        move $v1, $v1
        li $v1, 10000
        mul $v1, $v1, $v1
        move $v1, $v1
        add $v1, $v1, $v1
        move $a0, $v1
        li $v0, 1
        syscall
        la $a0, __lf__
        li $v0, 4
        syscall
        move $v1, $v1
        li $v1, 1
        sub $v1, $v1, $v1
        move $v1, $v1
        move $v1, $v1
        move $v1, $v1
        move $a0, $v1
        addi $sp, $sp, -4
        sw $a0, 0($sp)
        move $a0, $v1
        addi $sp, $sp, -4
        sw $a0, 0($sp)
        move $a0, $v1
        addi $sp, $sp, -4
        sw $a0, 0($sp)
        move $a0, $v1
        addi $sp, $sp, -4
        sw $a0, 0($sp)
        jal hanoi
        move $v1, $v0
    label2:
        li $v1, 0
        move $v0, $v1
        lw $ra, 0($sp)
        addi $sp, $sp, 20
        jr $ra
    main:
        li $v1, 3
        move $v1, $v1
        move $v1, $v1
        li $v1, 1
        li $v1, 2
        li $v1, 3
        move $a0, $v1
        addi $sp, $sp, -4
        sw $a0, 0($sp)
        move $a0, $v1
        addi $sp, $sp, -4
        sw $a0, 0($sp)
        move $a0, $v1
        addi $sp, $sp, -4
        sw $a0, 0($sp)
        move $a0, $v1
        addi $sp, $sp, -4
        sw $a0, 0($sp)
        jal hanoi
        move $v1, $v0
        li $v1, 0
        li $v0, 10
        syscall
