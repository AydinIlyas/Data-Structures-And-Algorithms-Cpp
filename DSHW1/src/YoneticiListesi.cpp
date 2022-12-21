#include "YoneticiListesi.hpp"
#include <iomanip>
YoneticiListesi::YoneticiListesi()
{
    this->list_head = NULL;
    this->list_tail = NULL;
    this->curr = NULL;
    this->nodeIndex = 0;
    this->page = 1;
    this->size = 0;
}

void YoneticiListesi::addFront(ListNode* node)
{
    list_head->before=node;
    node->next = list_head;
    list_head = node;
    curr = list_head;
    size++;
}

void YoneticiListesi::addLast(ListNode* node)
{
    list_tail->next = node;
    node->before = list_tail;
    list_tail = node;
    node->next = NULL;
    size++;
}

void YoneticiListesi::addSorted(SatirListesi* list)
{
    ListNode* node = new ListNode(list);
    float avg = node->getList()->getAVG();
    ListNode *traverser = list_head;
    if (size == 0)
    {
        list_head = node;
        list_tail = node;
        size++;
        return;
    }
    if (traverser->getList()->getAVG() > avg)
    {
        addFront(node);
        return;
    }
    while (traverser != NULL)
    {
        if (traverser->getList()->getAVG() > avg)
        {
            node->next = traverser;
            traverser->before->next = node;
            node->before = traverser->before;
            traverser->before = node;
            size++;
            return;
        }
        traverser = traverser->next;
    }
    addLast(node);
    
}

ListNode* YoneticiListesi::get()
{
    return list_head;
}

int YoneticiListesi::getSize()
{
    return this->size;
}

void YoneticiListesi::deleteListNode()
{
    ListNode* founder = curr;
    if (size == 1)
    {
        delete founder;
    }
    else if (founder == list_head)
    {
        ListNode* deleted = curr;
        curr = curr->next;
        founder = founder->next;
        founder->before = NULL;
        delete deleted;
        list_head = founder;
    }
    else if (founder == list_tail)
    {
        ListNode* deleted = curr;
        if (nodeIndex % 8 == 0 && nodeIndex == size - 1)
        {
            if(nodeIndex>0)
            {
                curr=curr->before;
                nodeIndex--;
                page--;
            }
        }
        else {
            curr = curr->before;
            nodeIndex--;
        }
        deleted->before->next = NULL;
        list_tail = deleted->before;
        delete deleted;
    }
    else {
        curr = curr->next;
        ListNode* deleted = founder;
        founder = founder->next;
        founder->before = founder->before->before;
        founder->before->next = founder;
        delete deleted;
    }
    size--;
    
   
    
}

void YoneticiListesi::deleteRandomNode(int random)
{
    ListNode* node = curr;
    SatirListesi* list = node->getList();
    if (list->length() == 1)
    {
        deleteListNode();
        if (nodeIndex >= size && nodeIndex > 0)
        {
            nodeIndex--;
        }
        return;
    }
    list->deleteNode(random);
    if (this->size == 1)
    {
        return;
    }

    //dogru yerde mi kontrol
    float avg = node->getList()->getAVG();
    if (nodeIndex != 0 && nodeIndex != size - 1)
    {
        if (node->before->getList()->getAVG() <= avg && node->next->getList()->getAVG() >= avg)
        {
            return;
        }
    }
    if (nodeIndex == 0 && node->next->getList()->getAVG() >= avg)
    {
        return;
    }
    if (nodeIndex == size - 1 && node->before->getList()->getAVG() <= avg)
    {
        return;
    }

    //yerinde degilse listeden cikartma
    if (node == list_head)
    {
        node->next->before = NULL;
        list_head = node->next;
    }
    else if (node == list_tail)
    {
        node->before->next = NULL;
        list_tail = node->before;
    }
    else {
        node->before->next = node->next;
        node->next->before = node->before;
    }

    //yerlestirme
    SatirListesi* listHead = list_head->getList();
    if (list_head->getList()->getAVG() >= avg)
    {
        curr=curr->before;
        list_head->before = node;
        node->before = NULL;
        node->next = list_head;
        list_head = node;
        return;
    }
    if (list_tail->getList()->getAVG() <= avg)
    {
        curr=curr->next;
        list_tail->next = node;
        node->before = list_tail;
        node->next = NULL;
        list_tail = node;
        return;
    }
    ListNode* iterator = node;
    if (iterator->next != NULL && avg >= iterator->next->getList()->getAVG())
    {
        if(nodeIndex!=size-1)
        curr=curr->next;
        iterator = iterator->next;
        while (avg > iterator->getList()->getAVG() && iterator != NULL)
        {
            iterator = iterator->next;
        }
    }

    else if (iterator->before != NULL && avg <= iterator->before->getList()->getAVG())
    {
        if(nodeIndex!=0)
        curr=curr->before;
        while (avg < iterator->before->getList()->getAVG() && iterator != NULL)
        {
            iterator = iterator->before;
        }
    }
    ListNode* previous = iterator->before;
    if (previous != NULL)
        previous->next = node;
    node->before = previous;
    if (node != iterator)
    {
        node->next = iterator;
        iterator->before = node;
    }
}

void YoneticiListesi::setPage(char ch)
{
    float pageAmount = (float)size / 8;
    if (ch == 'd'&&page<pageAmount)
    {
        page++;
        int count = nodeIndex+ 8;
        count = 8 - count % 8;
        while (count>0)
        {
            curr = curr->next;
            nodeIndex++;
            count--;
        }
    }
    else if(ch=='a'&&page>1&&size>0) {
        page--;
        int count = nodeIndex-8;
        count = 8 + count % 8;
        while (count > 0) 
        {
            curr = curr->before;
            nodeIndex--;
            count--;
        } 
    }
}

std::string duzcizgi(int amount)
{
    std::string text = "";
    for (int i = 0; i < amount; i++)
    {
        text+="  -----------";
    }
    text+="\n";
    return text;
}

int* YoneticiListesi::getIndex()
{
    return &nodeIndex;
}

ListNode* YoneticiListesi::getCurr()
{
    return curr;
}

void YoneticiListesi::manageCurr(char input)
{
    if (input == 'z')
    {
        if(nodeIndex % 8 != 0)
        {
            nodeIndex--;
            curr = curr->before;
            
        }
        else
        {
            if(page>1&&size>0)
            {
                page--;
                curr=curr->before;
                nodeIndex--;
            }   
        }
    }
    else if (input == 'c' && nodeIndex < size - 1)
    {
        if(nodeIndex % 8 != 7)
        {
            nodeIndex++;
            curr = curr->next;
            
        }
        else
        {
            setPage('d');
        }
    }
}

std::ostream& operator<<(std::ostream& os, YoneticiListesi& list)
{
    int testIndex = list.nodeIndex;
    int pageNum = testIndex / 8;
    os << std::setw(5) << (int)pageNum + 1 << ".Page";
    if ((list.getSize() - 1) / 8 >= (testIndex + 8)/ 8)
    {
        os << std::setw(94) << "Next-->";
    }
    if (list.size==0)
    {
        return os;
    }
    os << "\n\n";
    ListNode* iterator = list.curr;
    int beginIndex = list.nodeIndex;
    while (beginIndex % 8 != 0)
    {
        iterator = iterator->before;
        beginIndex--;
    }
    ListNode* node = iterator;
    int index = 1;
    while (iterator != NULL&&index<=8)
    {
        os << std::setw(3) << " " << std::left <<std::setw(9)<< iterator << " ";
        index++;
        iterator = iterator->next;
    }
    os << std::endl;
    os<<duzcizgi(index-1);
    iterator = node;
    index = 1;
    
    while (iterator != NULL &&index<=8)
    {
        os <<std::setw(2)<<" "<< "|" <<std::setw(9)<< iterator->before << "|";
        index++;
        iterator = iterator->next;
    }
    os << std::endl;
    os<<duzcizgi(index-1);
    iterator = node;
    index = 1;
    while (iterator != NULL && index <= 8)
    {
        os <<std::setw(2)<<"  |"<<std::setw(9)<<std::right<< std::fixed << std::setprecision(2) << iterator->getList()->getAVG() <<std::right << '|';
        index++;
        iterator = iterator->next;
    }
    os << std::endl;
    os<<duzcizgi(index-1);
    iterator = node;
    index = 1;
    while (iterator != NULL && index <= 8)
    {
        os <<std::setw(2)<<"  |"<<std::setw(9)<< std::fixed << std::setprecision(2) << iterator->next<<std::right << '|';
        index++;
        iterator = iterator->next;
    }
    os << std::endl;
    os<<duzcizgi(index-1);
    os<<std::endl;

    SatirListesi* doublyList = list.curr->getList();
    doublyList->updateIndex(list.nodeIndex);
    os << *doublyList;
    return os;
}

YoneticiListesi::~YoneticiListesi() {

}







