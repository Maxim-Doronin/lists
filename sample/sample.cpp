#include "list.h"
#include <cstdlib>
#include <iostream>
#include <ctime>

int main()
{
	NODE *l1 = new NODE;
	NODE *tmp = l1;
	srand(time(0));
	for(int i=0; i<10; i++)
	{
		tmp->key = 50 - rand()%100;
		std::cout << tmp->key << " ";
		tmp->pNext = new NODE;
		tmp = tmp->pNext;
	}
	tmp->pNext = 0;
	/*tmp = l1;
	std::cout<< "\n";
	

	int count = negativeInPlace(tmp);
	while (tmp != 0)
	{
		std::cout << tmp->key << " ";
		tmp = tmp->pNext;
	}
	*/
	tmp = l1;
	std::cout<< "\n";

	NODE* copy;
	copy = negativeCopy(tmp);
	while (copy != NULL)
	{
		std::cout << copy->key << " ";
		copy = copy->pNext;
	}

	return 0;
}