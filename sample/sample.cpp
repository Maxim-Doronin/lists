#include "list.h"
#include <cstdlib>
#include <iostream>
#include <ctime>

int main()
{
	NODE *list = new NODE;
	NODE *tmp = list;
	srand(time(0));
	for(int i=0; i<10; i++)
	{
		tmp->key = 50 - rand()%100;
		std::cout << tmp->key << " ";
		tmp->pNext = new NODE;
		tmp = tmp->pNext;
	}
	tmp->pNext = 0;
	
	
	NODE *even = new NODE;
	NODE *odd = new NODE;

	EvenOdd(list, odd, even);

	std::cout << "\n";

	while (even != 0)
	{
		std::cout << even->key<< " ";
		even = even->pNext;
	}

	std::cout << "\n";

	while (odd != 0)
	{
		std::cout << odd->key<< " ";
		odd = odd->pNext;
	}

	std::cout << "\n";

	return 0;
}