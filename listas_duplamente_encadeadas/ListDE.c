// 1. Escrever uma função para inverter uma lista duplamente encadeada = diff
// 2. Escrever uma função para inserir um elemento em uma lista duplamente encadeada dada uma posição = diff
// 3. Escrever uma função para remover um elemente dada uma posição na lista duplamente encadeada
// 4. Escrever uma função para remover um elemento da lista, dado o seu valor
// 5. Escrever uma funlçao de concatenação para listas "TListDE lstcat(TLitsDE &L1, TListDE L2") = diff
// 6. Escrever uma função ara contar o numero de ocorrencias de um elemento x em uma lista L
// 7. Escrever uma função que, dados um valor x e uma lista L, remova todas as ocorrencias de x L

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

typedef short Tdata; 

typedef  struct TNode
{
	Tdata info;
  	struct TNode *prev;
	struct TNode *next;
} TNode;

typedef struct TListDE
{
	TNode *first;
	TNode *last;
	short length;
} TListDE;

void initList(TListDE *L)
{
	L->first = NULL;
	L->last = NULL;
	L->length = 0;
}

void deleteList(TListDE *L)
{
	TNode *p = L->first;
	while (p)
	{
		L->first = L->first->next;
		free(p);
		p = L->first;
	}
	L->last = NULL;
  L->length = 0;
}

bool emptyList(TListDE L)
{
	return (L.length == 0);
}

void printList(TListDE L, bool inverse) 	
{	
  TNode *p;
  if (!inverse)
  {
    printf("First->");
    p = L.first;
     
    while (p)
    {
      printf("[%hd]->", p->info);
      p = p->next;
    }
    printf("[NULL]");
  }
	else
	{
		printf("Last->");
    p = L.last;
     
    while (p)
    {
      printf("[%hd]->", p->info);
      p = p->prev;
    }
    printf("[NULL]");
	}
  
  return;
}

short insertLeft(Tdata x, TListDE *L)
{
	TNode *aux;
	aux = (TNode*)malloc(sizeof(TNode));
	if (aux == NULL)
		return 1;
	else
	{
		aux->info = x;
		aux->next = L->first;
		aux->prev = NULL;
		if (L->first != NULL)
			L->first->prev = aux;
		L->first = aux;
		if (L->last == NULL)
			L->last = aux;
		L->length++;
		return 0;
	}
}

// Inserção pela direita
short insertRight(Tdata x, TListDE *L)
{
	printf("inserindo");
	TNode *aux = (TNode*)malloc(sizeof(TNode));
	if (aux == NULL){
		printf("ERRO DE INSERÇÃO");
		return 1;
	}
	else
	{
		aux->info = x;
		aux->next = NULL;
		aux->prev = L->last;
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

void removeFirst(TListDE *L)
{
	TNode *aux = L->first;
	L->first = L->first->next;
	free(aux);
	if (L->first == NULL)
		L->last = NULL;
  else
  L->first->prev = NULL;
	L->length--;
}

void removeLast(TListDE *L)
{
	TNode *aux = L->last;
	L->last = L->last->prev;
	free(aux);
	if (L->last == NULL)
		L->first = NULL;
  else
    L->last->next = NULL;
	L->length--;
}

TNode* searchList(Tdata x, TListDE L)
{
	TNode *aux = L.first;	
	while (aux && aux->info != x)
		aux = aux->next;
	return aux;
}

Tdata sumList(TListDE L)
{
	TNode *aux = L.first;
	Tdata s = 0;
	
	while (aux)
	{
		s += aux->info;
		aux = aux->next;
	}
	return s;
}
 
 Tdata avgList(TListDE L)
 {
	 return (sumList(L)/L.length);
 }

TListDE *dec2bin(Tdata num)
{
	Tdata r;
	TListDE *L = (TListDE*)malloc(sizeof(TListDE));
	initList(L);
	
	while (num > 1)
	{
		r = num % 2;
		num = num / 2;
		(insertLeft(r, L));
	}
	insertLeft(num, L);
	return L;
}

Tdata bin2dec(TListDE L)
{
	Tdata i = 0, n = 0;
	TNode *aux = L.first;
	
	while (aux)
	{
		n += aux->info * (Tdata)pow(2, L.length - (++i));
		aux = aux->next;
	}
	return n;
}

void invertList(TListDE *L)
{
	printf("aaaa");
	if(L->length <= 1) 
		printf("Lista possui 1 ou nenhum elemento! Nada será realizado.\n");
	else
	{
		printf("Lista possui mais de um elemento, invertendo . . .");
		TNode *seg, *atu;
		L->last = L->first;
		
		while(L->first);
		{
			printf("aaaaaaaaaaaaa ");
			seg = L->first->next;
			atu = L->first;
			L->first->next = L->first->prev;
			L->first->prev = seg;
			L->first = seg;
		}
		L->first = atu;
	}
}

//===========================================

int main()
{
	TListDE L1;
	short a, b;
	short k = 0;
	TNode *n;
	
	initList(&L1);
	printf("Lista Inicializada!");

	// printf("Digite um valor a ser inserido (-1 para sair)");
	
	// while(scanf("%hd", &k) && (k != -1))
	// {
	// 	if(!insertRight(k, &L1)) printf("%hd inserido!", k);
	// 	else printf("Erro na inserção!");
	// }
	printf("asdasdasd");
	insertRight(1, &L1);
	insertRight(2, &L1);
	insertRight(3, &L1);
	insertRight(4, &L1);


	printf("aaaa");

	printList(L1, 0);

	printf("aaaa");
	invertList(&L1);
	printf("aaaa");

	printList(L1, 0);

	deleteList(&L1);
  	printf("\nLista apagada!");
	
	return 0;
}

