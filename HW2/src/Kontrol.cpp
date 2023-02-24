/**
* @file Kontrol.cpp
* @description Mutasyon bu sinif yardimiyla gerceklestirilir.
* @course Veri Yapilari 1/C
* @assignment 2
* @date 08.12.2022
* @author İlyas Aydın ilyas.aydin1@ogr.sakarya.edu.tr
*/
#include "Kontrol.hpp"
Kontrol::Kontrol()
{
}

void Kontrol::Mutasyon(Organizma* organizma)
{
	organizma->Mutasyon();
}
Kontrol::~Kontrol()
{
}
