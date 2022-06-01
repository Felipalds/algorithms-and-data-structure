#include <stdio.h>

int main()
{
    int x, z, s, k = 1;

    scanf("%d", &x);
    do scanf("%d", &z);
    while(z <= x);

    s = x;
    do{
        s += x + k;
        k++;
    }while(s <= z);

    printf("%d\n", k);

    return 0;
}