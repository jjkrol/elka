all:	main asm link

main:	graf_io.c
	g++ -g -c -m32 -fpack-struct=1 graf_io.c -o main.o
asm:	graf.s
	nasm -f elf graf.s -o graf.o
link:	main.o graf.o
	g++ -g -m32 -o graf main.o graf.o


