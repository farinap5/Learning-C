#include <stdio.h>
#include <stdlib.h>

void bubbleSort(char **v, int len, int d) {
    for (int i = 0; i < len; i++) {
        for (int j = i; j < len; j++ ) {
            if (v[i][d] > v[j][d]) {
                char *aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
        }
    }
}

void radixSort(char **v, int len) {
    for (int i = 3; i >= 0; i--) {
        bubbleSort(v,len,i);
    }
}

int main() {
    char v[8][4] = {"asd\0", "sas\0", "jsa\0", "kas\0", "pre\0", "osa\0", "xas\0", "adf\0"};
    int len = 8;

    char *vx[8];
    for (int i = 0; i < len; i++) {
        vx[i] = v[i];
    }

    radixSort(vx, len);
    for (int i = 0; i < len; i++) {
        printf("%s\n", v[i]);
    }
}