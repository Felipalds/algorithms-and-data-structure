#include <stdio.h>

int main()
{

    int x;

    while(scanf("%d", &x) && x > 0)
    {
        for(int i = 1; i <= x; i++) {
            if(i != x) printf("%d ", i);
            else printf("%d\n", i);
        }
    }

    return 0;
}