#Data Structures#

The following data structures have been implemented:

##**list.h**##
A multi-purpose Linked list implementation.  

    - Useful for creating Linked lists  
    - Forms a basis for stacks, queues. A wrapper is all that is required.  
    - Optimized code

###Standard functions:
	1. TNode * getNode(unsigned long pos)
		* returns a pointer to the node at position _pos_
	2. TNode * getLast()
		* returns a pointer to the last node
	3. T getData(unsigned long pos)
		* returns the data at the position _pos_
	4. T operator[] (unsigned long pos)
		* returns the data at the position _pos_
	5. void add(T data, unsigned long pos)
		* adds element _data_ at posititon _pos_
	6. void add(T data)
		* adds element _data_ at the last position (append operation)
	7. void remove(unsigned long pos)
		* removes the element at position pos
	8. int swap(unsigned long pos1, unsigned long pos2)
		* swaps elements at position pos1 and pos2
	9. void build(unsigned long number_of_elem)
		* creates __number_of_elem__ number of empty nodes in the linked list
	10. long search(T data)
		* searches for 