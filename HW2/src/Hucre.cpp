/**
* @file Hucre.cpp
* @description Hucrelerin gorevi sayiyi(Dna uzunlugunu) icinde barindirmak. 
* @course Veri Yapilari 1/C
* @assignment 2
* @date 08.12.2022
* @author İlyas Aydın ilyas.aydin1@ogr.sakarya.edu.tr
*/
#include "Hucre.hpp"
Hucre::Hucre(int num)
{
	value = num;
}
int Hucre::getValue()
{
	return value;
}
Hucre::~Hucre()
{
}
void Hucre::Mutasyon()
{
	if(value%2==0)
	{
		value/=2;
	}

}
