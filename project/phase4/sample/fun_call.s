.data
    # Data section (if needed)

.text
    # Main code section
    main:
        # Prepare arguments for the function
        li $a0, 1        # First argument
        li $a1, 2        # Second argument
        li $a2, 3        # Third argument
        li $a3, 4        # Fourth argument

        # Push additional arguments onto the stack
        li $t0, 5        # Fifth argument
        sw $t0, -4($sp)  # Push onto the stack

        li $t0, 6        # Sixth argument
        sw $t0, -8($sp)  # Push onto the stack

        # Call the function
        jal my_function

        # Clean up the stack if needed

        # Exit the program
        li $v0, 10
        syscall

    my_function:
        # Function prologue
        # Save the return address and frame pointer
        sw $ra, 0($sp)
        sw $fp, -4($sp)
        # Set the frame pointer to the current stack pointer
        move $fp, $sp

        # Access arguments
        lw $t0, 8($fp)    # First argument (at offset 8 from frame pointer)
        lw $t1, 12($fp)   # Second argument (at offset 12 from frame pointer)
        lw $t2, 16($fp)   # Third argument (at offset 16 from frame pointer)
        lw $t3, 20($fp)   # Fourth argument (at offset 20 from frame pointer)
        lw $t4, 24($fp)   # Fifth argument (at offset 24 from frame pointer)
        lw $t5, 28($fp)   # Sixth argument (at offset 28 from frame pointer)

        # Function body
        # Perform operations with the arguments

        # Function epilogue
        # Restore the frame pointer and return address
        lw $ra, 0($sp)
        lw $fp, -4($sp)
        # Adjust the stack pointer
        addi $sp, $sp, 8

        # Return from the function
        jr $ra
