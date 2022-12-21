#ifndef Node_hpp
#define Node_hpp
class Node
{
private:

	int value;
public:
	Node* next;
	Node* before;
	Node(int value);
	int getValue();
};
#endif
