#Data Structures#

The following data structures have been implemented:

##**list.h**##
A multi-purpose Linked list implementation.  

    - Useful for creating Linked lists  
    - Forms a basis for stacks, queues. A wrapper is all that is required.  
    - Optimized code

###Crash Course List:

Let's dive into the code rightaway. First, let's initialize an empty list called _list_ :

	List <int> list;

Now, let's add two numbers at the end of the list:

	list.add(15);
	list.add(13);

We can also add numbers at a specific position:

	list.add(516,1);

Now the list size can be inspected using list.getSize(). The following code will print the size of the list:

	cout << list.getSize(); // this prints '3' on the console

The build() function builds empty slots at the end of the list. This function would require your data type to have a default constructor:

	list.build(3); // now list.size() would return 6

Till now, the linked list is:

	15 -> 516 -> 13 -> 0 -> 0 -> 0

At any point, if you'd like to get an element from the list, you can use the getData() function or the [] operator:

	list.getData(2); // returns 13
	list[1]; // returns 516

We can remove elements using remove():

	list.remove(2); // The list would become 15 -> 516 -> 0 -> 0 -> 0
