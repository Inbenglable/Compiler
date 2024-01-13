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
        sw $t0, reg_root + 72
        lw $t0, reg_root + 76
        lw $t0, 80($sp)
        sw $t0, reg_root + 76
        lw $t0, reg_root + 80
        lw $t0, 84($sp)
        sw $t0, reg_root + 80
        lw $t0, reg_root + 84
        lw $t0, 88($sp)
        sw $t0, reg_root + 84
        lw $t0, reg_root + 88
        lw $t0, 92($sp)
        sw $t0, reg_root + 88
        lw $t0, reg_root + 92
        lw $t0, 96($sp)
        sw $t0, reg_root + 92
        lw $t0, reg_root + 96
        lw $t0, 100($sp)
        sw $t0, reg_root + 96
        lw $t0, reg_root + 100
        lw $t0, 104($sp)
        sw $t0, reg_root + 100
        lw $t0, reg_root + 104
        lw $t0, 108($sp)
        sw $t0, reg_root + 104
        lw $t0, reg_root + 108
        lw $t0, 112($sp)
        sw $t0, reg_root + 108
        lw $t0, reg_root + 112
        lw $t0, 116($sp)
        sw $t0, reg_root + 112
        lw $t0, reg_root + 116
        lw $t0, 120($sp)
        sw $t0, reg_root + 116
        lw $t0, reg_root + 120
        lw $t0, 124($sp)
        sw $t0, reg_root + 120
        lw $t0, reg_root + 124
        lw $t0, 128($sp)
        sw $t0, reg_root + 124
        lw $t0, reg_root + 128
        sw $t0, reg_root + 128
        lw $t0, reg_root
        mul $t0, $t0, $t1
        sw $t0, reg_root
        lw $t0, reg_root + 132
        mul $t0, $t2, $t3
        sw $t0, reg_root + 132
        lw $t0, reg_root + 136
        sw $t0, reg_root + 136
        lw $t0, reg_root + 128
        sw $t0, reg_root + 128
        lw $t0, reg_root + 132
        add $t0, $t0, $t0
        sw $t0, reg_root + 132
        lw $t0, reg_root + 140
        mul $t0, $t4, $t5
        sw $t0, reg_root + 140
        lw $t0, reg_root + 144
        sw $t0, reg_root + 144
        lw $t0, reg_root + 136
        sw $t0, reg_root + 136
        lw $t0, reg_root + 140
        add $t0, $t0, $t0
        sw $t0, reg_root + 140
        lw $t0, reg_root + 148
        mul $t0, $t6, $t7
        sw $t0, reg_root + 148
        lw $t0, reg_root + 152
        sw $t0, reg_root + 152
        lw $t0, reg_root + 144
        sw $t0, reg_root + 144
        lw $t0, reg_root + 148
        add $t0, $t0, $t0
        sw $t0, reg_root + 148
        lw $t0, reg_root + 156
        mul $t0, $s0, $s1
        sw $t0, reg_root + 156
        lw $t0, reg_root + 160
        sw $t0, reg_root + 160
        lw $t0, reg_root + 152
        sw $t0, reg_root + 152
        lw $t0, reg_root + 156
        add $t0, $t0, $t0
        sw $t0, reg_root + 156
        lw $t0, reg_root + 164
        mul $t0, $s2, $s3
        sw $t0, reg_root + 164
        lw $t0, reg_root + 168
        sw $t0, reg_root + 168
        lw $t0, reg_root + 160
        sw $t0, reg_root + 160
        lw $t0, reg_root + 164
        add $t0, $t0, $t0
        sw $t0, reg_root + 164
        lw $t0, reg_root + 172
        mul $t0, $s4, $s5
        sw $t0, reg_root + 172
        lw $t0, reg_root + 176
        sw $t0, reg_root + 176
        lw $t0, reg_root + 168
        sw $t0, reg_root + 168
        lw $t0, reg_root + 172
        add $t0, $t0, $t0
        sw $t0, reg_root + 172
        lw $t0, reg_root + 180
        mul $t0, $s6, $s7
        sw $t0, reg_root + 180
        lw $t0, reg_root + 184
        sw $t0, reg_root + 184
        lw $t0, reg_root + 176
        sw $t0, reg_root + 176
        lw $t0, reg_root + 180
        add $t0, $t0, $t0
        sw $t0, reg_root + 180
        lw $t0, reg_root + 188
        mul $t0, $t8, $t9
        sw $t0, reg_root + 188
        lw $t0, reg_root + 192
        sw $t0, reg_root + 192
        lw $t0, reg_root + 184
        sw $t0, reg_root + 184
        lw $t0, reg_root + 188
        add $t0, $t0, $t0
        sw $t0, reg_root + 188
        lw $t0, reg_root + 196
        sw $t0, reg_root + 196
        lw $t0, reg_root + 72
        sw $t0, reg_root + 72
        lw $t0, reg_root + 76
        mul $t0, $t0, $t0
        sw $t0, reg_root + 76
        lw $t0, reg_root + 200
        sw $t0, reg_root + 200
        lw $t0, reg_root + 192
        sw $t0, reg_root + 192
        lw $t0, reg_root + 196
        add $t0, $t0, $t0
        sw $t0, reg_root + 196
        lw $t0, reg_root + 204
        sw $t0, reg_root + 204
        lw $t0, reg_root + 80
        sw $t0, reg_root + 80
        lw $t0, reg_root + 84
        mul $t0, $t0, $t0
        sw $t0, reg_root + 84
        lw $t0, reg_root + 208
        sw $t0, reg_root + 208
        lw $t0, reg_root + 200
        sw $t0, reg_root + 200
        lw $t0, reg_root + 204
        add $t0, $t0, $t0
        sw $t0, reg_root + 204
        lw $t0, reg_root + 212
        sw $t0, reg_root + 212
        lw $t0, reg_root + 88
        sw $t0, reg_root + 88
        lw $t0, reg_root + 92
        mul $t0, $t0, $t0
        sw $t0, reg_root + 92
        lw $t0, reg_root + 216
        sw $t0, reg_root + 216
        lw $t0, reg_root + 208
        sw $t0, reg_root + 208
        lw $t0, reg_root + 212
        add $t0, $t0, $t0
        sw $t0, reg_root + 212
        lw $t0, reg_root + 220
        sw $t0, reg_root + 220
        lw $t0, reg_root + 96
        sw $t0, reg_root + 96
        lw $t0, reg_root + 100
        mul $t0, $t0, $t0
        sw $t0, reg_root + 100
        lw $t0, reg_root + 224
        sw $t0, reg_root + 224
        lw $t0, reg_root + 216
        sw $t0, reg_root + 216
        lw $t0, reg_root + 220
        add $t0, $t0, $t0
        sw $t0, reg_root + 220
        lw $t0, reg_root + 228
        sw $t0, reg_root + 228
        lw $t0, reg_root + 104
        sw $t0, reg_root + 104
        lw $t0, reg_root + 108
        mul $t0, $t0, $t0
        sw $t0, reg_root + 108
        lw $t0, reg_root + 232
        sw $t0, reg_root + 232
        lw $t0, reg_root + 224
        sw $t0, reg_root + 224
        lw $t0, reg_root + 228
        add $t0, $t0, $t0
        sw $t0, reg_root + 228
        lw $t0, reg_root + 236
        sw $t0, reg_root + 236
        lw $t0, reg_root + 112
        sw $t0, reg_root + 112
        lw $t0, reg_root + 116
        mul $t0, $t0, $t0
        sw $t0, reg_root + 116
        lw $t0, reg_root + 240
        sw $t0, reg_root + 240
        lw $t0, reg_root + 232
        sw $t0, reg_root + 232
        lw $t0, reg_root + 236
        add $t0, $t0, $t0
        sw $t0, reg_root + 236
        lw $t0, reg_root + 244
        sw $t0, reg_root + 244
        lw $t0, reg_root + 120
        sw $t0, reg_root + 120
        lw $t0, reg_root + 124
        mul $t0, $t0, $t0
        sw $t0, reg_root + 124
        lw $t0, reg_root + 248
        sw $t0, reg_root + 248
        lw $t0, reg_root + 240
        sw $t0, reg_root + 240
        lw $t0, reg_root + 244
        add $t0, $t0, $t0
        sw $t0, reg_root + 244
        lw $t0, reg_root + 248
        move $v0, $t0
        lw $ra, 0($sp)
        addi $sp, $sp, 132
        jr $ra
    main:
        sw $t0, reg_root + 248
        sw $t1, reg_root + 4
        sw $t2, reg_root + 8
        sw $t3, reg_root + 12
        sw $t4, reg_root + 16
        sw $t5, reg_root + 20
        sw $t6, reg_root + 24
        sw $t7, reg_root + 28
        sw $s0, reg_root + 32
        sw $s1, reg_root + 36
        sw $s2, reg_root + 40
        sw $s3, reg_root + 44
        sw $s4, reg_root + 48
        sw $s5, reg_root + 52
        sw $s6, reg_root + 56
        sw $s7, reg_root + 60
        sw $t8, reg_root + 64
        sw $t9, reg_root + 68
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
        jal foo
        lw $t0, reg_root + 252
        move $t0, $v0
        move $a0, $t0
        li $v0, 1
        syscall
        la $a0, __lf__
        li $v0, 4
        syscall
        li $v0, 10
        syscall
