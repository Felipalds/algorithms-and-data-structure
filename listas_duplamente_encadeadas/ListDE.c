// 1. Escrever uma função para inverter uma lista duplamente encadeada
// 2. Escrever uma função para inserir um elemento em uma lista duplamente encadeada dada uma posição
// 3. Escrever uma função para remover um elemente dada uma posição na lista duplamente encadeada
// 4. Escrever uma função para remover um elemento da lista, dado o seu valor
// 5. Escrever uma funlçao de concatenação para listas "TListDE lstcat(TLitsDE &L1, TListDE L2")
// 6. Escrever uma função para contar o numero de ocorrencias de um elemento x em uma lista L
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
	TNode *aux = (TNode*)malloc(sizeof(TNode));
	if (aux == NULL)
		return 1;
	else
	{
		aux->info = x;
		aux->next = NULL;					// Não tem próximo
		aux->prev = L->last;				// O anterior é o antigo último

		if (L->last == NULL)				// Lista estava vazia
			L->first = L->last = aux;	// atualiza primeiro e último
		else                          // atualiza só o último
		{
			L->last->next = aux;			// liga o novo último nó
			L->last = aux;					// atualiza o ponteiro para o novo último
		}
		L->length++;						// atualiza o comprimento
		return 0;
	}
}

// remoção pela esquerda
void removeFirst(TListDE *L)
{
	TNode *aux = L->first;		// Guarda o nó a ser removido em aux
	L->first = L->first->next;	// Avança para o próximo nó
	free(aux)	;					// libera aux
	if (L->first == NULL)		// Lista ficou vazia
		L->last = NULL;			// Anula o last também
  else
  L->first->prev = NULL;
	L->length--;					// reduz o tamanho
}

// remoção pela direita

void removeLast(TListDE *L)
{
	TNode *aux = L->last;		// Guarda o nó a ser removido em aux
	L->last = L->last->prev;	// volta para o nó anterior
	free(aux)	;					// libera aux
	if (L->last == NULL)			// Lista ficou vazia
		L->first = NULL;			// Anula o first também
  else
    L->last->next = NULL;			// Anula o próximo do novo último
	L->length--;					// reduz o tamanho
}

// Busca um elemento na lista
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

// decimal para binário
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


// binário para decimal

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

//===========================================

int main()
{
	TListDE L1;
	short a, b;
	short k = 0;
	TNode *n;
	
	initList(&L1);
	printf("Lista Inicializada!\n\n");

	printf("Digite um valor a ser inserido (-1 para sair)");
	
	while(scanf("%hd", &k) && (k != -1))
	{
		if(!insertRight(k, &L1)) printf("%hd inserido!", k);
		else printf("Erro na inserção!");
	}
	printList(L1, 0);

	deleteList(&L1);
  	printf("Lista apagada!");
    deleteList(&L2);
	
	return 0;
}

