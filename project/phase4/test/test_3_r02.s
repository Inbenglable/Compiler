.data
    .globl main

.text
    j main
    fact:
        lw $t0, 0($sp)
        addi $sp, $sp, 4
        li $a1, 1
        bne $t0, $a1, label_0
        move $v0, $t0
        jr $ra
        j label_1
    label_0:
        addi $t1, $t0, -1
        move $a0, $t1
        addi $sp, $sp, -4
        sw $a0, 0($sp)
        jal fact
        move $t2, $v0
        mul $t3, $t0, $t2
        move $v0, $t3
        jr $ra
    label_1:
    main:
        li $v0, 5
        syscall
        move $t4, $v0
        li $a1, 1
        ble $t4, $a1, label_2
        move $a0, $t4
        addi $sp, $sp, -4
        sw $a0, 0($sp)
        jal fact
        move $t5, $v0
        j label_3
    label_2:
        li $t5, 1
    label_3:
        move $a0, $t5
        li $v0, 1
        syscall
        li $v0, 0
        jr $ra
