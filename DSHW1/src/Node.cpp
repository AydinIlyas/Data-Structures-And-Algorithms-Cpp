#include "Node.hpp"
#include<stdio.h>
Node::Node(int value)
{
    this->value = value;
    this->next = NULL;
    this->before = NULL;
}
int Node::getValue()
{
    return this->value;
}