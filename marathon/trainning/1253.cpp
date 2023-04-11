#include <iostream>
using namespace std;

int main(){
    string c;
    char newc[100];
    int len, rule;

    cin >> rule;
    cin >> c;

    for(int j = 0; c[j] != '\0'; j++){
        newc[j] = c[j] - rule;
        if(newc[j] < 65){
            newc[j] = newc[j] + 26;
        }
        if(newc[j] > 90){
            newc[j] = newc[j] - 26;
        }
    }
    cout << newc;
}