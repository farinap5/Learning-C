#include <stdio.h>

void shellSort(int *v, int len) {
    int d = len/2;

    while (d > 0) {
        int j = 0;
        while (j + d < len) {
            if (v[j] > v[j+d]) {
                int aux = v[j];
                v[j] = v[j+d];
                v[j+d] = aux;
            }
            j++;
        }
        d = d/2;
    }
}

int main() {
    int v[8] = {3,4,2,45,6,5,9,20};
    int len = 8;
    shellSort(v,len);
    for (int i = 0; i < len; i++) {
        printf("%d ", v[i]);
    }
}