.data
    .globl main
    __prompt__: .asciiz "Enter an integer: "
.text

    main:
        li $t0, 30
        li $t1, 0
        li $t2, 1
        li $t3, 1
    label_0:
        bgt $t3, $t0, label_1
    label_2:
        bgt $t2, $t3, label_3
        div $t4, $t3, $t2
        mul $t5, $t4, $t2
        bne $t3, $t5, label_4
        addi $t1, $t1, 1
    label_4:
        addi $t2, $t2, 1
        j label_2
    label_3:
        li $a1, 2
        bne $t1, $a1, label_5
        move $a0, $t3
        li $v0, 1
        syscall
    label_5:
        li $t2, 1
        li $t1, 0
        addi $t3, $t3, 1
        j label_0
    label_1:
        li $v0, 10
        syscall
