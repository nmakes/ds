#Data Structures#

The following data structures have been implemented:

##**list.h**##
A multi-purpose Linked list implementation.  

    - Useful for creating Linked lists  
    - Forms a basis for stacks, queues. A wrapper is all that is required.  
    - Optimized code

###Crash Course:

Let's dive into the code rightaway. First, let's initialize an empty list called _list_ :

	List <int> list;

Now, let's add two numbers at the end of the list:

	list.add(15);
	list.add(13);

This builds the list as:

	15 -> 13 -> NULL

We can also add numbers at a specific position:

	list.add(516,1);

After this operation, the list will be:

	15 -> 516 -> 13 -> NULL;

Now the list size can be inspected using list.getSize(). The following code will print the size of the list:

	cout << list.getSize(); // this prints '3' on the console

The build() function builds empty slots at the end of the list. This function would require your data type to have a default constructor:

	list.build(3); // now list.size() would return 6

Till now, the linked list is:

	15 -> 516 -> 13 -> 0 -> 0 -> 0 -> NULL

We can remove elements using remove(position):

	list.remove(2); // The list would become 15 -> 516 -> 0 -> 0 -> 0 -> NULL

Elements can be swapped using the swap(pos1,pos2) function:

	list.swap(0,2); // The list will become 0 -> 516 -> 15 -> 0 -> 0 -> NULL

At any point, to get an element from the list, you can use the getData() function or the [] operator:

	list.getData(2); // returns 15
	list[1]; // returns 516

There is also a feature to get the pointer to the node at a position:

	list.getNode(2); // returns a pointer to the node with the integer 15

A node can be used to alter data like so:
	
	list.getNode(2)->data = 330;
	list.getNode(2)->next->next->data = 70;

The list after these operations would be:
	
	0 -> 516 -> 330 -> 0 -> 70 -> 0 -> NULL