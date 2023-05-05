/*
   Escrever uma função void split que recebe uma lista L1 e divida em duas Listas, indo de first até pos -1 e L2 iniciando em pos - limpe L2 antes
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
	printf("]\n");
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
		return 0;
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
	short l = L->length;
	TNode *aux;
	TNode *new = (TNode*)malloc(sizeof(TNode));

	if(position <= 0){
		insertLeft(val, L);
	} else if(position > l){
		insertRight(val, L);
	} else {
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
}

void removeElement(TListSE *L, Tdata position)
{
	short k = 0;
	TNode *aux, *aux2;
	aux = L->first;
	while(k < position - 1)
	{
		aux = aux->next;
		k++;
	}
	aux2 = aux->next->next;
	free(aux->next);
	aux->next = aux2;
	L->length--;
}

void printInvert(TNode *L)
{
	if(!L) return; // its over
	else{
		printInvert(L->next);
		printf(" %hd ",L->info);
		return;
	}
}

void removeByValue(TListSE *L, Tdata x)
{
	if(L->first->info)
		removeFirst(L);
	else if(L->last->info)
		removeLast(L);
	else {
		TNode *aux = L->first;
		TNode *aux2;
		while(aux->next->info != x)
		{
			aux = aux->next;
		}
		aux2 = aux->next->next;
		free(aux->next);
		aux->next = aux2;
		L->length--;
	}
}

short countElement(TListSE *L, Tdata x)
{
	TNode *aux = L->first;
	short count = 0;
	while(aux)
	{
		if(aux->info == x) count++;
		aux = aux->next;
	}
	return count;
}

void listConcat(TListSE *L1, TListSE *L2)
{
	L1->last->next = L2->first;
	L1->length += L2->length;
	L1->last = L2->last;	
}

void removeAll(TListSE *L, Tdata val)
{
	if(L->first->info == val) removeFirst(L);

	TNode *aux, *aux2;
	aux = L->first;
	while(aux)
	{
		if(aux->next->info == val){
			aux2 = aux->next->next;
			free(aux->next);
			aux->next = aux2;
			if(aux->next == NULL) break;
		} else {
			aux = aux->next;
		}
	}
	if(L->first->info == val) removeFirst(L);

}


//===========================================

int main()
{
  // Declaração de variáveis
  TListSE L1;
  TListSE L2;

  // Inicialização da lista
  initList(&L1);
  initList(&L2);

  
  // Verificando lista vazia
  emptyList(L1)? printf("Lista vazia!\n"): printf("Lista não vazia!\n");

  // insere pela esquerda
  insertLeft(1, &L1); 
  insertLeft(2, &L1);
  insertLeft(1, &L1); 
  insertLeft(1, &L1);
  insertLeft(1, &L1); 

  
  // insere pela direita
  insertRight(1, &L1); 
  insertRight(2, &L1);
  insertRight(1, &L1); 

  insertRight(10, &L2); 
  insertRight(20, &L2);
  insertRight(49, &L2); 


  printf("L1 = ");
  printList(L1);

  printf("Removendo valores \n");
  removeAll(&L1, 1);
  printf("L1 = ");
  printList(L1);
	/*
  printf("Inserindo um valor: \n");
  insert(&L1, 3, 10);
  
  // Imprimindo a lista
  printf("L1 = ");
  printList(L1);
  printf("\n");

  removeElement(&L1, 3);
  
  printf("Removendo um valor: \n");
  printList(L1);
  printf("\n");

  // invertendo a lista
  invertList(&L1);
  printf("L invertida\n");
  printList(L1);
  printf("\n");

  printf("Printando invertido \n");
  printInvert(L1.first);

  printf("\nRemovendo um valor específico: \n");
  removeByValue(&L1, 6);
  printf("L invertida\n");
  printList(L1);

  printf("Numero de elementos na lista : %hd ", countElement(&L1, 144));

  printf("L1 + L2 = ");
  listConcat(&L1, &L2);
  printList(L1);
  */
  // Deletando a lista
  printf("Deletando a lista L1...\n");
  deleteList(&L1);
  printf("Lista deletada!\n");
  
	return 0;
}

