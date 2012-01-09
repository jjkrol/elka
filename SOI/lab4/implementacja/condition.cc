#include "condition.h"

Condition::Condition(key_t key){
	waitingCount = 0;
	sem = new Semaphore(key, 0666 | IPC_CREAT, 0);
#ifdef TEST_CON
	std::cout<<"Condition created"<<std::endl;
#endif
}

Condition::~Condition(){
	delete(sem);
#ifdef TEST_CON
	std::cout<<"Condition destroyed"<<std::endl;
#endif
}

void Condition::wait(){
	waitingCount++;
	sem->proberen();
#ifdef TEST_CON
	std::cout<<"Condition wait"<<std::endl;
#endif
}

bool Condition::signal(){
#ifdef TEST_CON
	std::cout<<"Condition signal"<<std::endl;
#endif
	if(waitingCount){
//		std::cout<<"Wysylam sygnal"<<std::endl;
		waitingCount--;
		sem->verhogen();
//		std::cout<<"Wracam z sygnalu"<<std::endl;
		return true;
	}
	else
		return false;
}


#ifdef TEST_CON

int main(int argc, char* argv[]){
std::cout<<"Beginning of TEST_CON"<<std::endl;
Condition * con;
con = new Condition(1001);
con->wait();
con->signal();
delete(con);
std::cout<<"End of TEST_CON"<<std::endl;
}
#endif
