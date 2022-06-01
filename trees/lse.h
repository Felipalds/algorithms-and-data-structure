/*
   Escrever uma função void split que recebe uma lista L1 e divida em duas Listas, indo de first até pos -1 e L2 iniciando em pos - limpe L2 antes
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

typedef unsigned short Tdata;

typedef struct TreeNode
{
    Tdata info;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

typedef  struct TNode
{
	TreeNode *info;
	struct TNode *next;
} TNode;

typedef struct TListSE
{
	TNode *first;
	TNode *last;
	short length;
} TListSE;

void initList(TListSE *L);

void deleteList(TListSE *L);

bool emptyList(TListSE L);

void printList(TListSE L);

short insertRight(TreeNode *x, TListSE *L);

void removeFirst(TListSE *L);

TreeNode* head(TListSE L);
