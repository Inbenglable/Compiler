# SPL compiler generated assembly
.data
_prmpt: .asciiz "Enter an integer: "
_eol: .asciiz "\n"
.globl main
.text
read:
  li $v0, 4
  la $a0, _prmpt
  syscall
  li $v0, 5
  syscall
  jr $ra
write:
  li $v0, 1
  syscall
  li $v0, 4
  la $a0, _eol
  syscall
  move $v0, $0
  jr $ra
hanoi:
  move $s0, $t0
  li $s0, 1
  j label1
label0:
  move $s0, $t0
  li $s0, 10000
  mul $s0, $t0, $t0
  move $s0, $t0
  add $s0, $t0, $t0
  move $a0, $s0
  addi $sp, $sp, -4
  sw $ra, 0($sp)
  jal write
  lw $ra, 0($sp)
  addi $sp, $sp, 4
  j label2
label1:
  move $s0, $t0
  li $s0, 1
  sub $s0, $t0, $t0
  move $s0, $t0
  move $s0, $t0
  move $s0, $t0
  move $s0, $t0
  li $s0, 10000
  mul $s0, $t0, $t0
  move $s0, $t0
  add $s0, $t0, $t0
  move $a0, $s0
  addi $sp, $sp, -4
  sw $ra, 0($sp)
  jal write
  lw $ra, 0($sp)
  addi $sp, $sp, 4
  move $s0, $t0
  li $s0, 1
  sub $s0, $t0, $t0
  move $s0, $t0
  move $s0, $t0
  move $s0, $t0
label2:
  li $s0, 0
main:
  li $s0, 3
  move $s0, $t0
  move $s0, $t0
  li $s0, 1
  li $s0, 2
  li $s0, 3
  li $s0, 0
