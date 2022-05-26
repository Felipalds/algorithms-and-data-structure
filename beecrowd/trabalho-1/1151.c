#include <stdio.h>

int V[47];

int fibonacci(int n, int c)
{
    int f0 = 0;
    int f1 = 1;
    int fib = 1;
    V[0] = 0;
    V[1] = 1;
    if(n == 0) fib = 0;
    if(n == 1|| n == 2){
        fib = 1;
    } else {
       for(int k = 3; k <= n ; k++){
        fib = f1 + f0; 
        V[c] = fib;
        c++;
        f0 = f1;
        f1 = fib;
       }
    }
}

int main()
{

    int x = 0;
    scanf("%d", &x);
    fibonacci(x, 2);

    for(int i = 0; i < x; i++)
    {
        if(i == 0) printf("%d", V[i]);
        else printf(" %d", V[i]);
        

    }
    printf("\n");


    return 0;
}