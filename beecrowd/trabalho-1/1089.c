#include <stdio.h>

void cleanVector(void)
{
    for(int c = 0; c < 10000; c++) V[c] = 0;
}

int main()
{

    int k;
    int V[10000];
    while(scanf("%d", &k) && k != 0)
    {
        cleanVector();
        for(int c = 0; c < k; c++) scanf("%d", &V[c]);


    }


    return 0;
}