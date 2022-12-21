#include "SatirListesi.hpp"
#include <iomanip>
SatirListesi::SatirListesi()
{
    this->okIndex = -1;
    this->ok = false;
    this->index = 0;
    this->size = 0;
    this->head = NULL;
    this->tail = NULL;
    this->average = 0;
}
void SatirListesi::addFront(int value)
{
    Node* node = new Node(value);
    node->next = head;
    if (size == 0)
    {
        tail = node;
        head = node;
    }
    else {
        head->before = node;
    }
    head = node;
    size++;
}

void SatirListesi::addLast(int value)
{
    Node* node = new Node(value);
    node->before = tail;
    if (size == 0)
    {
        head = node;
        tail = node;
    }
    else {
        tail->next = node;
    }

    tail = node;
    size++;
}

Node* SatirListesi::getHead()
{
    return head;
}


int SatirListesi::length()
{
    return size;
}

float SatirListesi::getAVG()
{
    return average;
}
void SatirListesi::calculateAverage(int sum)
{
    average = (float)sum / size;
}
bool SatirListesi::deleteNode(int index)
{
    float sum=average*size;
    Node* founder = head;
    if (index == 0)
    {
        Node* deleted = founder;
        sum = sum - founder->getValue();
        founder = founder->next;
        founder->before = NULL;
        delete deleted;
        head = founder;
        size--;
        average =sum / size;
        return true;
    }
    if (index == size - 1)
    {
        Node* founder = tail;
        sum = sum - founder->getValue();
        founder->before->next = NULL;
        tail = founder->before;
        delete founder;
        size--;
        average =sum / size;
        return true;
    }
    for (int i = 0; i < index; i++)
    {
        founder = founder->next;
    }
    Node* deleted = founder;
    sum = sum - founder->getValue();
    founder = founder->next;
    founder->before = founder->before->before;
    founder->before->next = founder;
    delete deleted;
    size--;
    average =sum / size;
    return true;
}

SatirListesi::~SatirListesi()
{
}

void SatirListesi::updateIndex(int index)
{
    this->index = index;
}

int SatirListesi::generateRandom()
{
    okIndex=rand() %size;
    ok = true;
    return okIndex;
}
std::ostream& operator << (std::ostream& os, SatirListesi& list)
{
    Node* kafa = list.getHead();
    os << std::setw(list.index % 8 * 13 + 13) << std::right << "^^^^^^^^^^^" << std::endl;
    int counter = 0;
    while (kafa != NULL)
    {
        int space = 4;
        os << std::setw(list.index % 8 * 13 + 3) << std::right << " " << std::setw(9) << kafa;
        os << "\n" << std::setw(list.index % 8 * 13) << "";
        os << "  -----------\n";
        os << std::setw(list.index % 8 * 13 + 3) << std::right << "|" << std::setw(9) << kafa->getValue() << '|';
        if (list.ok && counter == list.okIndex)
        {
            os << "<----------- Silmek istediginden emin misin?";
        }
        os << "\n" << std::setw(list.index % 8 * 13) << "";
        os << "  -----------\n";
        os << std::setw(list.index % 8 * 13 + 3) << std::right << "|" << std::setw(9) << kafa->next << std::right << "|";
        os << "\n" << std::setw(list.index % 8 * 13) << "";
        os << "  -----------\n";
        os << std::endl;
        kafa = kafa->next;
        counter++;
    }
    list.ok = false;
    return os;
}
