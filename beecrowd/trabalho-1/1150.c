#include <stdio.h>

int main()
{
    int A, i, s = 0;
    scanf("%d", &A);
    do{
        scanf("%d", &i);
    }
    while(i <= 0);

    for(int c = 0; c < i; c++)
    {
        s += c + A;
    }

    printf("%d\n", s);

    return 0;
}
