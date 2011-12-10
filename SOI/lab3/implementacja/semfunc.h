/*
semaphore functions for
allocating
deallocating
initialising
proberen
verhogen
*/
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/types.h>
union semun{
	int val;
	struct semid_ds *buf;
	unsigned short int *array;
	struct seminf *__buf;
};

/*
Allocation of a semaphore
*/
int sem_alloc(key_t key, int sem_flags){
	return  semget(key, 1, sem_flags);
}

/*
Deallocation of a semaphore with id semid
*/
int sem_dealloc(int semid){
	union semun ignored_argument;
	return semctl(semid, 1, IPC_RMID, ignored_argument);
}

/*
   semaphore initialisation
*/
int sem_init(int semid, int value){
	union semun argument;
	unsigned short values[1];
	values[0] = value;
	argument.array = values;
	return semctl(semid, 0, SETALL, argument);
}

/*
   proberen
*/
int sem_proberen(int semid){
	struct sembuf op[1];
	op[0].sem_num = 0;
	op[0].sem_op = -1;
	op[0].sem_flg = SEM_UNDO;

	return semop(semid, op, 1);
}

/*
   verhogen
*/
int sem_verhogen(int semid){
	struct sembuf op[1];
	op[0].sem_num = 0;
	op[0].sem_op = 1;
	op[0].sem_flg = SEM_UNDO;

	return semop(semid, op, 1);
}

