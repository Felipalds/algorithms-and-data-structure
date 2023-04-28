/**
 * @file q03.cpp
 * @author LUIZ FELIPE E PEDRO ZOZ
 * @brief QUESTÃO 3
 * @version 0.1
 * @date 2023-04-28
 */

#include <iostream>
#include <math.h>
using namespace std;

int main(){
    int hanoiAmount;
    int hanoiCalls;
    int test = 1;

    while(scanf("%d", &hanoiAmount) && hanoiAmount > 0){
        cout << "Teste " << test << endl;
        test++;
        hanoiCalls = pow(2, hanoiAmount) - 1;
        cout << hanoiCalls << endl << endl;
    }
}