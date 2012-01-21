CXX := g++
CXXFLAGS := 

OBJECTS := main.cc disk.o

diskmanager: $(OBJECTS)
	$(CXX) $(OBJECTS) -o diskmanager
main.o: main.cc
	$(CXX) -c main.cc
disk.o: disk.cc 
	$(CXX) -c disk.cc
clean: 
	rm -f *.o
