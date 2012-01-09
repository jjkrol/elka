class Queue{
	int *queue;
	int id;
	int size;
	int count;
	void increment(int*);
	void decrement(int*);

public:
	Queue(int, int);
	~Queue();
	int push(int);
	int popFront();
	int popBack();
	int list();
	int get_count();
	int get_size();
	void clear();
};
