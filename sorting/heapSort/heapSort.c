#include <stdio.h>
#include <math.h>

void swap(int *a, int *b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

/*void createHeap(int *v, int len) {
    for (int i = 1; i < log2(len); i++) {
        for (int j = pow(2, i ); j < pow(2, i + 1); j++) {
            if (j%2 == 0) {
                if (v[j/2] < v[j]) {
                    swap(&v[j/2], &v[j]);
                }
            } else {
                if (v[(j-1)/2] < v[j]) {
                    swap(&v[(j-1)/2], &v[j]);
                }
            }
        }
    }
}*/

void heap_descent(int *v, int len, int i) {
    while (i * 2 < len) {
        int aux = 2*i;
        if (aux < len && v[aux + 1] > v[aux]) {
            aux++;
        } 

        if (v[i] < v[aux]) {
            swap(&v[i], &v[aux]);
            i = aux;
        } else {
            i = len + 1;
        }
    }
}

void create_heap(int *v, int len) {
    for (int i = len/2; i >= 0; i--) {
        heap_descent(v, len, i);
    }
}

void heapSort(int *v, int len) {
    create_heap(v, len);
    for (int i = len; i > 1; i--) {
        swap(&v[0], &v[i]);
        heap_descent(v, i-1, 0);
    }
}

int main() {
    int v[8] = {3,4,2,1,6,5,9,7};
    int len = 8;
    heapSort(v,len);
    for (int i = 0; i < len; i++) {
        printf("%d ", v[i]);
    }
}