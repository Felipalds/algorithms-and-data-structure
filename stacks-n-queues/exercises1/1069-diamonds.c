/*
    Diamantes e Areia
    1. <> isso é um diamante.
    2. Devemos remover as areias entre os diamantes < ..... >.
    3. >>> isso não é um diamante.
*/

// %hu para unsigned short

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char Tdata;
typedef struct TNode
{
    Tdata info;
    struct TNode *next;
} TNode;
typedef struct TListSE
{
    TNode *first;
    TNode *last;
    short length;
} TListSE;

void initList(TListSE *L)
{
    L->first = NULL;
    L->last = NULL;
    L->length = 0;
}

short insertLast(Tdata x, TListSE *L)
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

void removeLast(TListSE *L)
{
    TNode *aux = L->first;
    if(L->first == L->last)
    {
        free(L->first);
        L->last = L->first = NULL;
    }
    else
    {
        while(aux->next->next != NULL)
            aux = aux->next;
        L->last = aux;
        free(aux->next);
        L->last->next = NULL;
    }
    L->length --;
}

void printList(TListSE L)
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

int main()
{
    int times;
    char mine;
    int diamonds = 0;
    TListSE List;
    scanf("%d", &times);
        getchar();


    while(times > 0)
    {
        initList(&List);
        while(scanf("%c", &mine) && mine != '\n')
        {
            if(mine == '<') insertLast(mine, &List);
            if(mine == '>') {
                if(List.length > 0)
                {
                    removeLast(&List);
                    diamonds++;
                }
            }
        }

        printf("%d\n", diamonds);
        deleteList(&List);
        diamonds = 0;
        times--;
    }
}
