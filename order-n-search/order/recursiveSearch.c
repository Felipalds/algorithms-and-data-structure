#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

typedef enum {false, true} bool;

typedef short Tdado;
typedef short Tnum;

void escreve(Tdado V[], Tnum n)
{
	printf("[");
	for (Tnum i = 0; i < n; i++)
	{
		printf("%hd", V[i]);
		if (i < n - 1)
			printf(", ");
	}
	printf("]\n");
}

Tnum seqSearch(Tdado elem, Tdado dados[], Tnum n)
{
	Tdado i;
   for (i = 0; (i < n) && (dados[i] != elem); i++);
	if (i == n) // não achou
		return -1;
	else
		return i;
}

int binSearch(Tdado elem, Tdado dados[], Tnum n)
{
   Tnum lo = 0;
   Tnum hi  = n - 1;
   Tnum i = 0;
   while (lo <= hi)
   {
      i = (lo + hi) / 2;
      if (dados[i] == elem)
         return i; // Achou
      if (elem < dados[i])
         hi  = i - 1; // Pesquisa na metade esquerda
      else
         lo = i +1; // Pesquisa na metade direita
   }
   return -1;
}

int main()
{
    const short MAX = 200;
    Tdado V[SHRT_MAX];
    Tnum n, k, p; // quantidade de números a serem gerados e indice
    clock_t tempo;
    
    scanf("%hd", &n);
        
    srand(time(NULL));	// inicializa o gerador de números aleatórios
    
    printf("Vetor: ");
    for (int i = 0; i < n; i++)
        V[i] = rand() % MAX + 1;
    escreve(V, n);
    
    tempo = clock();

    k = rand() % MAX + 1;
    printf("Procurando por %hd...\n", k);
    p = binSearch(k, V, n);
    if (p < 0)
        printf(" Não encontrado!\n");
    else
        printf("%hd encontrado na posição %hd.\n", k, p); 
        
    return 0;
}