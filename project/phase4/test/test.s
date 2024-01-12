.data
reg_root: .space 

.text
main:
    # 存储值到数组
    li $t0, 0           # 第一个元素的值
    sw $t0, myArray     # 存储到数组的第一个位置

    li $t1, 1           # 第二个元素的值
    sw $t1, myArray + 4 # 存储到数组的第二个位置，每个元素占4字节

    li $t2, 2           # 第三个元素的值
    sw $t2, myArray + 8 # 存储到数组的第三个位置，每个元素占4字节

    li $t3, 3           # 第四个元素的值
    sw $t3, myArray + 12# 存储到数组的第四个位置，每个元素占4字节

    # 从数组中读取并打印值
    lw $a0, myArray     # 将数组的第一个元素加载到 $a0 寄存器
    li $v0, 1           # 设置系统调用号为1，表示打印整数
    syscall             # 调用系统调用

    lw $a0, myArray + 8 # 将数组的第三个元素加载到 $a0 寄存器
    syscall             # 调用系统调用

    # 退出程序
    li $v0, 10          # 设置系统调用号为10，表示程序退出
    syscall