#include <stdio.h>
#include <stdlib.h>

#include "BST.h"

int main() {
    ///BSTTest();
    Node *root = (Node *) malloc(sizeof(Node));

//    BSTInsert(root,60);
//    BSTInsert(root,80);
//    BSTInsert(root,30);
//    BSTInsert(root,50);
//    BSTInsert(root,90);
//    BSTInsert(root,20);
//    BSTInsert(root,70);
//    BSTInsert(root,40);
    //BSTInsert(root,36);
    BSTInsert(root,10);
    BSTInsert(root,6);
    BSTInsert(root,7);
    BSTInsert(root,12);
    BSTInsert(root,20);
    BSTInsert(root,15);
    BSTInsert(root,5);

    printf("Pre Order: ");
    BSTPreOrder(root);
    printf("\nIn Order:  ");
    BSTInOrder(root);
    printf("\nPos Order: ");
    BSTPosOrder(root);

    printf("\n\n\n");
    BSTPrintTree(root,0);
    return 0;
}

//          20
//     30
//               40
//          50
//60
//          70
//     80
//          90

