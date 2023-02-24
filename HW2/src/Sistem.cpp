/**
* @file Sistem.cpp
* @description icinde bir organ dizisi barindirir.
* @course Veri Yapilari 1/C
* @assignment 2
* @date 08.12.2022
* @author İlyas Aydın ilyas.aydin1@ogr.sakarya.edu.tr
*/
#include "Sistem.hpp"
#include <iostream>

Sistem::Sistem()
{
	capacity = 100;
	size = 0;
	organlar = new Organ * [100];
}

void Sistem::add(Organ* organ)
{
	this->organlar[size] = organ;
	size++;
}

int Sistem::getSize()
{
	return size;
}

void Sistem::Mutasyon()
{
	for(int i=0;i<size;i++)
	{
		organlar[i]->Mutasyon();
	}
}
void Sistem::print()
{
	for(int i=0;i<size;i++)
	{
		if(organlar[i]->AvlCheck())
		{
			std::cout << " ";
		}
		else
		{
			std::cout << "#";
		}
	}
}
Sistem::~Sistem()
{
	for (int i = 0; i < size; i++)
	{
		delete organlar[i];
	}
	delete[] organlar;
}
