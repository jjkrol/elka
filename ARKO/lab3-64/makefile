all:	main asm link

link:	main.o graf.o
	gcc -lm -fpack-struct=1 -m64 -o graf main.o graf.o
main:	graf_io.c
	gcc -lm -c -m64 -fpack-struct=1 graf_io.c -o main.o
asm:	graf.s
	nasm -f elf64 graf.s -o graf.o


