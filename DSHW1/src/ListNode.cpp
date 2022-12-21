#include "ListNode.hpp"
#include<stdio.h>
ListNode::ListNode(SatirListesi* adres)
{
    this->adres = adres;
    this->next = NULL;
    this->before = NULL;
}
ListNode::ListNode()
{
    this->next = NULL;
    this->before = NULL;
}
SatirListesi* ListNode::getList()
{
    return adres;
}
ListNode::~ListNode()
{
    Node* deleter = this->adres->getHead();
    SatirListesi* list = this->adres;
    if (deleter != NULL)
    {

        while (deleter != NULL)
        {
            Node* sil = deleter;
            deleter = deleter->next;
            Node* test = sil;
            delete sil;
        }
        delete list;
    }
}