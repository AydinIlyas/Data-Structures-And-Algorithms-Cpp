#include "Radix.hpp"
#include"Doku.hpp"
#include<iomanip>
Radix::Radix(Doku* numbers,int length)
{
    this->length = length;
    doku=numbers;
	this->numbers=new int[length];
    queues = new Queue*[10];
    for(int i=0;i<10;i++)
    {
        queues[i] = new Queue();
    }
    
    
}
Radix::~Radix()
{
    delete[] numbers;
    for(int i=0;i<10;i++)
    {
        delete queues[i];
    }
    
    delete [] queues;

    
}

int *Radix::sort()
{

    for(int i=0;i<length;i++)
    {
        numbers[i]=doku->getHucre(i)->getValue();
        int lastDigit = numbers[i]%10;
        queues[lastDigit]->enqueue(numbers[i]);
    }
    int maxSteps = maxStepCount();
    
    
    int basamakCarpani = 10;

    for(int i = 1;i<maxSteps;i++ )
    {
        int lengths[10];

        QueueLengths(lengths);

        for(int j=0;j<10;j++)
        {
            int es = lengths[j];

            while(es)
            {
                int siradakiSayi = queues[j]->peek();

                queues[j]->dequeue();
                int steps = (siradakiSayi/basamakCarpani)%10;
                queues[steps]->enqueue(siradakiSayi);
                es--;
            }
        }
        basamakCarpani*=10;
    }
    int index = 0;
    for(int i=0;i<10;i++)
    {
        while(!queues[i]->empty())
        {
            numbers[index] = queues[i]->peek();
            queues[i]->dequeue();
            index++;
        }
    }
    
    return numbers;
}

int Radix::maxStepCount()
{
    int maxSteps = stepCount(numbers[0]);

    for(int i=1;i<length;i++)
    {
        int siradakiBasamakSayisi = stepCount(numbers[i]);
        if(maxSteps<siradakiBasamakSayisi)
            maxSteps = siradakiBasamakSayisi;
    }
    return maxSteps;
}
int Radix::stepCount(int number)
{
    int steps = 0;
    while(number)
    {
        number = number/10;
        steps++;
    }
    return steps;

}

void Radix::QueueLengths(int* lengths)
{
    for(int i=0;i<10;i++)
    {
        lengths[i] = queues[i]->count();
    } 
}
int Radix::midValue()
{
	return numbers[length/2];
}