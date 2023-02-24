#ifndef Organizma_hpp
#define Organizma_hpp
#include "Sistem.hpp"
class Organizma
{
private:
	int size;
	int capacity;
	Sistem** sistemler;
public:
	Organizma();
	void expand();
	void Mutasyon();
	void add(Sistem* sistem);
	int getSize();
	void print();
	~Organizma();
};
#endif

