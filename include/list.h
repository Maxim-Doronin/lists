#pragma once
#include <cstdlib>
#include <iostream>
#include <ctime>

struct NODE
{
	int key;
	NODE *pNext;
};


class List {
private: 
	NODE* pFirst;
public:
	List(int count);
	~List();
	
	void print();
	NODE* find(int key);
	int findPrev(int key, NODE *&point, NODE *&pPrev);
	
	void insertionFirst(int key);
	void insertionEnd(int key);
	void insertionPrev(int key, NODE *&elem);
	void insertionNext(int key, NODE *&elem);

	int del(int key);
private:
	int del(NODE *elem);
public:
	void negativeInPlace();
	List* negativeCopy();
	void EvenOdd(List *&pFirstOdd, List *&pFirstEven);

	void sort();
};