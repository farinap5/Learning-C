#include <stdio.h>

void bubbleSort(int *v, int len) {
    for (int i = 0; i < len; i++) {
        for (int j = i; j < len; j++ ) {
            if (v[i] > v[j]) {
                int aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
        }
    }
}

int main() {
    int v[8] = {3,4,2,45,6,5,9,20};
    int len = 8;
    bubbleSort(v,len);
    for (int i = 0; i < len; i++) {
        printf("%d ", v[i]);
    }
}