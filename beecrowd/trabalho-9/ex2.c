/*
*   Trabalho de algoritmos
*   Luiz Felipe e João Vitor
*   Exercício 02
*/


#include <stdio.h>
#include <stdlib.h>


/*
*   Definição da struct do vetor dinâmico
*   dados é o vetor em si
*   len é o tamanho do vetor dinâmico, alterado cada vez que o usuário digita um valor
*/
typedef struct
{
        int *dados;
        unsigned len;
} TVetDin;

/*
*   initVet()
*   Função que inicia o vetor, alocando size posições
*   Entradas: endereço para o vetor, size para o tamanho de posições (neste exercício será 0)
*   Saídas: void
*/
void initVet(TVetDin *V, unsigned size)
{
        V->dados = (int*)malloc(size*sizeof(int)); // alocação dinamica
        if(!V->dados)
        {
                printf("Erro: Memória insuficiente!\n");
                exit(1);
        }
        else
        {
                V->len = size;
                return;
        }
}

/*
*   realocVet()
*   Função que faz a realocação do vetor, alterando o número de posições que o vetor dinâmico terá
*   Entradas: endereço do vetor dinâmico
*   Saída: void
*/
void realocVet(TVetDin *V)
{
    unsigned newSize = V->len + 1;
    V->dados = (int*)realloc(V->dados, newSize*sizeof(int)); // realocação dinamica
    if(!V->dados)
    {
            printf("Erro: Memória insuficiente");
            exit(1);
    }
    V->len = newSize;
    return;
}

int main()
{
    short sum = 0;
    short acima, abaixo = 0;
    TVetDin Vet;
    initVet(&Vet, 0);
    short x;
    // leitura dos dados. não deve aceitar valores negativos
    while (scanf("%hd", &x) && x >= 0){
        sum += x;
        realocVet(&Vet);
        Vet.dados[Vet.len-1] = x;
    }
    
    // Cálculo da média
    float media = (float)sum / Vet.len;

    // For para achar quantos valores são acima ou abaixo da média
    for(int c = 0; c < Vet.len;c++){
        if(Vet.dados[c] > media) acima++;
        if(Vet.dados[c] < media) abaixo++;
    }

    printf("Média = %.2f \n", media);
    printf("Acima = %hd \n", acima);
    printf("Abaixo = %hd \n", abaixo);
    return 0;
}