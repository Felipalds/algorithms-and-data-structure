#include <stdio.h>
#include <stdlib.h>

typedef char TData;
typedef struct TNode{
    TData data;
    struct TNode *next;
} TNode;

typedef struct TStack {
    TNode *first;
    TNode *last;
    short length;
} TStack;

void initStack(TStack *L){
    L->first = NULL;
    L->last = NULL;
    L->length = 0;
}

short push(TData data, TStack *L){
    TNode *aux;
    aux = (TNode*)malloc(sizeof(TNode));
    if(aux == NULL) return 1;
    aux->data = data;
    aux->next = L->first;
    L->first = aux;
    if(L->last == NULL){
        L->last = aux;
    }
    L->length ++;
    return 0;
}

int main(){

    TStack Stack;
    char user_input[1000];
    short counter = 0;
    short isValid = 1;

    initStack(&Stack);

    while(scanf("%[^\n]s", user_input)){
        getchar();
        for(int i = 0; i < 1000; i++){
            if(user_input[i] == '\0') break;
            if(user_input[i] == '('){
                counter++;
            }
            if(user_input[i] == ')'){
                counter--;
            }
            if(counter < 0){
                isValid = 0;
                break;
            }
        }

        if(counter != 0){
            isValid = 0;
        }

        counter == 1 ? printf("correct\n") : printf("incorrect\n");
    }
}