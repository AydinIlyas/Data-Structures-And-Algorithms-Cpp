#ifndef Doku_hpp
#define Doku_hpp
#include "Hucre.hpp"
#include <cstddef>
class Doku
{
private:
	Doku* left;
	Doku* right;
	int size;
	int capacity;
	int midValue;
	Hucre** hucreler;
	void genislet();
public:
	Hucre* getHucre(int index);
	void setMidValue();
	int getMidValue();
	Doku();
	int getSize();
	Doku* getLeft();
	Doku* getRight();
	void setRight(Doku* node);
	void setLeft(Doku* node);
	void add(Hucre* hucre);
	void Mutasyon();
	~Doku();
};
#endif

