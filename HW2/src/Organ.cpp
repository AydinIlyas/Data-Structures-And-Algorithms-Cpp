/**
* @file Organ.cpp
* @description Dokular bu sinifin icindeki Ikili Arama agacinda tutulur. Eklerken dokunun ortanca degerine gore eklenir.
* @course Veri Yapilari 1/C
* @assignment 2
* @date 08.12.2022
* @author İlyas Aydın ilyas.aydin1@ogr.sakarya.edu.tr
*/
#include "Organ.hpp"
Organ::Organ()
{
	tree = new BinaryTree();
	size = 0;
	mutasyonIndex=0;
}
void Organ::add(Doku* doku)
{
	tree->insert(doku);
	size++;
}

bool Organ::AvlCheck()
{
	return tree->AvlCheck();
}

int Organ::getSize()
{
	return size;
}

Doku* Organ::getRoot()
{
	return tree->getRoot();
}
void Organ::Mutasyon()
{
	if(getRoot()->getMidValue()%50==0)
	{
		BinaryTree* newTree=new BinaryTree();
		Doku** newDokular=new Doku*[20];
		Mutasyon(getRoot(),newTree,newDokular,mutasyonIndex);
		for(int i=0;i<20;i++)
		{
			newDokular[i]->setLeft(0);
			newDokular[i]->setRight(0);
			newTree->insert(newDokular[i]);
		}
		mutasyonIndex=0;
		tree->deleteAll=false;
		delete tree;
		delete[] newDokular;
		tree=newTree;
	}
}
void Organ::Mutasyon(Doku* doku,BinaryTree* newTree,Doku** newDokular,int index)
{
	if (doku == NULL)
	{
		return;
	}
	
	Mutasyon(doku->getLeft(),newTree,newDokular,mutasyonIndex);
	Mutasyon(doku->getRight(),newTree,newDokular,mutasyonIndex);
	doku->Mutasyon();
	newDokular[mutasyonIndex]=doku;
	mutasyonIndex++;
}

Organ::~Organ()
{
	delete tree;
}

