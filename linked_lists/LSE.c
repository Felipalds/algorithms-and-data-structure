/* 2 - escrever uma função para inserir um elemento em uma lista em uma dada posição
	- pos <= 0 insere na esquerda
	- pos >= tamanho da lista, insere no fim
	- 0 < pos <= tamanho

   3 - escrever uma função para remover um elemento em uma dada posição da lista
   4 - fazer uma função para escrever os elementos da lista em ordem inversa sem inverter a lista

   1 - escrever uma função para remover um elemento da lista dado o seu valor
   2- escrever uma função de concatenação para listas
   3- escrever uma função para contar o número de ocorrências de um elemento X em uma lista L
   4- escrever uma função removeall, que remove todas as ocorrências de x em l1.
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

// ============================
typedef short Tdata; 
typedef  struct TNode
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

// ============================
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

void printList(TListSE L)
{
	TNode *p = L.first;
	
	printf("[");
	while (p)
	{
		printf("%hd", p->info);
		if (p->next)
			printf(", ");
		p = p->next;
	}
	printf("]");
}

short insertLeft(Tdata x, TListSE *L)
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
		return 0
	}
}

short insertRight(Tdata x, TListSE *L)
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

void removeLast(TListSE *L)
{
	TNode *aux = L->first;
	
	if (L->first == L->last)
	{
		free(L->first);
		L->last = L->first =NULL;
	}
	else
	{
		while (aux->next->next != NULL)
			aux = aux->next;
		L->last = aux;
		free(aux->next);
		L->last->next = NULL;
	}
	L->length--;
}

TNode* searchList(Tdata x, TListSE L)
{
	TNode *aux = L.first;
	
	while (aux && aux->info != x)
		aux = aux->next;
	return aux;
}

Tdata sumList(TListSE L)
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
 
Tdata avgList(TListSE L)
{
	return (sumList(L)/L.length);
}

void dec2bin(Tdata num, TListSE* L)
{
	Tdata r;
	deleteList(L);
	while (num > 1)
	{
		r = num % 2;
		num = num / 2;
		insertLeft(r, L);
	}
	insertLeft(num, L);
}

Tdata bin2dec(TListSE L)
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

void invertList(TListSE *L)
{
	TNode *ant; // valor anterior ao first - null
	TNode *seg; // valor proximo ao first
	L->last = L->first; // last recebe first
	ant = NULL;
	seg = NULL;

	while(L->first != NULL)
	{
		seg = L->first->next;
		L->first->next = ant;
		ant = L->first;
		L->first = seg;
	}
	L->first = ant;
}

void insert(TListSE *L, short position, Tdata val)
{
	int k = 0;
	TNode *aux;
	TNode *new = (TNode*)malloc(sizeof(TNode));

	if(!new){
		exit(1);
	}

	new->info = val;
	aux = L->first;
	
	while(k < position - 1)
	{
		aux = aux->next;
		k++;
	}
	new->next = aux->next;
	aux->next = new;
	L->length = L->length + 1;

}


//===========================================

int main()
{
  // Declaração de variáveis
  TListSE L1;

  // Inicialização da lista
  printf("Inicializando a lista L1...\n");
  initList(&L1);
  printf("Lista inicializada!\n");
  
  // Verificando lista vazia
  emptyList(L1)? printf("Lista vazia!\n"): printf("Lista não vazia!\n");

  // insere pela esquerda
  insertLeft(1, &L1); 
  insertLeft(2, &L1);
  insertLeft(3, &L1); 
  
  // insere pela esquerda
  insertRight(4, &L1); 
  insertRight(5, &L1);
  insertRight(6, &L1); 

  insert(&L1, 3, 10);
  
  // Imprimindo a lista
  printf("L1 = ");
  printList(L1);
  printf("\n");

  // invertendo a lista
  invertList(&L1);
  printf("L invertida");
  printList(L1);
  printf("\n");
  
  // Deletando a lista
  printf("Deletando a lista L1...\n");
  deleteList(&L1);
  printf("Lista deletada!\n");
  
	return 0;
}

