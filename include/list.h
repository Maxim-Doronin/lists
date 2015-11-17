#pragma once

struct NODE
{
	int key;
	NODE *pNext;
};

int negativeInPlace(NODE *&pFirst);
NODE* negativeCopy(NODE *&pFirstSourse);