#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

typedef struct node
{
    float data;
    struct node *next; 
}node;

void appendElement(node **root,float data, int index){
    node *new = (node*)malloc(sizeof(node));
    new->data = data;
    new->next = NULL;
    if (*root == NULL || index == 0)
    {
        new->next = *root;
        *root = new;
    }else{
        node *curr = *root;
        int num = 1;
        if (index < 0)
        {
            index = INT_MAX;
        }
        while (curr->next!=NULL && num < index){
            curr = curr->next;
            num += 1;
        }
        new->next = curr->next;
        curr->next = new;
    }
}

void removeElement(node **root,int index){
    node *curr = *root;
    if ((*root)->next == NULL || index == 0)
    {
        *root = (*root)->next;
        free(curr);
    }else{
        node *prev = curr;
        int num = 0;
        if (index < 0)
        {
            num = INT_MAX;
        }
        while (curr->next!=NULL && num < index){
            prev = curr;
            curr = curr->next;
            num += 1;
        }
        prev->next = curr->next;
        free(curr);
    }
}

float getElement(node *n,int index){
    int num = 0;
    while (n!=NULL)
    {
        if (num == index)
        {
            return n->data;
        }else{
            n = n->next;
        }
        num += 1;
    }
    return NAN;
}

void printList(node *n){
    while (n != NULL) {
        printf(" %.2f ", n->data);
        n = n->next;
    }
}

void clearList(node *root){
    node * n;
    while (n != NULL) {
        n = root;
        root = root->next;
        free(n);
    }
}

int main(int argc, char const *argv[])
{
    node *list = NULL;
    appendElement(&list,1,-1);
    appendElement(&list,2,-1);
    appendElement(&list,3,0);
    appendElement(&list,4,2);
    appendElement(&list,5,-1);
    removeElement(&list,0);
    removeElement(&list,1);
    printList(list);
    clearList(list);
    return 0;
}
