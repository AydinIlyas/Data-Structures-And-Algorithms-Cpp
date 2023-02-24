/**
* @file Doku.cpp
* @description Hucreler doku sinifinda double pointer yardimiyla  dinamik dizide tutulur. Ikili arama agacinin nodeudur ayni zamanda.
* @course Veri Yapilari 1/C
* @assignment 2
* @date 08.12.2022
* @author İlyas Aydın ilyas.aydin1@ogr.sakarya.edu.tr
*/
#include "Doku.hpp"
#include<iostream>
#include"Radix.hpp"

Doku::Doku()
{
	capacity = 15;
	size = 0;
	midValue = 0;
	right=NULL;
	left=NULL;
	hucreler = new Hucre*[capacity];
}
Hucre* Doku::getHucre(int index)
{
	return hucreler[index];
}
void Doku::genislet()
{
	capacity += 5;
	Hucre** tmp=new Hucre*[capacity];
	for (int i = 0; i < size; i++)
	{
		tmp[i] = hucreler[i];
	}
	delete []hucreler;
	hucreler = tmp;
	

}
int Doku::getSize()
{
	return size;
}
Doku* Doku::getLeft()
{
	return left;
}
Doku* Doku::getRight()
{
	return right;
}
void Doku:: setRight(Doku* node)
{
	right = node;
}
void Doku::setLeft(Doku* node)
{
	left = node;
}
void Doku::add(Hucre* hucre)
{
	if(size==capacity)
	{
		genislet();
	}
	hucreler[size] = hucre;
	size++;
}
void Doku::setMidValue()
{
	Radix* rdx = new Radix(this,size);
	rdx->sort();		
	this->midValue = rdx->midValue();
	delete rdx;
}
int Doku::getMidValue()
{
	return midValue;
}
void Doku::Mutasyon()
{

	for(int i=0;i<size;i++)
	{
		hucreler[i]->Mutasyon();
	}
	Radix* rdx=new Radix(this,size);
	rdx->sort();
	midValue=rdx->midValue();
	delete rdx;

}
Doku::~Doku()
{
	for (int i = 0; i < size; i++)
	{
		delete hucreler[i];
	}
	delete[] hucreler;
}
