CXX := g++
CXXFLAGS := 

OBJECTS := buffer.cc semaphore.cc condition.cc monitor.cc queue.cc 


monitor: $(OBJECTS)
	$(CXX) -D TEST $(OBJECTS) -lpthread -o monitor
over: $(OBJECTS)
	$(CXX) -D TEST -D OVER $(OBJECTS) -lpthread -o monitor_over
simwri: $(OBJECTS)
	$(CXX) -D TEST -D SIM_WRI $(OBJECTS) -lpthread -o monitor_simwri
simrw: $(OBJECTS)
	$(CXX) -D TEST -D SIM_RW $(OBJECTS) -lpthread -o monitor_simrw
simrrw: $(OBJECTS)
	$(CXX) -D TEST -D SIM_RRW $(OBJECTS) -lpthread -o monitor_simrrw
simrww: $(OBJECTS)
	$(CXX) -D TEST -D SIM_RWW $(OBJECTS) -lpthread -o monitor_simrww
#buffer.o: buffer.cc
#	$(CXX) $(CXXFLAGS) buffer.cc condition.cc semaphore.cc -o buffer.o
#queue.o: queue.cc
#	$(CXX) $(CXXFLAGS) -c queue.cc -o queue.o
clean: 
	rm -f *.o
