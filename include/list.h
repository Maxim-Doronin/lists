#pragma once

struct NODE
{
	int key;
	NODE *pNext;
};

int negativeInPlace(NODE *&pFirst);
NODE* negativeCopy(NODE *&pFirstSourse);
void EvenOdd(NODE *&pFirst, NODE *&pFirstOdd, NODE *&pFirstEven);