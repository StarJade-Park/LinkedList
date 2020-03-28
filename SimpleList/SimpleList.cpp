#include <iostream>

#include "List.h"

int main( )
{
	List<float> list;

	list.insertBack(1.1F);
	list.insertBack(1.3F);
	list.insertBack(5.0F);
	list.insertBack(7.6F);
	list.insertBack(9.9F);

	list.insertFront(100.1F);
	list.insertFront(100.2F);
	list.insertFront(100.3F);
	list.insertFront(100.4F);
	list.insertFront(100.5F);

	list.printElements( );
	
	list.removeBack( );
	list.removeFront( );
	list.printElements( );

	Node<float> node;

	bool result = list.search(5.0F, &node);
	result = list.search(5.0F, &node);

	return 0;
}
