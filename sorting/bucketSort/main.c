#include <stdio.h>
#include <stdlib.h>

typedef struct bucket {
    float* data;
} bucket_t;

void swap(float *a, float *b) {
    float aux = *a;
    *a = *b;
    *b = aux;
}

void insertioSort(float *v, int len) {
    if (len == 1) return;
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < i; j++ ) {
            if (v[i] < v[j]) {
                swap(&v[i], &v[j]);
            }
        }
    }
}

void bucketSort(float *v, int len) {

    // Create buckets
    bucket_t *b = (bucket_t *) malloc(len * sizeof(bucket_t));
    for (int i = 0; i < 10; i++) {
        b[i].data = (float *) malloc(len * sizeof(float));
        for (int j = 0; j < len; j++) {
            b[i].data[j] = 0.0;
        }
    }

    // populate buckets
    for (int i = 0;i < len; i++) {
        int x = 0;
        int k = 10 * v[i];
        while (b[k].data[x] != 0.0) x++;

        b[k].data[x] = v[i];
    }

    // Ordenate buckets
    for (int i = 0; i < 10; i++) {
        int x = 0;
        while (b[i].data[x] != 0.0) x++;
        insertioSort(b[i].data, x);
    }

    int i = 0;
    for (int j = 0; j < 10; j++) {
        int x = 0;
        while (b[j].data[x] != 0.0) {
            v[i++] = b[j].data[x++];
        }
    }
}

int main() {
    float v[8] = {0.34,0.4,0.1,0.6,0.31,0.5,0.9,0.7};
    int len = 8;
    bucketSort(v,len);
    for (int i = 0; i < len; i++) {
        printf("%f ", v[i]);
    }
}