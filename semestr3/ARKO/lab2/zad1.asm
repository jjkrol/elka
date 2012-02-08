	.data
s1:	.asciiz "almanach Ali. Nawalil\n"
s2:	.asciiz "ali"
	.text
.globl main

compare:
	lb $s1, ($a2)
	lb $s2, ($a3)
	beq $s1,$s2,compsucc
	bge $s1, 'a',minusc
	sub $s2,32
	beq $s1,$s2, compsucc
	b compfail
minusc:
	ble, $s1,'z', compfail
	sub $s1,32
	beq $s1,$s2, compsucc
compfail:
	li $v0, 0
	jr $ra
compsucc:
	li $v0, 1
	jr $ra

strstr:
	move $t1, $a0
	move $t2, $a1
	move $s3, $ra
loopext:	
	lb $t4, ($t2)
loop:
	lb $t3, ($t1)
	beq $t3, 0,loopend 
	move $a2, $t1	
	move $a3, $t2
	jal compare
	beq $v0, 1, success 

	addi $t1,1
	b loop
success:
	move $t5, $t1 #miejsce, w ktorym znalezlismy
	move $t6, $t2
successloop:
	addi $t6,1
	addi $t5,1 #nastepne znaki
	lb $t8, ($t6)
	beq $t8,0,loopend # koniec wzorca, zwracamy
	move $a2, $t5	
	move $a3, $t6
	jal compare
	beq $v0, 1, successloop 
	addi $t1,1
	b loopext
loopend:
	move $v0, $t1 
	jr $s3 
main:
	la $a0, s1
	la $a1, s2
	jal strstr
#	li $t1, $v0
	move $a0, $v0
	li $v0, 4
	syscall
end:
	li $v0,10
	syscall
