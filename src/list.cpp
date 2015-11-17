#include "list.h"

int  negativeInPlace(NODE *&pFirst) 
{
	int count = 0; //количство отриц. элементов 
	
	if (pFirst == 0) return count;
	while ((pFirst->pNext != 0)&&(pFirst->key > 0))
	{
		pFirst = pFirst->pNext;
	}
	NODE *res = pFirst;

	while (res->pNext != 0)
	{
		NODE *tmp = res;
		count++;
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
	
	return count;
}


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
}