/*
	Copyright (c) 2017 Naveen Venkat
	github.com/nmakes/ds
	Read Licence for more info
*/

#ifndef FLAG_IOSTREAM
#include <iostream>
#define FLAG_IOSTREAM
#endif

#ifndef FLAG_CSTDLIB
#include <cstdlib>
#define FLAG_CSTDLIB
#endif

#define LIST_VERSION_NUMBER 1.1

// changelog
// using a *tail pointer to improve traversal

using namespace std;

template <typename T> class Node
{
	public:
		T data;
		Node <T> * next;

		Node<T>(T d)
		{
			data = d;
			next = NULL;
		}
};

#define TNode Node <T>

template <typename T> class List
{
	private:

		TNode * head;
		TNode * tail;
		TNode * iterator;
		unsigned long size;

	public:

		List<T>()
		{
			head = NULL;
			tail = NULL;
			size = 0;
		}

		TNode * getNode(unsigned long pos);
		TNode * getLast();
		T getData(unsigned long pos);
		T operator[] (unsigned long pos);
		void add(T data, unsigned long pos);
		void add(T data);
		void remove(unsigned long pos);
		int swap(unsigned long pos1, unsigned long pos2);
		void build(unsigned long number_of_elem); // build requires a default constructor of type T.
		long search(T data); //

		int isEmpty() // returns true if the list is empty
		{return (size==0 && head==NULL && tail==NULL);}

		int isCorrupt() // returns true if the size is not zero, but the head or tail points differently
		{return ( (size!=0 && (head==NULL||tail==NULL)) || (head!=NULL && tail==NULL) || (head==NULL && tail!=NULL) ) ;}

		int isOrphan() // returns true if the size is zero and head is points to NULL (an empty pointer)
		{return (size==0 && (head==NULL||tail==NULL));}

		unsigned long getSize()
		{return size;}

		TNode * getHead()
		{return head;}

		TNode * getTail()
		{return tail;}

		unsigned long beg()
		{return 0;}

		unsigned long mid()
		{return size/2;}

		unsigned long end()
		{return size-1;}

		/*
			Utility Functions
			- These need to be defined by the user.
			- These use a function called 'compare' for comparing two nodes.
			- Define a function called compare in class T.

		*/

		// to be done

		int compare(T a, T b);
		void sort();
		T getMax();
		T getMin();
};

// FUNCTION DEFINITIONS

template <typename T>
TNode * List<T>::getNode(unsigned long index)
{
	// returns the node at position, if exists
	// returns NULL if head is NULL
	// throws exception and returns NULL if index is out of bounds

	if(head == NULL)
	{
		return NULL;
	}
	else if(index < 0 || index > size-1)
	{
		cout << endl << "==| Exception.List.getNode(): index out of bounds" << endl;
		return NULL;
	}
	else if(index == size-1)
	{
		return tail;
	}
	else
	{
		TNode* mov = head;
		for(int i=0;i<index; i++)
		{
			mov = mov->next;
		}
		return mov;
	}
}

template <typename T>
TNode * List<T>::getLast()
{
	// returns the last node
	return tail;
}

template <typename T>
T List<T>::getData(unsigned long pos)
{
	// returns the element at position pos
	// throws fatal exception and exits if error occurs

	if(head == NULL)
	{
		cout << endl << "==| FatalException.List.get(): head is NULL" << endl;
		system("exit");
	}
	else if(pos < 0 || pos > size-1)
	{
		cout << endl << "==| FatalException.List.get(): index out of bounds" << endl;
		system("exit");
	}
	else if(pos == size-1)
	{
		return tail->data;
	}
	else
	{
		TNode* mov = head;
		for(int i=0;i<pos; i++)
		{
			mov = mov->next;
		}
		return mov->data;
	}
}

template <typename T>
T List<T>::operator[] (unsigned long pos)
{
	// same as getData() function
	// returns the element at position pos
	// throws fatal exception and exits if error occurs

	if(head == NULL)
	{
		cout << endl << "==| FatalException.List.get(): head is NULL" << endl;
		system("exit");
	}
	else if(pos < 0 || pos > size-1)
	{
		cout << endl << "==| FatalException.List.get(): index out of bounds" << endl;
		system("exit");
	}
	else if(pos == size-1)
	{
		return tail->data;
	}
	else
	{
		TNode* mov = head;
		for(int i=0;i<pos; i++)
		{
			mov = mov->next;
		}
		return mov->data;
	}
}

template <typename T>
void List<T>::add(T data, unsigned long pos)
{
	// adds the given data at position pos
	// throws a fatal exception and exits if index is out of bounds

	if(pos < 0 || pos > size)
	{
		cout << endl << "==| FatalException.List.add(): index out of bounds" << endl;
		system("exit");
	}
	else
	{
		if(head==tail) // single element case
		{
			TNode * temp = new TNode(data);
			temp -> next = NULL;
			head = tail = temp;	
		}
		else if (pos==0)
		{
			TNode * temp = new TNode(data);
			temp -> next = head;
			head = temp;
		}
		else if(pos==size)
		{
			TNode * addNode = new TNode(data);
			addNode -> next = NULL;
			tail -> next = addNode;
			tail = addNode;
		}
		else
		{
			TNode * temp = getNode(pos-1);
			TNode * addNode = new TNode(data);
			addNode -> next = temp -> next;
			temp -> next = addNode;
		}
		size++;
	}
}

template <typename T>
void List<T>::add(T data)
{
	// adds the given data at the end
	// throws a fatal exception and exits if index is out of bounds

	TNode * temp = new TNode(data);
	if(tail == NULL)
	{
		head = tail = temp;
	}
	else
	{
		tail -> next = temp;
		tail = temp;
	}
	size++;

	// Here is an alternate code. It would take longer time for execution
	// because of the function call add(node,size). However, the code
	// size is small.
	/*
		add(node, size);
	*/
}

template <typename T>
void List<T>::remove(unsigned long pos)
{
	// removes the data at position pos
	// throws a fatal exception and exits if head is NULL
	// throws a fatal exception and exits if index is out of bounds

	if(head == NULL)
	{
		cout << endl << "==| FatalException.List.remove(): head is NULL" << endl;
		system("exit");
	}
	else if(pos < 0 || pos > size-1)
	{
		cout << endl << "Exception.List.remove(): index out of bounds" << endl;
		system("exit");
	}
	else
	{
		if(head==tail)
		{
			delete head;
			head = tail = NULL;
		}
		else if(pos == 0)
		{
			TNode * temp= head;
			head = head->next;
			delete temp;
			size--;
		}
		else
		{
			TNode * prev = getNode(pos-1);
			TNode * temp = prev->next;
			prev -> next = temp->next;
			delete temp;
			size--;

			if(pos==size-1)
			{
				tail = prev;
			}
		}
	}
}

template <typename T>
int List<T>::swap(unsigned long pos1, unsigned long pos2)
{
	// swaps elements at pos1 and pos2
	// returns -1 if head is NULL
	// returns -2 if either of the positions is out of bounds

	if(head==NULL)
	{
		cout << endl << "Exception.List.swap(): head is NULL" << endl;
		return -1;
	}
	if( (pos1<0 || pos1>size-1) )
	{
		cout << endl << "Exception.List.swap(): first node index out of bounds" << endl;
		system("exit");
		return -2;
	}
	else if( (pos2<0 || pos2>size-1) )
	{
		cout << endl << "Exception.List.swap(): second node index out of bounds" << endl;
		system("exit");
		return -2;
	}
	else
	{
		T temp = getData(pos1);
		getNode(pos1) -> data = getNode(pos2) -> data;
		getNode(pos2) -> data = temp;
	}
}

template <typename T>
void List<T>::build(unsigned long number_of_elem)
{
	// creates number_of_elem number of empty elements
	// does not throw any exception TODO: edit this

	for(int i=1; i<=number_of_elem; i++)
	{
		add(*(new T())); // requires a default constructor of type T.
	}
}

template <typename T>
long List<T>::search(T nData)
{
	// searches for the first occurance of the given element
	// returns the index of the first occurance of the data
	// returns -1 if head is NULL
	// returns -2 if not found

	if(head == NULL)
	{
		cout << endl << "Exception.List.remove(): head is NULL" << endl;
		system("exit");
		return -1;
	}
	else
	{
		TNode * mov = head;
		int i=0;
		while(mov != NULL)
		{
			if(mov->data == nData)
			{
				return i;
			}
			i++;
			mov = mov->next;
		}
	}
	return -2; // not found
}
