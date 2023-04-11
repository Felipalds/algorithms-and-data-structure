#include <iostream>

using namespace std;

int main(){

    int first, second, third, time;
    int sum1, sum2, sum3, minor;

    scanf("%d %d %d", &first, &second, &third);

    sum1 = second * 2 + third * 4;
    sum2 = first * 2 + third * 2;
    sum3 = second * 2 + first * 4;

    if(sum1 <= sum2 && sum1 <= sum3){
        minor = sum1;
    }
    if(sum2 <= sum1 && sum2 <= sum3){
        minor = sum2;
        
    }
    if(sum3 <= sum2 && sum3 <= sum1){
        minor = sum3;
        
    }
    printf("%d\n", minor);


    return 0;
}