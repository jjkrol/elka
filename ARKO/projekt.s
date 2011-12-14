	.data
sig:	.byte 0x11
	.byte 0x31
	.byte 0x92
	.byte 0xD5
	.byte 0x29
	.byte 0xDB	
	.byte 0xE0
	.byte 0x44
sigsize:.word	34		
mask:	.word	0xFFFFFFFF 
buffer:	.space	2421	
bajt:	.asciiz "Znaleziono tyle bitow od poczatku:\n"
hello:	.asciiz "Wyszukiwanie\n"
input:	.asciiz "dane.dat"

	.text
	.globl main
# 2420


findsig:
	li	$s6, 0
	li	$t4, 0
	move	$t1, $a0 	#temp dla buf
	move	$t2, $a1 	#temp dla sig
	lw	$t5, ($a2)	# dlugosc sygnatury
	sub	$t5, $t5, 32
	li	$s3, 0xFFFFFFFF	# zaladuj jedynki
	srl	$s3, $s3, $t5	# zrob (siglen-32) zer w masce
	
	
	

	lbu	$s1, ($t2)	# pierwsze 4  bajty sygnatury
	addiu	$t2, $t2, 1
	sll	$s1, $s1,8
	lbu	$t9, ($t2)
	addu	$s1, $s1, $t9
	addiu	$t2, $t2, 1
	sll	$s1, $s1,8
	lbu	$t9, ($t2)
	addu	$s1, $s1, $t9
	addiu	$t2, $t2, 1
	sll	$s1, $s1,8
	lbu	$t9, ($t2)
	addu	$s1, $s1, $t9
	addiu	$t2, $t2, 1

	lbu	$s2, ($t2)	# kolejne 4  bajty sygnatury
	addiu	$t2, $t2, 1
	sll	$s2, $s2,8
	lbu	$t9, ($t2)
	addu	$s2, $s2, $t9
	addiu	$t2, $t2, 1
	sll	$s2, $s2,8
	lbu	$t9, ($t2)
	addu	$s2, $s2, $t9
	addiu	$t2, $t2, 1
	sll	$s2, $s2,8
	lbu	$t9, ($t2)
	addu	$s2, $s2, $t9
	addiu	$t2, $t2, 1
	or	$s2, $s2, $s3	# utnij drugie slowo sygnatury do dodlugosci
				# maska dl sygnatury

	lbu	$s4, ($t1)	# pierwsze 4 bajty bufora 
	addiu	$t1, $t1, 1
	sll	$s4, $s4,8
	lbu	$t9, ($t1)
	addu	$s4, $s4, $t9
	addiu	$t1, $t1, 1
	sll	$s4, $s4,8
	lbu	$t9, ($t1)
	addu	$s4, $s4, $t9
	addiu	$t1, $t1, 1
	sll	$s4, $s4,8
	lbu	$t9, ($t1)
	addu	$s4, $s4, $t9
	addiu	$t1, $t1, 1

	lbu	$s5, ($t1)	# kolejne 4  bajty bufora
	addiu	$t1, $t1, 1
	sll	$s5, $s5,8
	lbu	$t9, ($t1)
	addu	$s5, $s5, $t9
	addiu	$t1, $t1, 1
	sll	$s5, $s5,8
	lbu	$t9, ($t1)
	addu	$s5, $s5, $t9
	addiu	$t1, $t1, 1
	sll	$s5, $s5,8
	lbu	$t9, ($t1)
	addu	$s5, $s5, $t9
	addiu	$t1, $t1, 1

	lbu	$s6, ($t1)	# kolejne 4 bajty bufora
	addiu	$t1, $t1, 1
	sll	$s6, $s6,8
	lbu	$t9, ($t1)
	addu	$s6, $s6, $t9
	addiu	$t1, $t1, 1
	sll	$s6, $s6,8
	lbu	$t9, ($t1)
	addu	$s6, $s6, $t9
	addiu	$t1, $t1, 1
	sll	$s6, $s6,8
	lbu	$t9, ($t1)
	addu	$s6, $s6, $t9
	addiu	$t1, $t1, 1
	
	li	$t8, 0		# zeruj licznik przesuniecia

loop:
	# t1 to wskaznik na bufor
	# t2 to wskazanie na sygnature
	# t3 na poczatku sprawdza czy ciag sie nie skonczyl
	# t4 licznik przesuniecia sygnatury
	
	# t8 licznik przesuniecia
	# t9 temp 

	# s1 to 1 slowo sygnatury
	# s2 drugie slowo sygnatury
	# s3 to maska dlugoscisygatury
	# s4 pierwsze slowo bufora
	# s5 drugie slowo bufora
	# s6 trzecies slowo bufora
	# s7 temp dla drugiego slowa 
	

	# czy to nie koniec ciagu przeszukiwanego?
	beq	$t8, 75, loopend
	bne 	$s1, $s4, nextloop	#jesli rozni sie pierwze slowo
	move 	$s7, $s5		# temp dla $s5
	or 	 $s7, $s7, $s3		# utnij do dlugosci sygnatury 
	bne	$s7, $s2, nextloop	# drugie slowo tez rowne
	b success

nextloop:	# nie udalo sie, przesun o jeden
	lw	$t6, mask
	sll	$s4, $s4, 1	# przesun pierwsze slowo bufora o jeden	
	and	$s4, $s4, $t6 
	move	$t9, $s5	# temp
	srl	$t9, $t9, 31	# wez ostatni
	addu	$s4, $s4, $t9	# wpisz pierwszy z s5 jako ostatni w s4

	sll	$s5, $s5, 1
	move	$t9, $s6	# temp
	srl	$t9, $t9, 31	# wez ostatni
	addu	$s5, $s5, $t9	# wpisz pierwszy z s6 jako ostatni w s5

	sll	$s6, $s6, 1 	#przesun s5
	addiu	$t8, 1
	beq	$t8, 32, nextword
	# sprawdz, czy nie trzeba zaladowac nowego do s6

	b loop

nextword:
	addiu	$t1, 1
	lb	$s6, ($t1)	# kolejne 4  bajty bufora
	addiu	$t1, $t1, 1
	sll	$s6, $s2,8
	lb	$t9, ($t1)
	addu	$s6, $s2, $t9
	addiu	$t1, $t1, 1
	sll	$s6, $s2,8
	lb	$t9, ($t1)
	addu	$s6, $s2, $t9
	addiu	$t1, $t1, 1
	sll	$s6, $s2,8
	lb	$t9, ($t1)
	addu	$s6, $s2, $t9
	addiu	$t1, $t1, 1

	b loop


success:
	sub	$t1, 12		# przesun do poczatku
#wypisz ktory to bit	
	la	$a1, buffer # zapisz poczatkowy bit 
	move	$v0, $t1	# wpsiz bajt na ktorym znaleziono
	subu	$v0, $v0, $a1	# odejmij
	mulou	$v0, $v0, 8	# ile to bitow?
	addu	$v0, $v0, $t8
	jr	$ra

loopend:
	li	$v0, -1
	jr	$ra

main:
	li $v0, 4
	la $a0, hello		# powitanie
	syscall
	# otworz plik
	la	$a0, input
	li 	$a1, 0		#flags
	li	$a2, 0		#mode
	li	$v0, 13
	syscall

	# czytaj
	move	$a0, $v0
	la	$a1, buffer
	li	$a2, 2421
	li	$v0, 14
	syscall

	# zamknij plik
	li	$v0, 16
	syscall

#plik wczytany, 
	li	$v0, 4		# wypisz komunikat
	la	$a0, bajt
	syscall

	la	$a0, buffer 
	la	$a1, sig
	la	$a2, sigsize		 
	jal	findsig

	move	$a0, $v0	# wypisz wynik
	li	$v0, 1
	syscall
end:
	li $v0, 10
	syscall


