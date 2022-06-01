#include <stdio.h>

int mdc(int num1, int num2) {

    int resto;

    do {
        resto = num1 % num2;

        num1 = num2;
        num2 = resto;

    } while (resto != 0);

    return num1;
}

int main()
{

    int x, a, b;
    scanf("%d", &x);
    for(int c = 0; c < x; c++)
    {
        scanf("%d %d", &a, &b);
        printf("%d\n", mdc(a, b));
    }

    return 0;
}