#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

typedef unsigned short Tdata;

typedef struct TreeNode
{
    Tdata info;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

typedef  struct TNode
{
	TreeNode *info;
	struct TNode *next;
} TNode;

typedef struct TListSE
{
	TNode *first;
	TNode *last;
	short length;
} TListSE;

// ====----=====----====----====---
void initList(TListSE *L)
{
	L->first = NULL;
	L->last = NULL;
	L->length = 0;
}

void deleteList(TListSE *L)
{
	TNode *p = L->first;
	while (p)
	{
		L->first = L->first->next;
		free(p);
		L->length--;
		p = L->first;
	}
	L->last = NULL;
}

bool emptyList(TListSE L)
{
	return (L.length == 0);
}


short insertRight(TreeNode *x, TListSE *L)
{
	TNode *aux = (TNode*)malloc(sizeof(TNode));
	if (aux ==NULL)
		return 1;
	else
	{
		aux->info = x;
		aux->next = NULL;
	
		if (L->last == NULL)
			L->first = L->last = aux;
		else
		{
			L->last->next = aux;
			L->last = aux;
		}
		L->length++;
		return 0;
	}
}

void removeFirst(TListSE *L)
{
	TNode *aux = L->first;
	L->first = L->first->next;
	free(aux);
	if (L->first == NULL)
		L->last = NULL;
	L->length--;
}

TreeNode* head(TListSE L)
{
    return (L.first->info);
}
