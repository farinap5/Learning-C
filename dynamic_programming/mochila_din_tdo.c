#include <stdio.h>
#include <stdlib.h>

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

float mx[4][4];

int pack_topDown(int j, int v[], int w[], int W) {
    if (mx[j][W] == -1) {
        if (w[j] > W) {
            mx[j][W] = pack_topDown(j - 1, v, w, W);
        } else {
            mx[j][W] = MAX(
                v[j] + pack_topDown(j - 1, v, w, W - w[j]),
                pack_topDown(j - 1, v, w, W)
            );
        }
    }
    return mx[j][W];
}

int pack(int n, int v[], int w[], int W) {
	for (int i = 0; i < W; i++) {
        mx[0][i] = 0;
        for (int j = 1; j < W; j++) {
            mx[j][i] = -1;
            mx[j][0] = 0;
        }
    }
    return pack_topDown(n, v, w, W);
}

int main() {
    int w[] = {1, 2, 3, 4};
    int v[] = {10, 20, 30, 40};
    int capacity = 5;
    int n = sizeof(w) / sizeof(w[0]);

    printf("O valor máximo é: %d\n", pack(n, v, w, capacity));

    return 0;
}