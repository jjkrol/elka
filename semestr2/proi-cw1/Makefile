zesp: main.o mycomplex.o
	g++ -Wall -o zesp main.o mycomplex.o
main.o: main.cpp
	g++ -Wall -c main.cpp
mycomplex.o: mycomplex.cpp mycomplex.h
	g++ -Wall -c mycomplex.cpp
clean:
	rm -f *.o
