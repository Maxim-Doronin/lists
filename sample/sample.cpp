#include "list.h"

int main()
{
	List list(0);
	list.insertionEnd(2);
	list.insertionEnd(10);
	list.insertionEnd(-2);
	list.insertionEnd(3);
	list.insertionEnd(5);

	List *list1 = new List(0);
	list1->insertionEnd(-2);
	list1->insertionEnd(3);

	List *list2 = new List(0);
	list2->insertionEnd(4);
	list2->insertionEnd(0);
	list2->insertionEnd(1);

	list.print();
	list1->print();
	list2->print();


	list.replaceList(list1, list2);
	list.print();
}