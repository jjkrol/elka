/* our includes */
#include "buffer.h"
#include <pthread.h>
#include <stdlib.h>
#include <signal.h>


/*
 * initialisation - takes shared memory key and queue_size
 * returns 1 if everythings correct
 */
Buffer::Buffer(int shm_key, int queue_size):notfull(1010), notempty(1020){
	mon = new Monitor(1030);
	que = new Queue(shm_key, queue_size);
#ifdef TEST_BUF
	std::cout<<"Buffer created"<<std::endl;
#endif
}

/**
 * Destructor
 */
Buffer::~Buffer(){
	delete(que);
	delete(mon);
#ifdef TEST_BUF
	std::cout<<"Buffer destroyed"<<std::endl;
#endif
}

/*
 * pop front
 */
int Buffer::popFront(){
	mon->enter();
	if(que->get_count()==0)
		mon->wait(notempty);
	int retval = que->popFront();
	mon->signal(notfull);
	//	std::cout<<"Popped"<<std::endl;
	mon->leave();
#ifdef TEST_BUF
	std::cout<<"Buffer popFront"<<std::endl;
#endif
	return retval;
}

/*
 * pop back
 */
int Buffer::popBack(){
	mon->enter();
	if(que->get_count()==0)
		mon->wait(notempty);
	int retval = que->popBack();
	mon->signal(notfull);
	mon->leave();
#ifdef TEST_BUF
	std::cout<<"Buffer popBack"<<std::endl;
#endif
	return retval;
}

/*
 * push
 */
int Buffer::push(int data){
	//	std::cout<<"Wchodze do push"<<std::endl;
	mon->enter();
	//	std::cout<<"Wszedlem do push"<<std::endl;
	if(que->get_count()==que->get_size()){
		mon->wait(notfull);
	}
	int retval = que->push(data);
	//	std::cout<<"PUSH, wychodze"<<std::endl;
	mon->signal(notempty);
	mon->leave();
	//	std::cout<<"Pushed"<<std::endl;
#ifdef TEST_BUF
	std::cout<<"Buffer pushed"<<std::endl;
#endif
	return retval;
}

void Buffer::show(){
	que->list();
}
void Buffer::clear(){
	mon->enter();
	que->clear();
	mon->leave();
}

#ifdef TEST_BUF
int main(int argc, char* argv[]){
	std::cout<<"Beginning of TEST_BUF"<<std::endl;
	Buffer * buf;
	buf = new Buffer(6760, 10);
	int i;
	for (i = 1; i < 11; i++) {
		buf->push(10*i);
		buf->show();
	}
	for (i = 0; i < 5; i++) {
		buf->popFront();
		buf->show();
		buf->popBack();
		buf->show();
	}
	usleep(500000);
	delete(buf);
	std::cout<<"End of TEST_BUF"<<std::endl;
}
#endif

#ifdef TEST

#define KILL_SIG 3
#define WAIT_TIME 10
Buffer * buf;

void* producer(void* multiplier){
	srand(time(NULL));
	while(true){
		buf->push(rand()%100 * *(int*)multiplier);
		usleep(500000);
	}
}

void* consumer(void* ptr){
	while(true){
		buf->popFront();
		usleep(500000);
	}
}

void* list(void* ptr){
	time_t start = time(NULL);
	while(true){
		buf->show();
		usleep(250000);
	}
}

int main(int argc, char* argv[]){
	int * multOne;
	int * multTen;
	multOne = new int(1);
	multTen = new int(10);
	buf = new Buffer (atoi(argv[1]), 10);
	std::cout<<"Poczatek testow"<<std::endl;
	pthread_t threadA, threadB, threadC, threadD, threadE;

	system("clear");
	time_t start;

#ifdef OVER
	std::cout<<"Test przepelnienia kolejki"<<std::endl;
	usleep(1000000);
	pthread_create(&threadA, NULL, producer, (void*)multOne);
	pthread_create(&threadB, NULL, list, NULL);
	start=time(NULL);
	while(true){
		if (time(NULL)-WAIT_TIME*2>=start){
			pthread_cancel(threadA);
			pthread_cancel(threadB);
			break;
		}
	}
#endif

#ifdef SIM_WRI
	system("clear");
	std::cout<<"Test rownoczesnego zapisu"<<std::endl;
	usleep(500000);
	pthread_create(&threadA, NULL, producer, (void*)multOne);
	pthread_create(&threadB, NULL, list, NULL);
	pthread_create(&threadC, NULL, producer, (void*)multTen);
	start=time(NULL);
	while(true){
		if (time(NULL)-WAIT_TIME>=start){
			pthread_cancel(threadA);
			pthread_cancel(threadB);
			pthread_cancel(threadC);
			break;
		}
	}
#endif

#ifdef SIM_RWW
	system("clear");
	std::cout<<"Test rownoczesnego zapisu i odczytui (wiecej zapisu)"<<std::endl;
	usleep(1000000);
	pthread_create(&threadA, NULL, producer, (void*)multOne);
	pthread_create(&threadB, NULL, list, NULL);
	pthread_create(&threadC, NULL, producer, (void*)multTen);
	usleep(500000);
	pthread_create(&threadE, NULL, consumer, (void*)NULL);
	start=time(NULL);
	while(true){
		if (time(NULL)-WAIT_TIME-10>=start){
			system("clear");
			pthread_cancel(threadA);
			pthread_cancel(threadB);
			pthread_cancel(threadE);
			pthread_cancel(threadC);
			break;
		}
	}
#endif
#ifdef SIM_RW
	system("clear");
	std::cout<<"Test rownoczesnego zapisu i odczytu (po rowno)"<<std::endl;
	usleep(1000000);
	pthread_create(&threadA, NULL, producer, (void*)multOne);
	pthread_create(&threadB, NULL, list, NULL);
	pthread_create(&threadC, NULL, producer, (void*)multTen);
	usleep(500000);
	pthread_create(&threadD, NULL, consumer, (void*)NULL);
	pthread_create(&threadE, NULL, consumer, (void*)NULL);
	start=time(NULL);
	while(true){
		if (time(NULL)-WAIT_TIME-20>=start){
			system("clear");
			pthread_cancel(threadA);
			pthread_cancel(threadB);
			pthread_cancel(threadD);
			pthread_cancel(threadE);
			pthread_cancel(threadC);
			break;
		}
	}
#endif

#ifdef SIM_RRW
	system("clear");
	std::cout<<"Test rownoczesnego zapisu i odczytu (wiecej odczytu)"<<std::endl;
	usleep(1000000);
	pthread_create(&threadA, NULL, producer, (void*)multOne);
	pthread_create(&threadB, NULL, list, NULL);
	usleep(500000);
	pthread_create(&threadD, NULL, consumer, (void*)NULL);
	pthread_create(&threadE, NULL, consumer, (void*)NULL);
	start=time(NULL);
	while(true){
		if (time(NULL)-WAIT_TIME-20>=start){
			system("clear");
			pthread_cancel(threadA);
			pthread_cancel(threadB);
			pthread_cancel(threadD);
			pthread_cancel(threadE);
			break;
		}
	}
#endif
	delete(multOne);
	delete(multTen);
	delete(buf);
	system("clear");
	return 0;
}
#endif
