/**
* @file Organizma.cpp
* @description icinde dinamik bir sistem dizisi barindirir. sistemler buradan ekrana yazdirilir.
* @course Veri Yapilari 1/C
* @assignment 2
* @date 08.12.2022
* @author İlyas Aydın ilyas.aydin1@ogr.sakarya.edu.tr
*/
#include "Organizma.hpp"
#include <iostream>
Organizma::Organizma()
{
	size = 0;
	capacity = 16;
	sistemler = new Sistem * [capacity];
}
void Organizma::expand()
{
	capacity += 5;
	Sistem** tmp=new Sistem*[capacity];
	for (int i = 0; i < size; i++)
	{
		tmp[i] = sistemler[i];
	}
	delete []sistemler;
	sistemler = tmp;
	

}
void Organizma::Mutasyon()
{
	for(int i=0;i<size;i++)
	{
		sistemler[i]->Mutasyon();
	}
}
void Organizma::add(Sistem* sistem)
{
	if(size==capacity)
	{
		expand();
	}
	sistemler[size] = sistem;
	size++;
}

int Organizma::getSize()
{
	return size;
}

void Organizma::print()
{
	for (int i = 0; i < size; i++)
	{
		sistemler[i]->print();
		std::cout<<std::endl;
	}
}

Organizma::~Organizma()
{
	for (int i = 0; i < size; i++)
	{
		delete sistemler[i];
	}
	delete[] sistemler;
}

