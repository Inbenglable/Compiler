.data
    reg_root: .space 156
    .globl main
    __prompt__: .asciiz "Enter an integer: "
    __lf__: .asciiz "\n"
.text

    hanoi:
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
        move $t4, $t0
        lw $t5, reg_root + 20
        li $t5, 1
        sw $t0, reg_root
        sw $t1, reg_root + 4
        sw $t2, reg_root + 8
        sw $t3, reg_root + 12
        sw $t4, reg_root + 16
        sw $t5, reg_root + 20
        lw $t0, reg_root + 16
        lw $t1, reg_root + 20
        beq $t0, $t1, label0
        sw $t0, reg_root + 16
        sw $t1, reg_root + 20
        j label1
    label0:
        lw $t0, reg_root + 24
        lw $t1, reg_root + 4
        move $t0, $t1
        lw $t2, reg_root + 28
        li $t2, 10000
        lw $t3, reg_root + 32
        mul $t3, $t0, $t2
        lw $t4, reg_root + 36
        lw $t5, reg_root + 12
        move $t4, $t5
        lw $t6, reg_root + 40
        add $t6, $t3, $t4
        move $a0, $t6
        li $v0, 1
        syscall
        la $a0, __lf__
        li $v0, 4
        syscall
        sw $t0, reg_root + 24
        sw $t1, reg_root + 4
        sw $t2, reg_root + 28
        sw $t3, reg_root + 32
        sw $t4, reg_root + 36
        sw $t5, reg_root + 12
        sw $t6, reg_root + 40
        j label2
    label1:
        lw $t0, reg_root + 44
        lw $t1, reg_root
        move $t0, $t1
        lw $t2, reg_root + 48
        li $t2, 1
        lw $t3, reg_root + 52
        sub $t3, $t0, $t2
        lw $t4, reg_root + 56
        lw $t5, reg_root + 4
        move $t4, $t5
        lw $t6, reg_root + 60
        lw $t7, reg_root + 12
        move $t6, $t7
        lw $s0, reg_root + 64
        lw $s1, reg_root + 8
        move $s0, $s1
        addi $sp, $sp, -4
        sw $t1, 0($sp)
        addi $sp, $sp, -4
        sw $t5, 0($sp)
        addi $sp, $sp, -4
        sw $s1, 0($sp)
        addi $sp, $sp, -4
        sw $t7, 0($sp)
        lw $s2, reg_root + 16
        addi $sp, $sp, -4
        sw $s2, 0($sp)
        lw $s3, reg_root + 20
        addi $sp, $sp, -4
        sw $s3, 0($sp)
        lw $s4, reg_root + 24
        addi $sp, $sp, -4
        sw $s4, 0($sp)
        lw $s5, reg_root + 28
        addi $sp, $sp, -4
        sw $s5, 0($sp)
        lw $s6, reg_root + 32
        addi $sp, $sp, -4
        sw $s6, 0($sp)
        lw $s7, reg_root + 36
        addi $sp, $sp, -4
        sw $s7, 0($sp)
        lw $t8, reg_root + 40
        addi $sp, $sp, -4
        sw $t8, 0($sp)
        addi $sp, $sp, -4
        sw $t0, 0($sp)
        addi $sp, $sp, -4
        sw $t2, 0($sp)
        addi $sp, $sp, -4
        sw $t3, 0($sp)
        addi $sp, $sp, -4
        sw $t4, 0($sp)
        addi $sp, $sp, -4
        sw $t6, 0($sp)
        addi $sp, $sp, -4
        sw $s0, 0($sp)
        lw $t9, reg_root + 68
        addi $sp, $sp, -4
        sw $t9, 0($sp)
        sw $t1, reg_root
        lw $t1, reg_root + 72
        addi $sp, $sp, -4
        sw $t1, 0($sp)
        sw $t5, reg_root + 4
        lw $t5, reg_root + 76
        addi $sp, $sp, -4
        sw $t5, 0($sp)
        sw $s1, reg_root + 8
        lw $s1, reg_root + 80
        addi $sp, $sp, -4
        sw $s1, 0($sp)
        sw $t7, reg_root + 12
        lw $t7, reg_root + 84
        addi $sp, $sp, -4
        sw $t7, 0($sp)
        sw $s2, reg_root + 16
        lw $s2, reg_root + 88
        addi $sp, $sp, -4
        sw $s2, 0($sp)
        sw $s3, reg_root + 20
        lw $s3, reg_root + 92
        addi $sp, $sp, -4
        sw $s3, 0($sp)
        sw $s4, reg_root + 24
        lw $s4, reg_root + 96
        addi $sp, $sp, -4
        sw $s4, 0($sp)
        sw $s5, reg_root + 28
        lw $s5, reg_root + 100
        addi $sp, $sp, -4
        sw $s5, 0($sp)
        sw $s6, reg_root + 32
        lw $s6, reg_root + 104
        addi $sp, $sp, -4
        sw $s6, 0($sp)
        sw $s7, reg_root + 36
        lw $s7, reg_root + 108
        addi $sp, $sp, -4
        sw $s7, 0($sp)
        sw $t8, reg_root + 40
        lw $t8, reg_root + 112
        addi $sp, $sp, -4
        sw $t8, 0($sp)
        sw $t0, reg_root + 44
        lw $t0, reg_root + 116
        addi $sp, $sp, -4
        sw $t0, 0($sp)
        sw $t2, reg_root + 48
        lw $t2, reg_root + 120
        addi $sp, $sp, -4
        sw $t2, 0($sp)
        move $a0, $s0
        addi $sp, $sp, -4
        sw $a0, 0($sp)
        move $a0, $t6
        addi $sp, $sp, -4
        sw $a0, 0($sp)
        move $a0, $t4
        addi $sp, $sp, -4
        sw $a0, 0($sp)
        move $a0, $t3
        addi $sp, $sp, -4
        sw $a0, 0($sp)
        jal hanoi
        lw $t2, 0($sp)
        addi $sp, $sp, 4
        lw $t0, 0($sp)
        addi $sp, $sp, 4
        lw $t8, 0($sp)
        addi $sp, $sp, 4
        lw $s7, 0($sp)
        addi $sp, $sp, 4
        lw $s6, 0($sp)
        addi $sp, $sp, 4
        lw $s5, 0($sp)
        addi $sp, $sp, 4
        lw $s4, 0($sp)
        addi $sp, $sp, 4
        lw $s3, 0($sp)
        addi $sp, $sp, 4
        lw $s2, 0($sp)
        addi $sp, $sp, 4
        lw $t7, 0($sp)
        addi $sp, $sp, 4
        lw $s1, 0($sp)
        addi $sp, $sp, 4
        lw $t5, 0($sp)
        addi $sp, $sp, 4
        lw $t1, 0($sp)
        addi $sp, $sp, 4
        lw $t9, 0($sp)
        addi $sp, $sp, 4
        lw $s0, 0($sp)
        addi $sp, $sp, 4
        lw $t6, 0($sp)
        addi $sp, $sp, 4
        lw $t4, 0($sp)
        addi $sp, $sp, 4
        lw $t3, 0($sp)
        addi $sp, $sp, 4
        sw $t2, reg_root + 120
        lw $t2, reg_root + 48
        lw $t2, 0($sp)
        addi $sp, $sp, 4
        sw $t0, reg_root + 116
        lw $t0, reg_root + 44
        lw $t0, 0($sp)
        addi $sp, $sp, 4
        sw $t8, reg_root + 112
        lw $t8, reg_root + 40
        lw $t8, 0($sp)
        addi $sp, $sp, 4
        sw $s7, reg_root + 108
        lw $s7, reg_root + 36
        lw $s7, 0($sp)
        addi $sp, $sp, 4
        sw $s6, reg_root + 104
        lw $s6, reg_root + 32
        lw $s6, 0($sp)
        addi $sp, $sp, 4
        sw $s5, reg_root + 100
        lw $s5, reg_root + 28
        lw $s5, 0($sp)
        addi $sp, $sp, 4
        sw $s4, reg_root + 96
        lw $s4, reg_root + 24
        lw $s4, 0($sp)
        addi $sp, $sp, 4
        sw $s3, reg_root + 92
        lw $s3, reg_root + 20
        lw $s3, 0($sp)
        addi $sp, $sp, 4
        sw $s2, reg_root + 88
        lw $s2, reg_root + 16
        lw $s2, 0($sp)
        addi $sp, $sp, 4
        sw $t7, reg_root + 84
        lw $t7, reg_root + 12
        lw $t7, 0($sp)
        addi $sp, $sp, 4
        sw $s1, reg_root + 80
        lw $s1, reg_root + 8
        lw $s1, 0($sp)
        addi $sp, $sp, 4
        sw $t5, reg_root + 76
        lw $t5, reg_root + 4
        lw $t5, 0($sp)
        addi $sp, $sp, 4
        sw $t1, reg_root + 72
        lw $t1, reg_root
        lw $t1, 0($sp)
        addi $sp, $sp, 4
        move $t9, $v0
        sw $s0, reg_root + 64
        lw $s0, reg_root + 72
        move $s0, $t5
        sw $t6, reg_root + 60
        lw $t6, reg_root + 76
        li $t6, 10000
        sw $t4, reg_root + 56
        lw $t4, reg_root + 80
        mul $t4, $s0, $t6
        sw $t3, reg_root + 52
        lw $t3, reg_root + 84
        move $t3, $t7
        sw $t2, reg_root + 48
        lw $t2, reg_root + 88
        add $t2, $t4, $t3
        move $a0, $t2
        li $v0, 1
        syscall
        la $a0, __lf__
        li $v0, 4
        syscall
        sw $t0, reg_root + 44
        lw $t0, reg_root + 92
        move $t0, $t1
        sw $t8, reg_root + 40
        lw $t8, reg_root + 96
        li $t8, 1
        sw $s7, reg_root + 36
        lw $s7, reg_root + 100
        sub $s7, $t0, $t8
        sw $s6, reg_root + 32
        lw $s6, reg_root + 104
        move $s6, $s1
        sw $s5, reg_root + 28
        lw $s5, reg_root + 108
        move $s5, $t5
        sw $s4, reg_root + 24
        lw $s4, reg_root + 112
        move $s4, $t7
        addi $sp, $sp, -4
        sw $t1, 0($sp)
        addi $sp, $sp, -4
        sw $t5, 0($sp)
        addi $sp, $sp, -4
        sw $s1, 0($sp)
        addi $sp, $sp, -4
        sw $t7, 0($sp)
        addi $sp, $sp, -4
        sw $s2, 0($sp)
        addi $sp, $sp, -4
        sw $s3, 0($sp)
        sw $t9, reg_root + 68
        lw $t9, reg_root + 24
        addi $sp, $sp, -4
        sw $t9, 0($sp)
        sw $s0, reg_root + 72
        lw $s0, reg_root + 28
        addi $sp, $sp, -4
        sw $s0, 0($sp)
        sw $t6, reg_root + 76
        lw $t6, reg_root + 32
        addi $sp, $sp, -4
        sw $t6, 0($sp)
        sw $t4, reg_root + 80
        lw $t4, reg_root + 36
        addi $sp, $sp, -4
        sw $t4, 0($sp)
        sw $t3, reg_root + 84
        lw $t3, reg_root + 40
        addi $sp, $sp, -4
        sw $t3, 0($sp)
        sw $t2, reg_root + 88
        lw $t2, reg_root + 44
        addi $sp, $sp, -4
        sw $t2, 0($sp)
        sw $s7, reg_root + 100
        lw $s7, reg_root + 48
        addi $sp, $sp, -4
        sw $s7, 0($sp)
        sw $t0, reg_root + 92
        lw $t0, reg_root + 52
        addi $sp, $sp, -4
        sw $t0, 0($sp)
        sw $t8, reg_root + 96
        lw $t8, reg_root + 56
        addi $sp, $sp, -4
        sw $t8, 0($sp)
        sw $s6, reg_root + 104
        lw $s6, reg_root + 60
        addi $sp, $sp, -4
        sw $s6, 0($sp)
        sw $s5, reg_root + 108
        lw $s5, reg_root + 64
        addi $sp, $sp, -4
        sw $s5, 0($sp)
        sw $s4, reg_root + 112
        lw $s4, reg_root + 68
        addi $sp, $sp, -4
        sw $s4, 0($sp)
        sw $t1, reg_root
        lw $t1, reg_root + 72
        addi $sp, $sp, -4
        sw $t1, 0($sp)
        sw $t5, reg_root + 4
        lw $t5, reg_root + 76
        addi $sp, $sp, -4
        sw $t5, 0($sp)
        sw $s1, reg_root + 8
        lw $s1, reg_root + 80
        addi $sp, $sp, -4
        sw $s1, 0($sp)
        sw $t7, reg_root + 12
        lw $t7, reg_root + 84
        addi $sp, $sp, -4
        sw $t7, 0($sp)
        sw $s2, reg_root + 16
        lw $s2, reg_root + 88
        addi $sp, $sp, -4
        sw $s2, 0($sp)
        sw $s3, reg_root + 20
        lw $s3, reg_root + 92
        addi $sp, $sp, -4
        sw $s3, 0($sp)
        sw $t9, reg_root + 24
        lw $t9, reg_root + 96
        addi $sp, $sp, -4
        sw $t9, 0($sp)
        sw $s0, reg_root + 28
        lw $s0, reg_root + 100
        addi $sp, $sp, -4
        sw $s0, 0($sp)
        sw $t6, reg_root + 32
        lw $t6, reg_root + 104
        addi $sp, $sp, -4
        sw $t6, 0($sp)
        sw $t4, reg_root + 36
        lw $t4, reg_root + 108
        addi $sp, $sp, -4
        sw $t4, 0($sp)
        sw $t3, reg_root + 40
        lw $t3, reg_root + 112
        addi $sp, $sp, -4
        sw $t3, 0($sp)
        sw $t2, reg_root + 44
        lw $t2, reg_root + 116
        addi $sp, $sp, -4
        sw $t2, 0($sp)
        sw $s7, reg_root + 48
        lw $s7, reg_root + 120
        addi $sp, $sp, -4
        sw $s7, 0($sp)
        move $a0, $t3
        addi $sp, $sp, -4
        sw $a0, 0($sp)
        move $a0, $t4
        addi $sp, $sp, -4
        sw $a0, 0($sp)
        move $a0, $t6
        addi $sp, $sp, -4
        sw $a0, 0($sp)
        move $a0, $s0
        addi $sp, $sp, -4
        sw $a0, 0($sp)
        jal hanoi
        lw $s7, 0($sp)
        addi $sp, $sp, 4
        lw $t2, 0($sp)
        addi $sp, $sp, 4
        lw $t3, 0($sp)
        addi $sp, $sp, 4
        lw $t4, 0($sp)
        addi $sp, $sp, 4
        lw $t6, 0($sp)
        addi $sp, $sp, 4
        lw $s0, 0($sp)
        addi $sp, $sp, 4
        lw $t9, 0($sp)
        addi $sp, $sp, 4
        lw $s3, 0($sp)
        addi $sp, $sp, 4
        lw $s2, 0($sp)
        addi $sp, $sp, 4
        lw $t7, 0($sp)
        addi $sp, $sp, 4
        lw $s1, 0($sp)
        addi $sp, $sp, 4
        lw $t5, 0($sp)
        addi $sp, $sp, 4
        lw $t1, 0($sp)
        addi $sp, $sp, 4
        lw $s4, 0($sp)
        addi $sp, $sp, 4
        lw $s5, 0($sp)
        addi $sp, $sp, 4
        lw $s6, 0($sp)
        addi $sp, $sp, 4
        lw $t8, 0($sp)
        addi $sp, $sp, 4
        lw $t0, 0($sp)
        addi $sp, $sp, 4
        sw $s7, reg_root + 120
        lw $s7, reg_root + 48
        lw $s7, 0($sp)
        addi $sp, $sp, 4
        sw $t2, reg_root + 116
        lw $t2, reg_root + 44
        lw $t2, 0($sp)
        addi $sp, $sp, 4
        sw $t3, reg_root + 112
        lw $t3, reg_root + 40
        lw $t3, 0($sp)
        addi $sp, $sp, 4
        sw $t4, reg_root + 108
        lw $t4, reg_root + 36
        lw $t4, 0($sp)
        addi $sp, $sp, 4
        sw $t6, reg_root + 104
        lw $t6, reg_root + 32
        lw $t6, 0($sp)
        addi $sp, $sp, 4
        sw $s0, reg_root + 100
        lw $s0, reg_root + 28
        lw $s0, 0($sp)
        addi $sp, $sp, 4
        sw $t9, reg_root + 96
        lw $t9, reg_root + 24
        lw $t9, 0($sp)
        addi $sp, $sp, 4
        sw $s3, reg_root + 92
        lw $s3, reg_root + 20
        lw $s3, 0($sp)
        addi $sp, $sp, 4
        sw $s2, reg_root + 88
        lw $s2, reg_root + 16
        lw $s2, 0($sp)
        addi $sp, $sp, 4
        sw $t7, reg_root + 84
        lw $t7, reg_root + 12
        lw $t7, 0($sp)
        addi $sp, $sp, 4
        sw $s1, reg_root + 80
        lw $s1, reg_root + 8
        lw $s1, 0($sp)
        addi $sp, $sp, 4
        sw $t5, reg_root + 76
        lw $t5, reg_root + 4
        lw $t5, 0($sp)
        addi $sp, $sp, 4
        sw $t1, reg_root + 72
        lw $t1, reg_root
        lw $t1, 0($sp)
        addi $sp, $sp, 4
        sw $s4, reg_root + 68
        lw $s4, reg_root + 116
        move $s4, $v0
        sw $t0, reg_root + 52
        sw $t1, reg_root
        sw $t2, reg_root + 44
        sw $t3, reg_root + 40
        sw $t4, reg_root + 36
        sw $t5, reg_root + 4
        sw $t6, reg_root + 32
        sw $t7, reg_root + 12
        sw $s0, reg_root + 28
        sw $s1, reg_root + 8
        sw $s2, reg_root + 16
        sw $s3, reg_root + 20
        sw $s4, reg_root + 116
        sw $s5, reg_root + 64
        sw $s6, reg_root + 60
        sw $s7, reg_root + 48
        sw $t8, reg_root + 56
        sw $t9, reg_root + 24
    label2:
        lw $t0, reg_root + 120
        li $t0, 0
        move $v0, $t0
        lw $ra, 0($sp)
        addi $sp, $sp, 20
        jr $ra
    main:
        sw $t0, reg_root + 120
        lw $t0, reg_root + 124
        li $t0, 3
        lw $t1, reg_root + 128
        move $t1, $t0
        lw $t2, reg_root + 132
        move $t2, $t1
        lw $t3, reg_root + 136
        li $t3, 1
        lw $t4, reg_root + 140
        li $t4, 2
        lw $t5, reg_root + 144
        li $t5, 3
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
        addi $sp, $sp, -4
        sw $t5, 0($sp)
        lw $t6, reg_root + 148
        addi $sp, $sp, -4
        sw $t6, 0($sp)
        lw $t7, reg_root + 152
        addi $sp, $sp, -4
        sw $t7, 0($sp)
        move $a0, $t5
        addi $sp, $sp, -4
        sw $a0, 0($sp)
        move $a0, $t4
        addi $sp, $sp, -4
        sw $a0, 0($sp)
        move $a0, $t3
        addi $sp, $sp, -4
        sw $a0, 0($sp)
        move $a0, $t2
        addi $sp, $sp, -4
        sw $a0, 0($sp)
        jal hanoi
        lw $t7, 0($sp)
        addi $sp, $sp, 4
        lw $t6, 0($sp)
        addi $sp, $sp, 4
        lw $t5, 0($sp)
        addi $sp, $sp, 4
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
        move $t6, $v0
        li $t7, 0
        li $v0, 10
        syscall
