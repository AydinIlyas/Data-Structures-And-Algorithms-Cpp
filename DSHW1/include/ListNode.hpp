#ifndef ListNode_hpp
#define ListNode_hpp
#include"SatirListesi.hpp"
class ListNode
{
private:
	SatirListesi* adres;
public:
	ListNode();
	ListNode* next;
	ListNode* before;
	SatirListesi* getList();
	ListNode(SatirListesi* list);
	~ListNode();

};
#endif
