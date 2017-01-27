// demo_list.cpp

#include "list.h"
#include <iostream>

using namespace std;

int main()
{
	List <int> list;
	cout << list.getSize() << endl;
	list.add(15);
	list.add(5616);
	list.add(516,1);
	cout << list.getSize() << endl;
	cout << list[0] << "    " << list[1] << "    " << list[2];
	return 0;
}