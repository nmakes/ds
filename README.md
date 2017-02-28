#Data Structures#

The following data structures have been implemented:

##**list.h**##
A multi-purpose Linked list implementation.  

    - Useful for creating Linked lists  
    - Forms a basis for stacks, queues. A wrapper is all that is required.  
    - Optimized code

###Crash Course:

The list indexing starts from 0. Initially, the list will have 0 elements and the head and the tail will point to null. 

Throughout the documentation, 'element' means a data element - the real data which is wrapped inside a node of the linked list.

Let's dive into the code rightaway. 

###Initialising the list:

First, let's initialize an empty list called _list_ :

	List <int> list;

All this did was created an empty linked list, whose head and tail pointers point to NULL. We will see the uses of the head and tail later.

###Adding elements to the list:

Now, let's add two numbers to the end of the list:

	list.add(15);
	list.add(13);

This builds the list as:

	15 -> 13
	^head ^tail | size == 2

We can also add numbers at a specific position:

	list.add(516,1);

After this operation, the list will be:

	15 -> 516 -> 13
	^head        ^tail | size == 3

###Inspecting the list size:

Now the list size can be inspected using list.getSize(). The following code will print the size of the list:

	cout << list.getSize() << "\n"; 
	// this prints '3' on the console

	cout << list.beg() << " " << list.mid() << " " << list.end();
	// this prints the beginning, middle and ending indices of the list

###Building the list:

The build() function builds empty slots at the end of the list. This function would require your data type to have a default constructor:

	list.build(3); 
	// now list.size() would return 6

Till now, the linked list is:

	15 -> 516 -> 13 -> 0 -> 0 -> 0
	^head                        ^tail | size == 6

###Removing elements:

We can remove elements using remove(position):

	list.remove(2); 

The list would become:
	
	15 -> 516 -> 0 -> 0 -> 0
	^head                  ^tail | size == 5

###Swapping elements:

Elements can be swapped using the swap(pos1,pos2) function:

	list.swap(0,2);

The list would become:
	
	0 -> 516 -> 15 -> 0 -> 0
	^head                  ^tail | size == 5

###Retrieving elements:

At any point, to get an element from the list, you can use the getData() function or the [] operator:

	list.getData(2); // returns 15
	list[1]; // returns 516

###Getting pointers pointing to elements (nodes):

There is also a feature to get the pointer to the node at a position:

	list.getNode(2); 
	// returns a pointer to the node with the integer 15

A node can be used to alter data like so:
	
	list.getNode(2)->data = 330;
	list.getNode(2)->next->next->data = 70;

The list after these operations would be:
	
	0 -> 516 -> 330 -> 0 -> 70
	^head                   ^tail | size == 5

getTail() gives the last node, getHead() gives the first node:

	list.getTail()->data = 53;
	list.getHead()->next->data = 37;

The list after these operations would be:
	
	0 -> 37 -> 330 -> 0 -> 53
	^head                   ^tail | size == 5

###Searching:

Searching can be done in the list using the search() function. However, this requires the data elements to be comparable, i.e. the operator == must be defined. The search function returns the position of the first occurance of the data element. It returns -2 if it is not found.

	list.search(79); // returns -2, because 79 is not found
	list.search(53); // returns 4, the position of 53 in the list
	list.search(0); // returns 0, the position of the first occurance of 0