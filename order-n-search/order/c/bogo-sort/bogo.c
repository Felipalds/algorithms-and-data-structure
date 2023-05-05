#include <stdio.h>
#include <time.h>
#include <stdlib.h>


    void shuffle(int *a, int n) {
        int i, t, temp;
        for (i = 0;i < n;i++) {
            t = a[i];
            temp = rand() % n;
            a[i] = a[temp];
            a[temp] = t;
        }
    }

    int isSorted(int *a, int n) {
    while (--n >= 1) {
        if (a[n] < a[n - 1]) {
            return 0;
        }
    }
    return 1;
    }


    void bogoSort(int *a, int n) {
        printArr(a);
        while (!isSorted(a, n)) {
            shuffle(a, n);
        }
    }

int main(){

    srand(time(NULL));

    int arr[5] = {5, 2, 1, 3, 4};

    bogoSort(arr, 5);


    return 0;
}