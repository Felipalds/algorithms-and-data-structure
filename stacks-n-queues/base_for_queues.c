
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char Tdata;
typedef struct TNode
{
    Tdata info;
    struct TNode *next;
} TNode;
typedef struct TQueue
{
    TNode *first;
    TNode *last;
    short length;
} TQueue;

void initQueue(TQueue *L)
{
    L->first = NULL;
    L->last = NULL;
    L->length = 0;
}

short inQueue(Tdata x, TQueue *L)
{
    TNode *aux = (TNode*)malloc(sizeof(TNode));
    if(aux == NULL)
        return 1;
    else
    {
        aux->info = x;
        aux->next = NULL;
        if(L->last == NULL)
            L->first = L->last = aux;
        else
        {
            L->last->next = aux;
            L->last = aux;
        }
        L->length ++;
        return 0;
    }
}

void deQueue(TQueue *L)
{
	TNode *aux = L->first;
	L->first = L->first->next;
	free(aux);
	if (L->first == NULL)
		L->last = NULL;
	L->length--;
}

void PrintQueue(TQueue L)
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

void DeleteQueue(TQueue *L)
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
