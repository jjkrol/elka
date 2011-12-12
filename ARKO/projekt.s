	.data
hello:	.asciiz "Wyszukiwanie\n"
input:	.asciiz "dane.dat"
sig:	.word	22287 
sigsize:.word	10	
bytemask:.byte	0
buffer:	.space	2421	
bajt:	.asciiz "Znaleziono od bajtu:\n"
bit:	.asciiz "\n Bit: \n"

	.text
	.globl main
# 2420


findsig:
	move	$t1, $a0 	#temp dla buf
	move	$t2, $a1 	#temp dla sig
	move	$t5, $a1	#pamietaj ktory jest pierwszy bajt sygnatury
	move	$t3, $a2 	#maska bitowa
	move	$s3, $ra 	#temp dla return

loop:
	# t1 to wskaznik na bufor
	# t2 to wskazanie na sygnature
	# t3 na poczatku sprawdza czy ciag sie nie skonczyl, a potem jest maska bitowa
	# t4 to wynik ich porownania
	# t5
	# t6 zapamietuje w ktorym bajcie byl pierwszy sukces
	# t7 zapamietuje w ktorym bicie tego bajtu byl sukces
	# s1 to bajt bufora
	# s2 to bajt sygnatury
	# s3 to temp dla buf AND maska
	# s4 to temp dla sig AND maska
	# s5 to kolejny pierdolony licznik, liczy w ktorym miejscu bajtu jestesmy
	# s6 to licznik przesuniecia sygnatury (czyli nty dopasowany bit)
	

	# czy to nie koniec ciagu przeszukiwanego?
	lb 	$t3, ($t1)	# zaladuj bit do porownania
	beq	$t3, 0, loopend # salto

	lb 	$s1, ($t1)	#laduj bit bufora 
	lb	$s2, ($t2)	#laduj bit sygnatury 
	sllv	$s2, $s2, $s6	# przesun w lewo o tyle ile juz jest dopasowanych
				# (przy ciagu dalszym dopasowania)
	li	$t3, 128	# resetuj maske bitowa, niech bedzie 10000000
	li	$s5, 0		# koljeny pierdolony licznik, liczy ile bitow
byteloop:
	# tutaj przesuwamy sie w obrebie jednego bajtu
	# robimy to przesuwajac maske bitowa (w ten sposob
	# bierzemy po jednym bicie) za pomoca srlv

	beqz	$t3, byteloopend #jesli koniec bajtu, to koncz petle

	and	$s3, $t3, $s1	# sprawdz bit w buf
	and	$s4, $t3, $s2	# sprawdz bit w sig
	#xor	$t4, $s3, $s4	# porownaj je ze soba
	# xor dla takich samych wartosci da 0
	beq	$s3, $s4, bytesuccess# jesli takie same, ???, PROFIT!

	# jesli sie nie udalo a byly przedtem sukcesy
	beqz	$s6, blunsucont
	#wroc do miejsca ostatniego sukcesu w buforze
	move	$t1, $t6	# odzyskaj wskazanie na bajt
	lb	$s1, ($t1)	# odzyskaj bajt
	move	$s5, $t7	# odzyskaj licznik
	move	$t3, $t8	# odzyska maske
blunsucont:
	li	$s6, 0 		# kontrolnie zeruj licznik
	lb	$s2, ($t5)	# wroc do poczatku sygnatury
	srlv	$s2,$s2,$s5	# przesun o tyle ile jest maska	
blcont: 
	# kontynuuj petle
	srl	$t3,$t3, 1 	# przesun maske, zeby badac nastepny bit
	addi	$s5, 1		# inkrementuj licznik przesuniec 
	b byteloop 		# salto

byteloopend:
	# koniec petli, wez nastepny bajt ciagu przeszukiwanego
	addi	$t1, 1
	b loop

bytesuccess:
# jesli to pierwszy sukces, zapamietujemy, gdzie sie zdarzyl, zeby moc wrocic
# jesli okaze sie, ze to lipa
	beqz	$s6, firstsuc
bscont:
# jesli znalezlismy pasujace bajty, nie przesuwamy sygnatury,
# dzieki temu bedziemy badac nastepny bit. Zwiekszamy tylko licznik
# zeby jesli jednak dopasowanie sie nie uda, moc wrocic do odpowiedniej pozycji
	addi	$s6, 1
# kontroluj, czy nie skonczyla sie sygnatura (dlugosc okreslona w sigsize)
	la	$t9, sigsize		# 
	lb	$s7, ($t9)
	beq	$s7, $s6, success
# kontroluj, czy nie skonczyl sie juz bajt sygnatury. Jesli tak, zaladuj nastepny
	beq	$s6, 8, nextbyte#j jesli doszedl do 8 (caly bit sie przesunal)
	b blcont

nextbyte:
	li	$s6, 0		# wyzeruj licznik przesuniecia sygnatury
	addi	$t2, 1		# wez nastepny bit z sygnatury
	lb	$s2, ($t2)	# zaladuj go do s2
	b	blcont		# wroc
firstsuc:
	move	$t6, $t1	# zapisz miejsce w buforze
	move	$t7, $s5	# zapisz licznik petli bajtu
	move	$t8, $t3	# zapisz maske
	b	bscont

success:
#wypisz ciag	
	li	$v0, 4
	la	$a0, bajt
	syscall

#wypisz ktory bajt	
	li	$v0, 1
	move	$a0, $t6
	syscall

#wypisz ciag	
	li	$v0, 4
	la	$a0, bit
	syscall

#wypisz ktory bit	
	li	$v0, 1
	move	$a0, $t7
	syscall

	b end
#successloop:
#	addi	$t6, 1
#	addi	$t5, 1 #nastepny znak
#	lb	$t8, ($t6)
#	beq	$t8, 0, loopend #kon, zwr
loopend:
	move	$v0, $t1
	jr	$s3

main:
	li $v0, 4
	la $a0, hello
	syscall
#open
	la	$a0, input
	li 	$a1, 0		#flags
	li	$a2, 0		#mode
	li	$v0, 13
	syscall

#read
	move	$a0, $v0
	la	$a1, buffer
	li	$a2, 2421
	li	$v0, 14
	syscall

#close
	li	$v0, 16
	syscall

#plik wczytany, nakurwiam salto
	la	$a0, buffer 
	la	$a1, sig
        la	$a2, bytemask	
	li	$s6, 0
	jal	findsig
	
	move	$a0, $v0
	li	$v0, 4
	syscall
end:
	li $v0, 10
	syscall


#wypisz ciag	
#	li	$v0, 4
#	la	$a0, buffer
#	syscall

