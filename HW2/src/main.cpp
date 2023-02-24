/**
* @file main.cpp
* @description txtler burada okunur. Siniflar bu dosyada olusturulur ve fonksiyonlari cagrilir. program bitimine heap temizlenir.
* @course Veri Yapilari 1/C
* @assignment 2
* @date 08.12.2022
* @author İlyas Aydın ilyas.aydin1@ogr.sakarya.edu.tr
*/
#include <iostream>
#include <fstream>
#include<sstream>
#include "Kontrol.hpp"
#include <iomanip>

int main()
{
	std::ifstream Oku("./doc/veri.txt");
	std::string a;
	Organizma *organizma = new Organizma();
	Sistem* sistem = new Sistem();
	Organ* organ = new Organ();
	if (Oku.is_open())
	{
		while (getline(Oku, a))
		{			Doku *doku = new Doku();
			std::istringstream iss(a);
			std::string strnum;
			while (getline(iss, strnum, ' ')) {
				int value = std::stoi(strnum);
				doku->add(new Hucre(value));
			}
			doku->setMidValue();
			organ->add(doku);
			if (organ->getSize()==20)
			{
				sistem->add(organ);
				if (sistem->getSize() == 100)
				{
					organizma->add(sistem);
					sistem = new Sistem();
				}
				organ = new Organ();
			}
		}
	}
	if(organizma->getSize()==0)
	{
		delete organizma;
		delete sistem;
		delete organ;
		if(!Oku.is_open())
		{
			std::cout<<"veri.txt dosyasi bulunamadi! Lutfen doc klasorunu kontrol ediniz.";	
		}
		else{
			std::cout<<"veri.txt dosyasinda organizma bulunamadi. Lutfen dosyayi kontrol ediniz.";
		}
		return 0;
	}
	Oku.close();
	delete sistem;
	delete organ;
	std::cout << std::setw(30) << " " << "ORGANIZMA" << std::endl;
	organizma->print();
	std::cin.ignore();
	Kontrol *kontrol = new Kontrol();
	kontrol->Mutasyon(organizma);
	delete kontrol;
	system("cls");
	std::cout << std::setw(30) << " " << "ORGANIZMA (MUTASYONA UGRADI)" << std::endl;
	organizma->print();
	delete organizma;
	
	return 0;
	


}
