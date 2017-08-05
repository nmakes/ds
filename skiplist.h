#include <stdio.h>
#include <stdlib.h>

typedef struct _SkipList SkipList;
typedef struct _SkipNode SkipNode;

struct _SkipNode
{
	int val;
	SkipNode * next;
	SkipNode * prev;
};

struct _SkipListNode
{
	int height;
	SkipNode * node;
	SkipListNode * up;
	SkipListNode * down;
	SkipListNode * right;
	SkipListNode * left;
};

int skipList_getNextLevel(SkipList * list)
{
	return list->
}

SkipList * skipList_init(int n = 0)
{
	if(n==0)
	{
		SkipList * sl = (SkipList*) malloc(sizeof(SkipList));
		sl->pos = 0;
		sl->val = 0;
		sl->size = 1;
		sl->up = NULL;
		sl->down = NULL;
		sl->left = NULL;
		sl->right = NULL;
	}
	else
	{
		return (SkipList*) malloc(sizeof(SkipList) * n);
	}
}

int main(int argc, char* argv[])
{
	SkipList * head = NULL;
	return 0;
}