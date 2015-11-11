#include "list.h"
#include <cstdlib>
#include <iostream>
using namespace std;

int main()
{
	NODE *l1 = new NODE;
	NODE *tmp = l1;
	for(int i=0; i<10; i++)
	{
		tmp->key = rand()-RAND_MAX/2;
		cout << tmp->key << " ";
		tmp->pNext = new NODE;
		tmp = tmp->pNext;
	}
	tmp->pNext = 0;
	negative(l1);

	
	tmp = l1;
	for(int i=0; i<9; i++)
	{
		cout << tmp->key << " ";
		tmp = tmp->pNext;
	}

	


	return 0;
}