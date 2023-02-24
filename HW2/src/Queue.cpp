/**
* @file Queue.cpp
* @description Kuyruk sinifi. ekleme cikarma vb. fonksiyon barindirir. Array ile olusturuldu. Radix sort icin kullaniliyor.
* @course Veri Yapilari 1/C
* @assignment 2
* @date 08.12.2022
* @author İlyas Aydın ilyas.aydin1@ogr.sakarya.edu.tr
*/
#include "Queue.hpp"
Queue::Queue()
{
	first = 0;
	last = -1;
	size = 0;
	capacity = 10;
	queue = new int[capacity];
}

void Queue::enqueue(int value)
{
	if (size == capacity)
	{
		expand();
	}
	last = (last + 1) % capacity;
	queue[last] = value;
	size++;
}
void Queue::expand()
{
	int* tmp = new int[capacity+5];
	for (int i = 0; i < size; i++)
	{
		tmp[i] = queue[first];
		first = (first + 1) % capacity;
	}
	delete []queue;
	queue = tmp;
	first = 0;
	last = capacity - 1;
	capacity += 5;
}
int Queue::dequeue()
{
	int value = first;
	if (size > 0)
	{
		first = (first + 1) % capacity;
		size--;
		return queue[value];
	}
	return 0;
	
}
int Queue::peek()
{
	return queue[first];
}

bool Queue::empty()
{
	return size==0;
}

int Queue::count()
{
	return size;
}
Queue::~Queue()
{
	delete []queue;
}

