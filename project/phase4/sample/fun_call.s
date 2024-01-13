.data
    # Data section (if needed)
    .globl main

.text
    # Main code section
    main:
        
        # Exit the program
        li $v0, 10
        syscall
    
    # Function to add two numbers
    add_numbers:
        
