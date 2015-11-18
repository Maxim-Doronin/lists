#include "list.h"
#include <cstdlib>
#include <iostream>
#include <ctime>

int main()
{
	NODE *list = new NODE;
	NODE *tmp = list;
	srand(time(0));
	for(int i=0; i<5; i++)
	{
		tmp->key = 50 - rand()%100;
		std::cout << tmp->key << " ";
		tmp->pNext = new NODE;
		tmp = tmp->pNext;
	}
	tmp->pNext = 0;
	
	
	NODE *even = 0;
	NODE *odd = 0;

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