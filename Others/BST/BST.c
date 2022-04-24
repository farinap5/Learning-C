#include "BST.h"
#include <stdlib.h>
#include <stdio.h>

//typedef struct node {
//    int info;
//    struct node *dir;
//    struct node *esq;
//} Node;

Node *BSTInsert(Node *root, int info) {
    if (root == NULL) {
        Node *tmp = (Node *) malloc(sizeof(Node));
        tmp->esq = NULL;
        tmp->dir = NULL;
        tmp->info = info;
        return tmp;
    }
    if(info > root->info) {
        root->dir = BSTInsert(root->dir,info);
    } else {
        root->esq = BSTInsert(root->esq, info);
    }
    return root;
}

void BSTPreOrder(Node *root) {
    if (root != NULL) {
        printf("%d ",root->info);
        BSTPreOrder(root->esq);
        BSTPreOrder(root->dir);
    }
}

void BSTInOrder(Node *root) {
    if (root != NULL) {
        BSTInOrder(root->esq);
        printf("%d ",root->info);
        BSTInOrder(root->dir);
    }
}

void BSTPosOrder(Node *root) {
    if (root != NULL) {
        BSTPosOrder(root->esq);
        BSTPosOrder(root->dir);
        printf("%d ",root->info);
    }
}

/**
 * @brief In order printing tree that plots a simple 2D tree.
 * @param root
 * @param spc
 */
void BSTPrintTree(Node *root,int spc) {
    if (root != NULL) {
        spc+=1;

        BSTPrintTree(root->esq,spc);

        printf("\n");
        for(int i=0;i<=spc;i++)
            printf("\t\t");

        printf("%d ",root->info);

        BSTPrintTree(root->dir,spc);
    }
}

void BSTTest() {
    printf("aaaa\n");
}

Node *BSTSearch(Node *root, int info) {
    Node *aux = root;
    while (aux != NULL) {
        if (aux->info == info)
            return info;
        if (aux->info > info)
            aux = aux->esq;
        else
            aux = aux->dir;
    }
    return 0;
}

//busca (raiz, k) {
//    if (raiz == NULL || raiz->chave == k)
//        return raiz;
//    else if (k > raiz->chave)
//        return busca(raiz->dir, k);
//    else
//        return busca(raix->esq, k);
//}

//Node *bstest(Node *root, int info) {
//    if (root == NULL) {
//        Node *tmp = (Node *) malloc(sizeof(Node));
//        tmp->info = info;
//        tmp->esq = NULL;
//        tmp->dir = NULL;
//        return tmp;
//    }
//    if (root->info > info) {
//        root->esq = bstest(root->esq,info);
//    } else if (root->info < info) {
//        root->dir = bstest(root->dir,info);
//    }
//}