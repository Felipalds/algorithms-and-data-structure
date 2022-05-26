#include <stdio.h>

int calls = 0;
int fibonacci(int n) {
  calls++;
  if (n <= 1) {
    return(n);
  }

  return fibonacci(n-1) + fibonacci(n-2);
}



int main()
{
    int x, k;
    scanf("%d", &k);
    for(int c = 0; c < k; c++){
        calls = 0;
        scanf("%d", &x);
        int fib = fibonacci(x);
        calls--;
        printf("fib(%d) = %d calls = %d\n", x, calls, fib);
    }


    return 0;
}