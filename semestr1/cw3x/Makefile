all: przedszkole
przedszkole: main.o pomoc.o interface.o
	gcc -Wall -o przedszkole main.o interface.o
main.o: main.c
	gcc -Wall -o main.o -c main.c
interface.o: interface.c
	gcc -Wall -o interface.o -c interface.c
clean:
	rm -rf *.o a.out 
