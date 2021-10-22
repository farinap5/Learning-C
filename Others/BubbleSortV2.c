/*
    O(n) = n²
           2
    Bubble Sort
*/

#include <stdio.h>

void swap(int x[], int i, int j) {
    int aux = x[i];
    x[i] = x[j];
    x[j] = aux;
}

void sort(int v[], int n) {
    int min, aux;

    for (int i = 0;i < n-1;i++) {
        int mp = v[i];
        min = i;

        for (int j = i+1;j < n; j++) {
            if (v[j] < mp) {
                mp = v[j];
                min = j;
            }
        }
    swap(v, i, min);
    }
}

int main(void) {
    int n = 6;
    int v[] = {4,6,3,2,7,9,1};
    sort(v,6);
    
    for (int i = 0;i < n;i++) {
        printf("%d ",v[i]);
    }
    printf("\n");

    return 0;
}
