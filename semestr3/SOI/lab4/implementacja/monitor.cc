#include "monitor.h"

Monitor::Monitor(key_t key){
sem = new Semaphore(key, 0666|IPC_CREAT, 1);
#ifdef TEST_MON
	std::cout<<"Monitor created"<<std::endl;
#endif
}

Monitor::~Monitor(){
delete(sem);
#ifdef TEST_MON
	std::cout<<"Monitor destroyed "<<std::endl;
#endif
}

void Monitor::wait(Condition & cond){
leave();
cond.wait();
//enter();
#ifdef TEST_MON
	std::cout<<"Monitor wait"<<std::endl;
#endif
}

void Monitor::signal(Condition & cond){
//	leave();
if(cond.signal()) enter();
#ifdef TEST_MON
	std::cout<<"Monitor verhogen"<<std::endl;
#endif
}

void Monitor::enter(){
sem->proberen();
#ifdef TEST_MON
	std::cout<<"Monitor enter"<<std::endl;
#endif
}
void Monitor::leave(){
sem->verhogen();
#ifdef TEST_MON
	std::cout<<"Monitor leave"<<std::endl;
#endif
}

#ifdef TEST_MON
int main(int argc, char* argv[]){
std::cout<<"Beginning of TEST_MON"<<std::endl;
Monitor * mon;
Condition con(1000);
mon = new Monitor(1005);
mon->enter();
mon->signal(con);
mon->wait(con);
mon->leave();
delete(mon);
std::cout<<"End of TEST_MON"<<std::endl;
}
#endif
