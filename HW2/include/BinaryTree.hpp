#ifndef BinaryTree_hpp
#define BinaryTree_hpp
#include "Doku.hpp"
class BinaryTree
{
private:
	Doku* root;
	bool AvlCheck(Doku* node);
	int height(Doku* t);
	void DestroyRecursive(Doku* node);
public:
	bool deleteAll;
	BinaryTree();
	void insert(Doku* newDoku);
	bool AvlCheck();
	Doku* getRoot();
	~BinaryTree();
	
};
#endif
