/**
 * @file q02.cpp
 * @author LUIZ FELIPE E PEDRO ZOZ
 * @brief QUESTÃO 2
 * @version 0.1
 * @date 2023-04-28
 */

#include <iostream>
#include <vector>
using namespace std;



int main(){
    int studentAmount;
    int testAmount;
    testAmount = 1;
    while(scanf("%d", &studentAmount) && studentAmount > 0){
        vector<int> bestDegrees;

        int bestDegree = 0;
        for(int c = 0; c < studentAmount; c++){
            int id, note;
            scanf("%d %d", &id, &note);
            if(note == bestDegree){
                bestDegrees.push_back(id);
            }
            if(note > bestDegree){
                bestDegree = note;
                bestDegrees.clear();
                bestDegrees.push_back(id);
            }
        }
        cout << "Turma " << testAmount << endl;
        for(int c = 0; c < bestDegrees.size(); c++){
            cout << bestDegrees[c] << " ";
        }
        cout << endl << endl;
        testAmount ++;
    } 

}