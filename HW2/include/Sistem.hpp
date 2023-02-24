#ifndef Sistem_hpp
#define Sistem_hpp
#include "Organ.hpp"
class Sistem
{
private:
	
	int size;
	int capacity;
	Organ** organlar;
public:
	Sistem();
	void add(Organ* organ);
	int getSize();
	void print();
	void Mutasyon();
	~Sistem();



};
#endif
