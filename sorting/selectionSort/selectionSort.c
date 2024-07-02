#include <stdio.h>
#include <math.h>

void swap(int *a, int *b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}


void mergeSort(int *v, int len) {
    for (int i = 0; i < len; i++) {
        int aux = i;
        for (int j = i+1; j < len; j++) {
            if (v[aux] > v[j])
                aux = j;
        }
        if (aux != i)
            swap(&v[aux], &v[i]);
    }
}

int main() {
    int v[8] = {3,4,2,1,6,5,9,7};
    int len = 8;
    mergeSort(v,len);
    for (int i = 0; i < len; i++) {
        printf("%d ", v[i]);
    }
}