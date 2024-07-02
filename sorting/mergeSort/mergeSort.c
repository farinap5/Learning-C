#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void merge(int v[], int s, int k, int e) {
    int *aux;
    aux = malloc((e-s+1) * sizeof(int));

    int i, esq, dir;

    esq = s, dir = k + 1;

    for (i = 0; esq <= k && dir <= e; i++) {
        if (v[esq] <= v[dir])
            aux[i] = v[esq++];
        else 
            aux[i] = v[dir++];
    }

    while (dir <= e)
        aux[i++] = v[dir++];
    while (esq <= k)
        aux[i++] = v[esq++];

    for (i = 0; s + i <= e; i++)
        v[s+i] = aux[i];

    free(aux);
}

void div_comb(int *v, int s, int e) {
    if (s == e) {
        return;
    }

    int k = (s + e)/2;

    div_comb(v, s, k);
    div_comb(v, k+1, e);
    merge(v, s, k, e);
}

void mergeSort(int *v, int len) {
    div_comb(v, 0, len-1);
}

int main() {
    int v[8] = {3,4,2,1,6,5,9,7};
    int len = 8;
    mergeSort(v,len);
    for (int i = 0; i < len; i++) {
        printf("%d ", v[i]);
    }
}