#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// tipo de dado a ser colocado na lista
typedef short Tdata;

// tipo de dado para a lista encadeada
typedef struct TNode
{
    Tdata info; // dado armazenado no nó
    struct TNode *next; // ponteiro para o próximo nó
} TNode;

typedef struct TListSE
{
    TNode *first;
    TNode *last;
    short length;
} TListSE;

/*

    Funções sobre listas encadeadas

*/

// inicialização da lista
void initList(TListSE *L)
{
    L->first = NULL;
    L->last = NULL;
    L->length = 0;
}

// inserção pela esquerda
short insertLeft(Tdata x, TListSE *L)
{

}

// inserção pela direita
short insertRight(Tdata x, TListSE *L)
{
    TNode *aux = (TNode*)malloc(sizeof(TNode));
    if(!aux)
        exit(1);
    else
    {
        aux->info = x;
        aux->next = NULL;
        if(L->length == 0)
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

// print list
void printList(TListSE L)
{
    TNode *p = L.first;
    printf("[");
    while(p)
    {
        printf("%hd", p->info);
        if(p->next)
            printf(", ");
        p = p->next;
    }
    printf("]");
}

// função que insere arrays?

int main(){

    TListSE lista;
    initList(&lista);
    insertRight(3, &lista);
    printList(lista);
    return 0;
}