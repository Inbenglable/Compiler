.text

    main:
        li $v0, 5
        syscall
        move $t0, $v0
        li $a1, 0
        ble $t0, $a1, label_0
        li $a0, 1
        li $v0, 1
        syscall
        j label_1
    label_0:
        li $a1, 0
        bge $t0, $a1, label_2
        li $a0, -1
        li $v0, 1
        syscall
        j label_3
    label_2:
        li $a0, 0
        li $v0, 1
        syscall
    label_3:
    label_1:
        li $v0, 10
        syscall
