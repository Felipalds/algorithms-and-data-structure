/*
*   Trabalho de algoritmos
*   Luiz Felipe e João Vitor
*   Exercício 01
*/

#include <stdio.h>

/*
*   fat()
*   função que faz o cálculo do fatorial de forma recursiva
*   entradas: n como o valor do número a ser calculado seu fatorial
*   saidas: o fatorial de n
*/
int fat(int n){
    if (n <= 1)
        return 1;
    n *= fat(n-1);
    return n;
}

int main(){
    unsigned n;
    // leitura dos dados, não deve aceitar valores menores que 0
    while(scanf("%u", &n) && n > 0)
        printf("%d\n", fat(n));
    return 0;
}