/*
*   Trabalho de algoritmos
*   Luiz Felipe e João Vitor
*   Exercício 03
*/


#include <stdio.h>
#include <stdlib.h>

/*
* Definição de tipos e de structs
* TRacional para o tipo racional num/den
* TData para os dados da lista simplesmente encadeada
* TListSE para a lista simplesmente encadeada 
*/
typedef struct
{
    int num;
    int den;
} TRacional;

typedef struct TNode
{
    TRacional info;
    struct TNode *next;
} TNode;

typedef struct
{
	TNode *first;
	TNode *last;
	short length;
} TListSE;

/*
*   initList()
*   Função que inicia a lista simplesmente encadeada, zerando os valores e evitando possíveis lixos na memória
*   Entradas: ponteiro da lista do tipo definido TListSE
*   Saídas: nenhuma
*/
void initList(TListSE *L)
{
	L->first = NULL;
	L->last = NULL;
	L->length = 0;
}

/*
*   printList()
*   Função que printa a lista de maneira formatada, mostrando numerador/denominador
*   Se denominador for == 1, printa somente 1
*   Entradas: ponteiro da lista TListSE
*   Saídas: nenhuma
*/
void printList(TListSE L)
{
	TNode *p = L.first;
	
	while (p)
	{
		p->info.den == 1 ? printf("1") : printf("%d/%d", p->info.num, p->info.den); // se o denominador for 1, printa 1 por quesitos de output
		if (p->next)
			printf(", ");
		p = p->next;
	}
	printf("\n");
}

/*
*   printInvert()
*   Função que imprime de forma invertida a lista, começando pelo last e indo até o first, de forma recursiva
*   Entradas: ponteiro para o FIRST da lista
*   Saídas: nenhuma
*/
void printInvert(TNode *L)
{
	if(!L) return; // its over
	else{
		printInvert(L->next);
		L->info.den == 1 ? printf("1") : printf(" %d/%d, ",L->info.num, L->info.den);
		return;
	}
}

/*
*   insertRight()
*   Função que insere valores à direita na lista simplesmente encadeada.
*   Entradas: valor que será inserido na lista é do tipo TRacional, contendo um numerador e um denominador
*   Saídas: short que nos diz se a função deu certo ou não deu.
*/
short insertRight(TRacional x, TListSE *L)
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

/*
*   calcList()
*   Função que faz o cálculo de todos os elementos da lista TListSE
*   O cálculo é realizado somando numerador/denominador à uma variável de soma
*   Entrada: endereço de memória para a lista
*   Saída: um double para a soma dos elementos
*/
double calcList(TListSE *L)
{
    TNode *p = L->first;
    double sum = 0;
    while(p)
    {
        sum += (float)p->info.num / (float)p->info.den;
        p = p->next;
    }
    return sum;
}



int main()
{
    TListSE Lista;
    initList(&Lista);
    TRacional value;
    value.num = 1;

    for(int c = 1; c <= 100; c++) // gravação dos dados
    {
        value.den = c;
        insertRight(value, &Lista);
    }
    printf("S = ");
    printList(Lista);
    printf("S =");
    printInvert(Lista.first);
    printf("\n");
    printf("S = %.5lf", calcList(&Lista));
    printf("\n");

    return 0;
}