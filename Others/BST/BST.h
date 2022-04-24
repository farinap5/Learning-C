#ifndef BST_BST_H
#define BST_BST_H

typedef struct node {
    int info;
    struct node *dir;
    struct node *esq;
} Node;

Node *BSTInsert(Node *root, int info);
void BSTPreOrder(Node *root);
void BSTInOrder(Node *root);
void BSTPosOrder(Node *root);
void BSTPrintTree(Node *root,int spc);
Node *BSTSearch(Node *root, int info);
void BSTTest();

#endif //BST_BST_H
