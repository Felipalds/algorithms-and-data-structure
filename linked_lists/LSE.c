// listSE.c
// Exemplos de algoritmos com listas encadeadas

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

// define o tipo de dado a ser colocado na lista
typedef short Tdata; 

//tipo de dado para lista encadeada
typedef  struct TNode
{
	Tdata info; // dado armazenado no nó
	struct TNode *next;	// ponteiro para o próximo nó
} TNode;

typedef struct TListSE
{
	TNode *first;
	TNode *last;
	short length;
} TListSE;

//===========================================
//
// Funções sobre listas encadeadas
//
//===========================================

// Inicialização da lista
void initList(TListSE *L)
{
	L->first = NULL;
	L->last = NULL;
	L->length = 0;
}

// destruição da lista
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

// verifica lista vazia
bool emptyList(TListSE L)
{
	return (L.length == 0);
}

// escreve a lista;

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

// inserção pela esquerda
short insertLeft(Tdata x, TListSE *L)
{
	TNode *aux;
	aux = (TNode*)malloc(sizeof(TNode));
	if (aux == NULL)	// falha na alocação
		return 1;	// sinaliza com erro, deixando a lista original intacta
	else
	{ // insere x na lista
		aux->info = x;					// atribui x para o campo info
		aux->next = L->first;		// insere o elemento antes do atual primeiro
		L->first = aux;					// Faz o ponteiro do primeiro apontar para o novo nó
		if (L->last == NULL)		// lista estava vazia
			L->last = aux;				// primeiro elemento é também o último
		L->length++;						// incrementa o tamanho da lista
		return 0;								// fim normal
	}
}

// Inserção pela direita
short insertRight(Tdata x, TListSE *L)
{
	TNode *aux = (TNode*)malloc(sizeof(TNode));
	if (aux ==NULL)
		return 1;
	else
	{
		aux->info = x;
		aux->next = NULL;
	
		if (L->last == NULL)		// lista está vazia
			L->first = L->last = aux; // atualiza primeiro e último
		else                            // atualiza só o último
		{
			L->last->next = aux;
			L->last = aux;
		}
		L->length++;
		return 0;
	}
}

// insert array

// remoção pela esquerda
void removeFirst(TListSE *L)
{
	TNode *aux = L->first;	// guarda o nó a ser removido em aux
	L->first = L->first->next;	// avança para o próximo nó
	free(aux)	;									// libera aux
	if (L->first == NULL)		// Lista ficou vazia
		L->last = NULL;			// Anula o last também
	L->length--;						// reduz o tamanho
}

// remoção pela direita

void removeLast(TListSE *L)
{
	TNode *aux = L->first;
	
	if (L->first == L->last)		// há apenas um elemento na lista
	{
		free(L->first);					// libera o nó first
		L->last = L->first =NULL;	// anula tudo
	}
	else
	{	// tem mais de um na lista
		while (aux->next->next != NULL)		// procura pelo penúltimo
			aux = aux->next;
		L->last = aux;								// penúltimo é novo último
		free(aux->next);							// libera o último
		L->last->next = NULL;			// anula o nó depois do último
	}
	L->length--;
}

// Busca um elemento na lista
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

// decimal para binário
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



// binário para decimal

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


// inversão de lista

void invertList(TListSE *L)
{
	TNode *ant; // valor anterior ao first - null
	TNode *seg; // valor proximo ao first
	L->last = L->first; // last recebe first
	ant = NULL;
	seg = NULL;

	while(L->first != NULL)
	{
		seg = seg->next;
		L->first->next = ant;
		ant = L->first;
		L->first = seg;
	}

	// first recebe ant
	L->first = ant;
}

/* 
	inserir um elemento em uma posição qualquer da lista
	- se pos == 0 insere na esquerda
	- se pos >= tamanho, insere na direita
	- se 0 < pos < tamanho, insere deslocando os elementos pra trás
*/
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

