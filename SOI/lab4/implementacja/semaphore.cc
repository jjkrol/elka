#include "semaphore.h"
Semaphore::Semaphore(key_t key, int semFlags, int value){
	semid =  semget(key, 1, semFlags); //sem alloc TODO throw
	union semun argument; // initialise
	unsigned short values[1];
	values[0] = value;
	argument.array = values;
#ifdef TEST_SEM
	std::cout<<"Semaphore created"<<std::endl;
#endif
	 semctl(semid, 0, SETALL, argument);
}

Semaphore::~Semaphore(){
	union semun ignored_argument;
#ifdef TEST_SEM
	std::cout<<"Semaphore destroyed"<<std::endl;
#endif
	semctl(semid, 1, IPC_RMID, ignored_argument);

}

int Semaphore::proberen(){
#ifdef TEST_SEM
	std::cout<<"Semaphore proberen"<<std::endl;
#endif
	struct sembuf op[1];
	op[0].sem_num = 0;
	op[0].sem_op = -1;
	op[0].sem_flg = SEM_UNDO;

return semop(semid, op, 1);;
}

int Semaphore::verhogen(){
#ifdef TEST_SEM
	std::cout<<"Semaphore verhogen"<<std::endl;
#endif
	struct sembuf op[1];
	op[0].sem_num = 0;
	op[0].sem_op = 1;
	op[0].sem_flg = SEM_UNDO;

	return semop(semid, op, 1);
}

#ifdef TEST_SEM
int main(int argc, char* argv[]){
std::cout<<"Beginning of TEST_SEM"<<std::endl;
Semaphore * sem;
sem = new Semaphore(1001, 0666 | IPC_CREAT,0);
sem->proberen();
sem->verhogen();
delete(sem);
std::cout<<"End of TEST_SEM"<<std::endl;
}
#endif
