// demo_list.cpp

#include "list.h"
#include <iostream>

using namespace std;

int main()
{
	List <int> list;

	cout << "\n-- initial --\n";
	cout << "List size: " << list.getSize() << endl;

	list.add(15);
	list.add(13);
	list.add(516,1);
	cout << "\n-- adding three elements --\n";
	cout << "List: ";
	for(int i=0; i<=list.end(); i++)
	{
		cout << list.getData(i) << " ";
	}
	cout << endl;
	cout << "New list size: " << list.getSize() << endl;

	list.build(3);
	cout << "\n-- after using build --\n";
	cout << "List: ";
	for(int i=0; i<=list.end(); i++)
	{
		cout << list.getData(i) << " ";
	}
	cout << endl;
	cout << "New list size: " << list.getSize() << endl;

	return 0;
}
