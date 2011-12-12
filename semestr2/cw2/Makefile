zesp: main.o mycomplex.o myextendedcomplex.o angle.o
	g++ -static-libgcc -o zesp main.o mycomplex.o myextendedcomplex.o angle.o
main.o: main.cpp 
	g++ -c main.cpp -o main.o
mycomplex.o: mycomplex.cpp mycomplex.h
	g++ -c mycomplex.cpp -o mycomplex.o
myextendedcomplex.o: myextendedcomplex.cpp myextendedcomplex.h
	g++ -c myextendedcomplex.cpp -o myextendedcomplex.o
angle.o: angle.cpp angle.h
	g++ -c angle.cpp -o angle.o
clean:
	rm -rf *.o
