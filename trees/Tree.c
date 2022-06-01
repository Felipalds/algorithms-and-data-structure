#include <stdio.h>
#include <stdlib.h>
#include "lse.h"

// ====================
//  IMPRIMINDO ÁRVORE
// ====================
void printBT(TreeNode *bt, short level)
{
    int i;
    if(!bt)
        return;
    else
    {
        printBT(bt->right, level + 1);
        for(i = 0; i < level; i++)
            printf("...|");
        printf("%hd\n", bt->info);
        printBT(bt->left, level + 1);
    }
}

// ====================
//  Inserção na árvore
// ====================
TreeNode* BTinsert(Tdata x, TreeNode *bt)
{
    TreeNode *aux;
    //verifica se a raiz é nula
    if(!bt)
    {
        aux = (TreeNode*)malloc(sizeof(TreeNode));
        if(!aux)
        {
            printf("Erro na alocação \n");
            return NULL;
        }
        else
        {
            aux->info = x;
            aux->left = NULL;
            aux->right == NULL;
            return aux;
        }
    }
    else //raiz não é nula, decide se insere à esquerda ou à direita
        if(x < bt->info)
        {
            bt->left = BTinsert(x, bt->left);
            return bt;
        }
        else
        {
            bt->right = BTinsert(x, bt->right);
            return bt;
        }
}

// \t é uma tabulação, um TAB
int main(){
    TreeNode *BT = NULL; //ponteiro pára a raiz para a arvore
    int op;
    Tdata v;
    TreeNode *found = NULL;
    do
    {
        printf("Árvores Binárias de Busca (BST)\n");
        printf("Árvore atual: \n \n");
        printBT(BT, 0);
        printf("\n\n");
        printf("Selecione a opção desejada: \n\n");
        printf("\t(0)Sair\n");
        printf("\t(1)Inserir elemento\n");
        printf("\t(2)Remover elemento\n");
        printf("\t(3)Procurar elemento\n");
        printf("\t(4)Percurso em largura\n");
        printf("\t(5)Percurso pré-ordem\n");
        printf("\t(6)Percurso em ordem\n");
        printf("\t(7)Percurso pós-ordem\n");
        scanf("%d", &op);

        switch(op){
            case 0:
                printf("Saindo. . .");
                break;
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:

            case 7:
                printf("\t\t >> Percurso em pós-ordem <<\n");
                printf("\n\n");
                break;
        }

    }while(op != 0);
    printf("Limpando a árvore . . .\n");
    //BTclear(BT);
    printf("Árvore limpa! \n");
    return 0;
}
