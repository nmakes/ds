#ifndef FLAG_IOSTREAM
#include <iostream>
#define FLAG_IOSTREAM
#endif

#ifndef FLAG_CSTDLIB
#include <cstdlib>
#define FLAG_CSTDLIB
#endif

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
		unsigned long size;

	public:

		List<T>()
		{
			head = NULL;
			size = 0;
		}

		TNode * getNode(unsigned long pos)
		{
			if(head == NULL)
			{
				cout << endl << "Exception.List.getNode(): head is NULL" << endl;
				system("exit");
			}
			else if(pos < 0 || pos > size-1)
			{
				cout << endl << "Exception.List.getNode(): index out of bounds" << endl;
				system("exit");
			}
			else
			{
				TNode* mov = head;
				for(int i=0;i<pos; i++)
				{
					mov = mov->next;
				}
				return mov;
			}
		}

		TNode * getLast()
		{
			if(head == NULL)
			{
				return head;
			}
			else
			{
				TNode *mov = head;
				while(mov->next!=NULL)
				{
					mov = mov->next;
				}
				return mov;
			}
		}

		T getData(unsigned long pos)
		{
			if(head == NULL)
			{
				cout << endl << "Exception.List.get(): head is NULL" << endl;
				system("exit");
			}
			else if(pos < 0 || pos > size-1)
			{
				cout << endl << "Exception.List.get(): index out of bounds" << endl;
				system("exit");
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

		T operator[] (unsigned long pos)
		{
			if(head == NULL)
			{
				cout << endl << "Exception.List.get(): head is NULL" << endl;
				system("exit");
			}
			else if(pos < 0 || pos > size-1)
			{
				cout << endl << "Exception.List.get(): index out of bounds" << endl;
				system("exit");
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

		void add(T node, unsigned long pos)
		{
			if(pos < 0 || pos > size)
			{
				cout << endl << "Exception.List.add(): index out of bounds" << endl;
				system("exit");
			}
			else
			{
				if (pos==0)
				{
					TNode * temp = new TNode(node);
					temp -> next = head;
					head = temp;
				}
				else
				{
					TNode * temp = getNode(pos-1);
					TNode * addNode = new TNode(node);
					addNode -> next = temp -> next;
					temp -> next = addNode;
				}
				size++;
			}
		}

		void add(T node)
		{
			TNode * temp = new TNode(node);
			TNode * last = getLast();
			if(last == NULL)
			{
				head = temp;
			}
			else
			{
				last -> next = temp;
			}
			size++;

			// Here is an alternate code. It would take longer time for execution
			// because of the function call add(node,size). However, the code
			// size is small.
			/*
				add(node, size);
			*/
		}

		void remove(unsigned long pos)
		{
			if(head == NULL)
			{
				cout << endl << "Exception.List.remove(): head is NULL" << endl;
				system("exit");
			}
			else if(pos < 0 || pos > size-1)
			{
				cout << endl << "Exception.List.remove(): index out of bounds" << endl;
				system("exit");
			}
			else
			{
				if(pos == 0)
				{
					TNode * temp= head;
					head = head->next;
					delete temp;
				}
				else
				{
					TNode * mov = head;
					for(int i=1;i<pos; i++)
					{
						mov = mov->next;
					}
					TNode * temp = mov->next;
					mov -> next = temp -> next;
					delete temp;
				}
			}

			size--;
		}

		void swap(unsigned long pos1, unsigned long pos2)
		{
			if( (pos1<0 || pos1>size-1) )
			{
				cout << endl << "Exception.List.swap(): first node index out of bounds" << endl;
				system("exit");
				return;
			}
			else if( (pos2<0 || pos2>size-1) )
			{
				cout << endl << "Exception.List.swap(): second node index out of bounds" << endl;
				system("exit");
				return;
			}
			else
			{
				T temp = getData(pos1);
				getNode(pos1) -> data = getNode(pos2) -> data;
				getNode(pos2) -> data = temp;
			}
		}

		unsigned long getSize()
		{
			return size;
		}

		TNode * getHead()
		{
			return head;
		}

		unsigned long beg()
		{return 0;}

		unsigned long mid()
		{return size/2;}

		unsigned long end()
		{return size-1;}

		void build(unsigned long number_of_elem) // create number_of_elem amount of empty elements
		{
			for(int i=1; i<=number_of_elem; i++)
			{
				add(*(new T())); // requires a default constructor of type T.
			}
		}

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
