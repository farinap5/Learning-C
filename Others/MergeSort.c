/*
  Merge Sort
  O(n*log n)
*/

#include <stdio.h>
#include <stdlib.h>

void imprime(int v[], int tamanho) {
    int i;
    for (i = 0; i < tamanho; i++)
        printf("%d ", v[i]);
    printf("\n");
}


void merge(int v[], int ini, int meio, int fim) {
    int *aux;
    aux = malloc((fim-ini+1) * sizeof(int));

    int i, esq, dir;

    esq = ini, dir = meio + 1;

    for (i = 0; esq <= meio && dir <= fim; i++) {
        if (v[esq] <= v[dir])
            aux[i] = v[esq++];
        else 
            aux[i] = v[dir++];
    }

    while (dir <= fim)
        aux[i++] = v[dir++];
    while (esq <= meio)
        aux[i++] = v[esq++];

    for (i = 0; ini + i <= fim; i++)
        v[ini+i] = aux[i];

    free(aux);
}

void mergesort(int v[], int ini, int fim) {
    if (ini == fim)
        return;
    
    int meio = (ini + fim)/2;
    mergesort(v, ini, meio);
    mergesort(v, meio+1, fim);
    merge(v, ini, meio, fim);
}

void ordena(int v[], int tamanho) {
    mergesort(v, 0, tamanho-1);
}

int main() {
    int v[] = {3, 8, 5, 2, 4, 7, 1, 6};
    ordena(v, 8);
    imprime(v, 8);
    return 0;
}
