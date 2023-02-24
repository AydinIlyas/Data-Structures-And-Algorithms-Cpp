#ifndef Radix_hpp
#define Radix_hpp
#include "Queue.hpp"
#include "Doku.hpp"

class Radix
{
public:
    Radix(Doku* numbers,int length);
    ~Radix();
    int* sort();
	int midValue();

private:
    int     maxStepCount();
    int     stepCount(int number);
    void    QueueLengths(int* lengths);
    Queue** queues;
    int*    numbers;
    Doku* doku;
    int     length;
};

#endif