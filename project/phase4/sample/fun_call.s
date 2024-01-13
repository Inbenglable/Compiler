.data
    # Data section (if needed)
    .globl main

.text
    # Main code section
    main:
        li $t0, 1
        addi $sp, $sp, -4
        sw $t0, 0($sp)
        li $t1, 2
        addi $sp, $sp, -4
        sw $t1, 0($sp)
        # Exit the program
        li $v0, 10
        syscall
    
    # Function to add two numbers
    add_numbers:
        # Save the return address
        addi $sp, $sp, -4
        sw $ra, 0($sp)
        addi $sp, $sp, -4
        sw $fp, 0($sp)
        # Add the numbers
        lw $t0, 4($sp)
        lw $t1, 8($sp)
        add $v0, $t0, $t1
        # Restore the arguments
        addi $sp, $sp, 4
        lw $a1, 0($sp)
        addi $sp, $sp, 4
        lw $a0, 0($sp)
        # Restore the return address
        lw $ra, 0($sp)
        addi $sp, $sp, 4
        # Return
        jr $ra
