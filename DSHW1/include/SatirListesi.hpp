#ifndef SatirListesi_hpp
#define SatirListesi_hpp
#include "Node.hpp"
#include<iostream>
class SatirListesi
{
public:
    SatirListesi();
    void addFront(int value);
    void addLast(int value);
    int length();
    Node* getHead();
    void calculateAverage(int sum);
    float getAVG();
    bool deleteNode(int index);
    ~SatirListesi();
    void updateIndex(int index);
    int generateRandom();
    friend std::ostream& operator << (std::ostream& os, SatirListesi& node);

private:
    int okIndex;
    bool ok;
    int index;
    int size;
    Node* head;
    Node* tail;
    float average;


};

#endif
