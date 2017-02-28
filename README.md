#Data Structures#

The following data structures have been implemented:

##**list.h**##
A multi-purpose Linked list implementation.  

    - Useful for creating Linked lists  
    - Forms a basis for stacks, queues. A wrapper is all that is required.  
    - Optimized code

###DS Library 101:

Let's dive into the code rightaway.

	Let's initialize an empty list called _list_ :
		List <int> list;

	Let's add two numbers at the end of the list:
		list.add(15);
		list.add(13);

	We can also add numbers at a specific position:
		list.add(516,1);

	Now the list size can be inspected using list.getSize(). The following code will print the size of the list:
		cout << list.getSize();

