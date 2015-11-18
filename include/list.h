#pragma once

struct NODE
{
	int key;
	NODE *pNext;
};

void negativeInPlace(NODE *&pFirst);
NODE* negativeCopy(NODE *&pFirstSourse);
void EvenOdd(NODE *&pFirst, NODE *&pFirstOdd, NODE *&pFirstEven);