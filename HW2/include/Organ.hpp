#ifndef Organ_hpp
#define Organ_hpp
#include "BinaryTree.hpp"
class Organ
{
private:
	int size;
	BinaryTree* tree;
	int mutasyonIndex;
public:
	Organ();
	void add(Doku *doku);
	bool AvlCheck();
	int getSize();
	Doku* getRoot();
	void Mutasyon();
	void Mutasyon(Doku* doku,BinaryTree* newTree,Doku** newDokular,int index);
	~Organ();
};
#endif

