#ifndef YoneticiListesi_hpp
#define YoneticiListesi_hpp
#include "ListNode.hpp"
#include<iostream>
class YoneticiListesi
{
public:
    void addFront(ListNode* list);
    void addLast(ListNode* list);
    void addSorted(SatirListesi* list);
    void deleteListNode();
    void deleteRandomNode(int random);
    ListNode* get();
    YoneticiListesi();
    int getSize();
    void setPage(char ch);
    ~YoneticiListesi();
    void manageCurr(char input);
    int* getIndex();
    ListNode* getCurr();  
    friend std::ostream& operator << (std::ostream& os, YoneticiListesi& list);
private:
    int nodeIndex;
    ListNode* curr;
    int page;
    int size;
    ListNode* list_head;
    ListNode* list_tail;
};
#endif

