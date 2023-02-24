#ifndef Queue_hpp
#define Queue_hpp
class Queue
{
private:
	int* queue;
	int size;
	int first;
	int last;
	int capacity;
public:
	Queue();
	void enqueue(int value);
	int dequeue();
	void expand();
	bool empty();
	int count();
	int peek();
	~Queue();

};
#endif

