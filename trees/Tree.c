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

// ===================
//  Remoção da árvore
// ===================
TreeNode *BTdelete(Tdata x, TreeNode *bt)
{
    TreeNode *p, *p2;
    if(bt->info == x)
    {
        if(bt->left == bt->right)
        {
            free(bt);
            return NULL;
        }
        else 
        {
            if(bt->left == NULL)
            {
                p = bt->right;
                bt = NULL;
            }
        }
    }
}

TreeNode* BTsearch(Tdata x, TreeNode *bt)
{
    if(bt == NULL)
        return 0;
    else if (bt->info == x)
        return bt;
    else if(x < bt->info)
        return BTsearch(x, bt->left);
    else
        return BTsearch(x, bt->right);
}

void BreadthFirst(TreeNode *bt)
{
    TreeNode *raiz = bt;
    TListSE fila;

    initList(&fila);
    if(raiz != NULL)
    {
        insertRight(raiz, &fila); // insere a raiz na fila
        while(!emptyList(fila))
        {
            raiz = head(fila); //pega o elemento na cabeça da fila
            removeFirst(&fila);
            printf("%hd", raiz->info); //imprime
            if(raiz->left != NULL)
                insertRight(raiz->left, &fila);
            if(raiz->right != NULL)
                insertRight(raiz->right, &fila);
        }
    }
}

void PreOrder(TreeNode *bt)
{
    if(bt == NULL)
        return;
    else
    {
        printf("%hd ", bt->info);
        PreOrder(bt->left);
        PreOrder(bt->right);
    }
}

void InOrder(TreeNode *bt)
{
    if(bt == NULL)
        return;
    else
    {
        InOrder(bt->left);
        printf("%hd ", bt->info);
        InOrder(bt->right);
    }
}

void PostOrder(TreeNode *bt)
{
    if(bt == NULL)
        return;
    else
    {
        PostOrder(bt->left);
        PostOrder(bt->right);
        printf("%hd ", bt->info);

    }
}

short HeightTree(TreeNode *bt)
{
    if(bt == NULL)
        return 0;
    else
    {
        short valueLeft = HeightTree(bt->left);
        short valueRight = HeightTree(bt->right);
        if(valueLeft > valueRight)
            return 1 + valueLeft;
        else
            return 1 + valueRight;
    }
}

short LengthTree(TreeNode *bt)
{
    if(bt == NULL)
        return 0;
    else
    {
        if(bt->left == bt->right) return 1;
        else return (LengthTree(bt->left) + LengthTree(bt->right));
    }
}

short NodeHeight(TreeNode *bt, short value)
{
    if(bt == NULL)
        return 0;
    else if (bt->info == value)
        return 1;
    else if(value < bt->info)
        return 1 + NodeHeight(bt->left, value);
    else
        return 1 + NodeHeight(bt->right, value);
}

short NodeDistance(TreeNode *bt, short x, short y)
{
    if(bt == NULL)
        return 0;
    else if(bt->info > x && bt->info > y)
        NodeDistance(bt->left, x, y);
    else if(bt->info < x && bt->info < y)
        NodeDistance(bt->right, x, y);
    else
    {
        short h1 = NodeHeight(bt, x) - 1;
        short h2 = NodeHeight(bt, y) - 1;
        return h1 + h2;
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
        printf("\t(8)Altura da árvore\n");
        printf("\t(9)Largura da árvore\n");
        printf("\t(10)Altura do nó\n");
        printf("\t(11)Distâncias entre nós\n");


        scanf("%d", &op);

        switch(op){
            case 0:
                printf("Saindo. . .");
                break;
            case 1:
                printf("Qual valor? >>");
                scanf("%hu", &v);
                BT = BTinsert(v, BT);
                break;
            case 2:
                printf("Qual valor? >>");
                scanf("%hu", &v);
                BT = BTdelete(v, BT);
                break;
            case 3:
                printf("Qual valor? >>");
                scanf("%hu", &v);
                found = BTsearch(v, BT);
                if(found)
                    printf(">>> Valor encontrado no endereço %p <<<\n", found);
                else 
                    printf(">>> Valor não encontrado <<< \n");
                break;
            case 4:
                printf("\t\t>> Percurso em largura <<\n");
                BreadthFirst(BT);
                printf("\n\n");
                break;
            case 5:
                printf("\t\t>> Percurso em pré-ordem <<\n");
                PreOrder(BT);
                printf("\n\n");
                break;
            case 6:
                printf("\t\t>> Percurso em ordem <<\n");
                InOrder(BT);
                printf("\n\n");
                break;
            case 7:
                printf("\t\t >> Percurso em pós-ordem <<\n");
                PostOrder(BT);
                printf("\n\n");
                break;
            case 8:
                printf("\t\t >> Altura da árvore << \n");
                printf("%hd", HeightTree(BT));
                printf("\n\n");
                break;
            case 9:
                printf("\t\t >> Largura da árvore << \n");
                printf("%hd", LengthTree(BT));
                printf("\n\n");
                break;
            case 10:
                printf("\t\t >> Altura do nó << \n");
                short value;
                scanf("%hd", &value);
                printf(" > > > > Altura é: %hd\n\n", NodeHeight(BT, value));
            case 11:
                printf("\t\t >> Distância entre dois nós << \n");
                short value1, value2;
                scanf("%hd %hd", &value1, &value2);
                printf(" > > > Distância é: %hd \n \n", NodeDistance(BT, value1, value2));
        }

    }while(op != 0);
    
    printf("Limpando a árvore . . .\n");
    //BTclear(BT);
    printf("Árvore limpa! \n");
    return 0;
}
