/**
 * @file q01.cpp
 * @author LUIZ FELIPE E PEDRO ZOZ
 * @brief QUESTÃO 1
 * @version 0.1
 * @date 2023-04-28
 */

#include <iostream>
using namespace std;



int main(){

    int testAmount;
    int testOrder;
    int grandson1, grandson2, sum;
    testOrder = 1;

    while(scanf("%d", &testAmount) && testAmount != 0){
        sum = 0;
        cout << "Teste " << testOrder << endl;

        for(int c = 0; c < testAmount; c++){
            scanf("%d %d", &grandson1, &grandson2);
            sum += (grandson1 - grandson2);
            cout << sum << endl;
        }
        cout << endl;
        testOrder++;
    }
}