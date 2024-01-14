.data
    reg_root: .space 256
    .globl main
    __prompt__: .asciiz "Enter an integer: "
    __lf__: .asciiz "\n"
.text

    foo:
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
        lw $t5, reg_root + 20
        lw $t5, 24($sp)
        lw $t6, reg_root + 24
        lw $t6, 28($sp)
        lw $t7, reg_root + 28
        lw $t7, 32($sp)
        lw $s0, reg_root + 32
        lw $s0, 36($sp)
        lw $s1, reg_root + 36
        lw $s1, 40($sp)
        lw $s2, reg_root + 40
        lw $s2, 44($sp)
        lw $s3, reg_root + 44
        lw $s3, 48($sp)
        lw $s4, reg_root + 48
        lw $s4, 52($sp)
        lw $s5, reg_root + 52
        lw $s5, 56($sp)
        lw $s6, reg_root + 56
        lw $s6, 60($sp)
        lw $s7, reg_root + 60
        lw $s7, 64($sp)
        lw $t8, reg_root + 64
        lw $t8, 68($sp)
        lw $t9, reg_root + 68
        lw $t9, 72($sp)
        sw $t0, reg_root
        lw $t0, reg_root + 72
        lw $t0, 76($sp)
        sw $t1, reg_root + 4
        lw $t1, reg_root + 76
        lw $t1, 80($sp)
        sw $t2, reg_root + 8
        lw $t2, reg_root + 80
        lw $t2, 84($sp)
        sw $t3, reg_root + 12
        lw $t3, reg_root + 84
        lw $t3, 88($sp)
        sw $t4, reg_root + 16
        lw $t4, reg_root + 88
        lw $t4, 92($sp)
        sw $t5, reg_root + 20
        lw $t5, reg_root + 92
        lw $t5, 96($sp)
        sw $t6, reg_root + 24
        lw $t6, reg_root + 96
        lw $t6, 100($sp)
        sw $t7, reg_root + 28
        lw $t7, reg_root + 100
        lw $t7, 104($sp)
        sw $s0, reg_root + 32
        lw $s0, reg_root + 104
        lw $s0, 108($sp)
        sw $s1, reg_root + 36
        lw $s1, reg_root + 108
        lw $s1, 112($sp)
        sw $s2, reg_root + 40
        lw $s2, reg_root + 112
        lw $s2, 116($sp)
        sw $s3, reg_root + 44
        lw $s3, reg_root + 116
        lw $s3, 120($sp)
        sw $s4, reg_root + 48
        lw $s4, reg_root + 120
        lw $s4, 124($sp)
        sw $s5, reg_root + 52
        lw $s5, reg_root + 124
        lw $s5, 128($sp)
        sw $s6, reg_root + 56
        lw $s6, reg_root + 128
        sw $s7, reg_root + 60
        lw $s7, reg_root
        sw $t8, reg_root + 64
        lw $t8, reg_root + 4
        mul $s6, $s7, $t8
        sw $t9, reg_root + 68
        lw $t9, reg_root + 132
        sw $t0, reg_root + 72
        lw $t0, reg_root + 8
        sw $t1, reg_root + 76
        lw $t1, reg_root + 12
        mul $t9, $t0, $t1
        sw $t2, reg_root + 80
        lw $t2, reg_root + 136
        add $t2, $s6, $t9
        sw $t3, reg_root + 84
        lw $t3, reg_root + 140
        sw $t4, reg_root + 88
        lw $t4, reg_root + 16
        sw $t5, reg_root + 92
        lw $t5, reg_root + 20
        mul $t3, $t4, $t5
        sw $t6, reg_root + 96
        lw $t6, reg_root + 144
        add $t6, $t2, $t3
        sw $t7, reg_root + 100
        lw $t7, reg_root + 148
        sw $s0, reg_root + 104
        lw $s0, reg_root + 24
        sw $s1, reg_root + 108
        lw $s1, reg_root + 28
        mul $t7, $s0, $s1
        sw $s2, reg_root + 112
        lw $s2, reg_root + 152
        add $s2, $t6, $t7
        sw $s3, reg_root + 116
        lw $s3, reg_root + 156
        sw $s4, reg_root + 120
        lw $s4, reg_root + 32
        sw $s5, reg_root + 124
        lw $s5, reg_root + 36
        mul $s3, $s4, $s5
        sw $s7, reg_root
        lw $s7, reg_root + 160
        add $s7, $s2, $s3
        sw $t8, reg_root + 4
        lw $t8, reg_root + 164
        sw $t0, reg_root + 8
        lw $t0, reg_root + 40
        sw $t1, reg_root + 12
        lw $t1, reg_root + 44
        mul $t8, $t0, $t1
        sw $s6, reg_root + 128
        lw $s6, reg_root + 168
        add $s6, $s7, $t8
        sw $t9, reg_root + 132
        lw $t9, reg_root + 172
        sw $t4, reg_root + 16
        lw $t4, reg_root + 48
        sw $t5, reg_root + 20
        lw $t5, reg_root + 52
        mul $t9, $t4, $t5
        sw $t2, reg_root + 136
        lw $t2, reg_root + 176
        add $t2, $s6, $t9
        sw $t3, reg_root + 140
        lw $t3, reg_root + 180
        sw $s0, reg_root + 24
        lw $s0, reg_root + 56
        sw $s1, reg_root + 28
        lw $s1, reg_root + 60
        mul $t3, $s0, $s1
        sw $t6, reg_root + 144
        lw $t6, reg_root + 184
        add $t6, $t2, $t3
        sw $t7, reg_root + 148
        lw $t7, reg_root + 188
        sw $s4, reg_root + 32
        lw $s4, reg_root + 64
        sw $s5, reg_root + 36
        lw $s5, reg_root + 68
        mul $t7, $s4, $s5
        sw $s2, reg_root + 152
        lw $s2, reg_root + 192
        add $s2, $t6, $t7
        sw $s3, reg_root + 156
        lw $s3, reg_root + 196
        sw $t0, reg_root + 40
        lw $t0, reg_root + 72
        sw $t1, reg_root + 44
        lw $t1, reg_root + 76
        mul $s3, $t0, $t1
        sw $s7, reg_root + 160
        lw $s7, reg_root + 200
        add $s7, $s2, $s3
        sw $t8, reg_root + 164
        lw $t8, reg_root + 204
        sw $t4, reg_root + 48
        lw $t4, reg_root + 80
        sw $t5, reg_root + 52
        lw $t5, reg_root + 84
        mul $t8, $t4, $t5
        sw $s6, reg_root + 168
        lw $s6, reg_root + 208
        add $s6, $s7, $t8
        sw $t9, reg_root + 172
        lw $t9, reg_root + 212
        sw $s0, reg_root + 56
        lw $s0, reg_root + 88
        sw $s1, reg_root + 60
        lw $s1, reg_root + 92
        mul $t9, $s0, $s1
        sw $t2, reg_root + 176
        lw $t2, reg_root + 216
        add $t2, $s6, $t9
        sw $t3, reg_root + 180
        lw $t3, reg_root + 220
        sw $s4, reg_root + 64
        lw $s4, reg_root + 96
        sw $s5, reg_root + 68
        lw $s5, reg_root + 100
        mul $t3, $s4, $s5
        sw $t6, reg_root + 184
        lw $t6, reg_root + 224
        add $t6, $t2, $t3
        sw $t7, reg_root + 188
        lw $t7, reg_root + 228
        sw $t0, reg_root + 72
        lw $t0, reg_root + 104
        sw $t1, reg_root + 76
        lw $t1, reg_root + 108
        mul $t7, $t0, $t1
        sw $s2, reg_root + 192
        lw $s2, reg_root + 232
        add $s2, $t6, $t7
        sw $s3, reg_root + 196
        lw $s3, reg_root + 236
        sw $t4, reg_root + 80
        lw $t4, reg_root + 112
        sw $t5, reg_root + 84
        lw $t5, reg_root + 116
        mul $s3, $t4, $t5
        sw $s7, reg_root + 200
        lw $s7, reg_root + 240
        add $s7, $s2, $s3
        sw $t8, reg_root + 204
        lw $t8, reg_root + 244
        sw $s0, reg_root + 88
        lw $s0, reg_root + 120
        sw $s1, reg_root + 92
        lw $s1, reg_root + 124
        mul $t8, $s0, $s1
        sw $s6, reg_root + 208
        lw $s6, reg_root + 248
        add $s6, $s7, $t8
        move $v0, $s6
        lw $ra, 0($sp)
        addi $sp, $sp, 132
        jr $ra
    main:
        sw $t0, reg_root + 104
        sw $t1, reg_root + 108
        sw $t2, reg_root + 216
        sw $t3, reg_root + 220
        sw $t4, reg_root + 112
        sw $t5, reg_root + 116
        sw $t6, reg_root + 224
        sw $t7, reg_root + 228
        sw $s0, reg_root + 120
        sw $s1, reg_root + 124
        sw $s2, reg_root + 232
        sw $s3, reg_root + 236
        sw $s4, reg_root + 96
        sw $s5, reg_root + 100
        sw $s6, reg_root + 248
        sw $s7, reg_root + 240
        sw $t8, reg_root + 244
        sw $t9, reg_root + 212
        lw $t0, reg_root + 252
        addi $sp, $sp, -4
        sw $t0, 0($sp)
        li $a0, 32
        addi $sp, $sp, -4
        sw $a0, 0($sp)
        li $a0, 31
        addi $sp, $sp, -4
        sw $a0, 0($sp)
        li $a0, 30
        addi $sp, $sp, -4
        sw $a0, 0($sp)
        li $a0, 29
        addi $sp, $sp, -4
        sw $a0, 0($sp)
        li $a0, 28
        addi $sp, $sp, -4
        sw $a0, 0($sp)
        li $a0, 27
        addi $sp, $sp, -4
        sw $a0, 0($sp)
        li $a0, 26
        addi $sp, $sp, -4
        sw $a0, 0($sp)
        li $a0, 25
        addi $sp, $sp, -4
        sw $a0, 0($sp)
        li $a0, 24
        addi $sp, $sp, -4
        sw $a0, 0($sp)
        li $a0, 23
        addi $sp, $sp, -4
        sw $a0, 0($sp)
        li $a0, 22
        addi $sp, $sp, -4
        sw $a0, 0($sp)
        li $a0, 21
        addi $sp, $sp, -4
        sw $a0, 0($sp)
        li $a0, 20
        addi $sp, $sp, -4
        sw $a0, 0($sp)
        li $a0, 19
        addi $sp, $sp, -4
        sw $a0, 0($sp)
        li $a0, 18
        addi $sp, $sp, -4
        sw $a0, 0($sp)
        li $a0, 17
        addi $sp, $sp, -4
        sw $a0, 0($sp)
        li $a0, 16
        addi $sp, $sp, -4
        sw $a0, 0($sp)
        li $a0, 15
        addi $sp, $sp, -4
        sw $a0, 0($sp)
        li $a0, 14
        addi $sp, $sp, -4
        sw $a0, 0($sp)
        li $a0, 13
        addi $sp, $sp, -4
        sw $a0, 0($sp)
        li $a0, 12
        addi $sp, $sp, -4
        sw $a0, 0($sp)
        li $a0, 11
        addi $sp, $sp, -4
        sw $a0, 0($sp)
        li $a0, 10
        addi $sp, $sp, -4
        sw $a0, 0($sp)
        li $a0, 9
        addi $sp, $sp, -4
        sw $a0, 0($sp)
        li $a0, 8
        addi $sp, $sp, -4
        sw $a0, 0($sp)
        li $a0, 7
        addi $sp, $sp, -4
        sw $a0, 0($sp)
        li $a0, 6
        addi $sp, $sp, -4
        sw $a0, 0($sp)
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
        sw $t0, reg_root + 252
        LABEL
        lw $t0, reg_root + 252
        move $a0, $t0
        li $v0, 1
        syscall
        la $a0, __lf__
        li $v0, 4
        syscall
        li $v0, 10
        syscall
