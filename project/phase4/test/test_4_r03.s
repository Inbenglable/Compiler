.text

    main:
        li $t0, 97
        li $t1, 110
        mul $t2, $v1, 3
        addi $t3, $t2, 13
        move $a0, $t3
        li $v0, 1
        syscall
        li $v0, 10
        syscall
