CXX := gcc
CXXFLAGS := 

OBJECTS := buffer.o queue.o


sem: main.o $(OBJECTS)
	$(CXX) main.o $(OBJECTS) -o sem
prod1: producent1.o $(OBJECTS)
	$(CXX) producent1.o $(OBJECTS) -o prod1
prod2: producent2.o $(OBJECTS)
	$(CXX) producent2.o $(OBJECTS) -o prod2
kons1: konsument1.o $(OBJECTS)
	$(CXX) konsument1.o $(OBJECTS) -o kons1
kons2: konsument2.o $(OBJECTS)
	$(CXX) konsument2.o $(OBJECTS) -o kons2
test: test.o $(OBJECTS)
	$(CXX) test.o $(OBJECTS) -o test
main.o: main.c
	$(CXX) $(CXXFLAGS) -c main.c -o main.o
producent1.o: producent1.c
	$(CXX) $(CXXFLAGS) -c producent1.c -o producent1.o
producent2.o: producent2.c
	$(CXX) $(CXXFLAGS) -c producent2.c -o producent2.o
konsument1.o: konsument1.c
	$(CXX) $(CXXFLAGS) -c konsument1.c -o konsument1.o
konsument2.o: konsument2.c
	$(CXX) $(CXXFLAGS) -c konsument2.c -o konsument2.o
test.o: test.c
	$(CXX) $(CXXFLAGS) -c test.c -o test.o
buffer.o: buffer.c
	$(CXX) $(CXXFLAGS) -c buffer.c -o buffer.o
queue.o: queue.c
	$(CXX) $(CXXFLAGS) -c queue.c -o queue.o
clean: 
	rm -f sem *.o
