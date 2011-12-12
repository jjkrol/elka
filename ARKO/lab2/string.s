	.data
str1: 	.asciiz " Enter string : "
str2:	.space 80
	.text
	.globl main

main:
	li $v0, 4
	la $a0, str1
	syscall

	la $a0, str2
	li $a1, 80
	li $v0, 8
	syscall

	addi$t3, $zero, 0
loop:
	la $t0, str2
	add $t0, str2
	lb $t1, ($t0)
	beq $t1, 0, end
	addi $t1, $t1, 1
	sb $t1, ($t0)
	addi $t3, $t3, 1
	j loop
end:
	li $v0, 4
	la $a0, str2
	syscall
	
	li $v0, 10
	syscall
