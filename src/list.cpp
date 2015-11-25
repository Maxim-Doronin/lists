#include "list.h"

/*
NODE* negativeCopy(NODE *&pFirstSourse)
{
	NODE* tmpSourse = pFirstSourse;

	if (tmpSourse == 0) return 0;
	while ((tmpSourse->pNext != 0)&&(tmpSourse->key >= 0))
	{
		tmpSourse = tmpSourse->pNext;
	}

	NODE* pFirstCopy = new NODE;
	NODE* tmpCopy = pFirstCopy;

	if (tmpSourse->key < 0)
	{
		tmpCopy->key = tmpSourse->key;
		tmpCopy->pNext = new NODE;
		tmpCopy = tmpCopy->pNext;
	}

	while (tmpSourse->pNext != 0)
	{
		tmpSourse = tmpSourse->pNext;
		if (tmpSourse->key < 0)
		{	
			tmpCopy->key = tmpSourse->key;
			tmpCopy->pNext = new NODE;
			tmpCopy = tmpCopy->pNext;
		}
	}
	
	tmpCopy = pFirstCopy;


	return tmpCopy;
}*/


List::List(int count)
{
	if (count == 0)
	{
		pFirst = 0;
		return;
	}
	pFirst = new NODE;
	NODE *tmp = pFirst;
	srand(time(0));
	tmp->key = 50 - rand()%100;

	for(int i=1; i<count; i++)
	{
		tmp->pNext = new NODE;
		tmp = tmp->pNext;
		tmp->key = 50 - rand()%100;
	}
	tmp->pNext = 0;
}

List::~List()
{
	NODE *tmp = pFirst;
	while (pFirst != 0)
	{
		pFirst = pFirst->pNext;
		delete tmp;
		tmp = pFirst;
	}
}

void List::print()
{
	if (pFirst == 0)
	{
		std::cout << "No members" << std::endl;
		return;
	}
	NODE *tmp = pFirst;
	while(tmp != 0)
	{
		std::cout << tmp->key << " ";
		tmp = tmp->pNext;
	}
	std::cout << std::endl;
}

NODE* List::find(int key)
{
	if (pFirst == 0) return 0;
	NODE *tmp = pFirst;
	while((tmp != 0)&&(tmp->key != key))
		tmp = tmp->pNext;
	if (tmp->key != key) return 0;
	return tmp;
}

int List::findPrev(int key, NODE *&point, NODE *&pPrev)
{
	if(pFirst == 0) return 0;
	pPrev = 0;
	point = pFirst;
	while ((point != 0)&&(point->key != key))
	{
		pPrev = point;
		point = point->pNext;
	}
	if (point->key != key)
	{
		point = 0;
		pPrev = 0;
		return 0;
	}
	return 1;
}

int List::getFirst() const
{
	return pFirst->key;
}

void List::insertionFirst(int key)
{
	NODE *tmp = new NODE;
	tmp->key = key;
	tmp->pNext = pFirst;
	pFirst = tmp;
}

void List::insertionEnd(int key)
{
	if (pFirst == 0) 
	{
		insertionFirst(key);
		pFirst->pNext = 0;
		return;
	}
	NODE *tmp = pFirst;
	while(tmp->pNext != 0)
		tmp = tmp->pNext;
	tmp->pNext = new NODE;
	tmp->pNext->key = key;
	tmp->pNext->pNext = 0;
}

void List::insertionPrev(int key, NODE *&elem)
{
	NODE *pPrev;
	NODE *point;
	int code = findPrev(key, point, pPrev);
	if (!code) return;
	elem->pNext = point;
	if (pPrev == 0)
	{
		pFirst = elem;
		return;
	}
	pPrev->pNext = elem;
}

void List::insertionNext(int key, NODE *&elem)
{
	NODE *point = find(key);
	if (point == 0) return;
	elem->pNext = point->pNext;
	point->pNext = elem;
}

void List::insertionNext(NODE *elem, NODE *&newElem)
{
	NODE *tmp = pFirst;
	while ((tmp != 0)&&(tmp != elem))
		tmp = tmp->pNext;
	if (tmp == elem)
	{
		newElem->pNext = elem->pNext;
		elem->pNext = newElem;
	}
}

int List::del(int key)
{
	NODE *point;
	NODE *pPrev;
	int code = findPrev(key, point, pPrev);
	if (!code) return 0;
	if (pPrev == 0)
	{
		pFirst = pFirst->pNext;
		delete point;
		return 1;
	}
	pPrev->pNext = point->pNext;
	delete point;
	return 1;
}

int List::del(NODE *elem)
{
	NODE *point = pFirst;
	NODE *pPrev = 0;
	while ((point != 0)&&(point != elem))
	{
		pPrev = point;
		point = point->pNext;
	}
	if (point != elem) return 0;
	if (pPrev == 0)
	{
		pFirst = pFirst->pNext;
		delete point;
		return 1;
	}
	pPrev->pNext = point->pNext;
	delete point;
	return 1;
}

void List::negativeInPlace()
{
	if (pFirst == 0) return;
	NODE *pPrev = 0;
	while ((pFirst != 0)&&(pFirst->key >= 0))
	{
		pPrev = pFirst;
		pFirst = pFirst->pNext;
		delete(pPrev);
	}
	NODE *tmp = pFirst;
	pPrev = pFirst;
	while(tmp != 0)
	{
		if (tmp->key >= 0) 
		{
			del(tmp);
			tmp = pPrev;
		}
		pPrev = tmp;
		tmp = tmp->pNext;
	}
}

List* List::negativeCopy()
{
	List* pCopy;
	return pCopy;
}

void List::EvenOdd(List *&pFirstOdd, List *&pFirstEven)
{
}

void List::sort()
{
	NODE *min;
	NODE *startPoint = pFirst;
	NODE *tmp;

	while(startPoint != 0)
	{
		tmp = startPoint;
		min = startPoint;
		while (tmp != 0)
		{
			if (tmp->key < min->key) min = tmp;
			tmp = tmp->pNext;
		}
		if (startPoint == min)
		{
			startPoint = startPoint->pNext;
		}
		insertionFirst(min->key);
		del(min);
	}
}

void List::replaceList(List *&list1, List *&list2)
{
	if (list1 == 0) return;
	
	NODE *start = pFirst;
	NODE *tmp;
	NODE *prev = 0;
	NODE *tmp1 = list1->pFirst;
	NODE *tmp2;
	
	while (start != 0){
		if (start->key == tmp1->key)
		{
			tmp = start;
			while ((tmp1 != 0)&&(tmp != 0))		//проверка
			{
				if (tmp->key != tmp1->key) break;
				tmp = tmp->pNext;
				tmp1 = tmp1->pNext;
			}
			if (tmp1 == 0)						//замена
			{
				tmp = start;
				tmp1 = list1->pFirst;
				NODE* pPrev = 0;
				while ((tmp1 != 0)&&(tmp != 0))			//удаление
				{
					pPrev = tmp;
					tmp = tmp->pNext;
					tmp1 = tmp1->pNext;
					del(pPrev);
				}
				tmp2 = list2->pFirst;
				while(tmp2 != 0)						//вставка
				{
					NODE *newElem = new NODE;
					newElem->key = tmp2->key;
					insertionNext(prev, newElem);
					prev = prev->pNext;
					tmp2 = tmp2->pNext;
				}
				start = prev;
			}
			tmp1 = list1->pFirst;
		}
		prev = start;
		start = start->pNext;
	}
}
		