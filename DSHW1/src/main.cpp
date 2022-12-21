#include <iostream>
#include "YoneticiListesi.hpp"
#include<fstream>
#include<sstream>
#include<string>

int main()
{
	std::ifstream Oku("veriler.txt");
	std::string a;
	YoneticiListesi* yoneticilist = new YoneticiListesi();
	if(Oku.is_open())
	while (getline(Oku, a))
	{
		SatirListesi *satirlist = new SatirListesi();
		std::istringstream iss(a);
		std::string strnum;
		int sum=0;
		while (getline(iss, strnum, ' ')) {
			int value=std::stoi(strnum);
			satirlist->addLast(value);
			sum+=value;
		}
		satirlist->calculateAverage(sum);
		yoneticilist->addSorted(satirlist);
	}
	else
	{
		std::cout<<"veriler.txt diye bir dosya yok!";
		return 0;
	}
	if(yoneticilist->getSize()==0)
	{
		std::cout<<"veriler.txt dosyasi bos!";
		return 0;
	}
	Oku.close();
	int* index = yoneticilist->getIndex();
	while (true)
	{
		system("cls");
		std::cout << *yoneticilist;
		char ch;
		std::cin >> ch;
		if (ch == 'z')
		{
			yoneticilist->manageCurr('z');
		}
		else if (ch == 'c')
		{
			yoneticilist->manageCurr('c');
		}
		else if (ch == 'd')
		{
			yoneticilist->setPage('d');
		}
		else if (ch == 'a')
		{
			yoneticilist->setPage('a');
		}
		else if (ch == 'p')
		{
			yoneticilist->deleteListNode();

		}
		else if (ch == 'k')
		{
			int random=yoneticilist->getCurr()->getList()->generateRandom();
			system("cls");
			std::cout<<*yoneticilist;
			char dogrulama;
			std::cin >> dogrulama;
			if(dogrulama=='k')
			yoneticilist->deleteRandomNode(random);
			
			
		}
		if (yoneticilist->getSize() == 0)
		{
			system("cls");
			delete yoneticilist;
			break;

		}

	}
	return 0;

}

