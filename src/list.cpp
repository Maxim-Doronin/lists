#include "list.h"

void negative(NODE *&pFirst) //Надо вернуть int - количество элементов 
{
	if(pFirst == 0) return;
	while(pFirst->key > 0)
	{
		pFirst = pFirst->pNext;
	}
	NODE *res = pFirst;
	while (res->pNext != 0)
	{
		NODE *tmp = res;
		while((tmp->pNext != 0)&&(tmp->pNext->key > 0))
		{
			tmp = tmp->pNext;
		}
		if (tmp->key > 0)
		{
			res->pNext = tmp->pNext;
		}
		res = res->pNext;
		
	}
}