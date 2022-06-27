
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
    int length;
} TListSE;

void initList(TListSE *L)
{
    L->first = NULL;
    L->last = NULL;
    L->length = 0;
}

short insertLast(TListSE *L, Tdata x)
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

short insertFirst(TListSE *L, Tdata x)
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

void removeFirst(TListSE *L)
{
	TNode *aux = L->first;
	L->first = L->first->next;
	free(aux);
	if (L->first == NULL)
		L->last = NULL;
	L->length--;
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
	
	while (p)
	{
		printf("%c", p->info);
		p = p->next;
	}
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
    TListSE Stack, OriginalQueue, AuxiliarQueue, historicData;
    int totalChar;
    char queueChar;
    Tdata dataInsert = 'I';
    Tdata dataRemove = 'R';
    int isImpossible = 0;

    initList(&Stack);
    initList(&OriginalQueue);
    initList(&AuxiliarQueue);
    initList(&historicData);

    scanf("%d", &totalChar);

    getchar();
    for(int c = 0; c < totalChar; c++)
    {
        scanf("%c", &queueChar);
        insertLast(&OriginalQueue, queueChar);
    }
    getchar();

    for(int c = 0; c < totalChar; c++)
    {
        scanf("%c", &queueChar);
        insertLast(&AuxiliarQueue, queueChar);
    }
    getchar();
    
    TNode *aux = OriginalQueue.first;
    insertLast(&Stack, aux->info);


    while(AuxiliarQueue.length > 0)
    {
        if(aux == NULL && Stack.last->info != AuxiliarQueue.first->info){
            isImpossible = 1;
            break;
        }

        while(Stack.last->info != AuxiliarQueue.first->info && aux->next != NULL)
        {
            aux = aux->next;
            insertLast(&Stack, aux->info);
            insertLast(&historicData, dataInsert);
        }

        removeFirst(&AuxiliarQueue);
        removeLast(&Stack);
        insertLast(&historicData, dataRemove);
    }

    printList(historicData);
    isImpossible == 1 ? printf(" Impossible\n") : printf("\n");

}
