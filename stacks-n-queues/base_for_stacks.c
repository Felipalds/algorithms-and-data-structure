
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char Tdata;
typedef struct TNode
{
    Tdata info;
    struct TNode *next;
} TNode;
typedef struct TStack
{
    TNode *first;
    TNode *last;
    short length;
} TStack;

void initList(TStack *L)
{
    L->first = NULL;
    L->last = NULL;
    L->length = 0;
}

void pop(Tqueue *L)
{
	TNode *aux = L->first;
	L->first = L->first->next;
	free(aux);
	if (L->first == NULL)
		L->last = NULL;
	L->length--;
}

short push(Tdata x, Tqueue *L)
{
	TNode *aux;
	aux = (TNode*)malloc(sizeof(TNode));
	if (aux == NULL)
		return 1;
	else
	{
		aux->info = x;
		aux->next = L->first;
		L->first = aux;
		if (L->last == NULL)
			L->last = aux;
		L->length++;
		return 0;
	}
}


void PrintStack(TStack L)
{
	TNode *p = L.first;
	
	printf("[");
	while (p)
	{
		printf("%c", p->info);
		if (p->next)
			printf(", ");
		p = p->next;
	}
	printf("]\n");
}

void DeleteStack(TStack *L)
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

int main()
{
   
}
