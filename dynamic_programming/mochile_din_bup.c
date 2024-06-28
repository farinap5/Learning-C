#include <stdio.h>
#include <stdlib.h>

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

float mx[4][4];

int pack_bottomUp(int n, int v[], int w[], int W) {
    for (int i = 0; i < W; i++)
        mx[0][i] = 0;

    for (int i = 0; i < n; i++)
        mx[i][0] = 0;
    
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < W; j++) {
            if (w[i] > j) {
                mx[i][j] = mx[i - 1][j];
            } else {
                mx[i][j] = MAX(
                    v[i] + mx[i - 1][j - w[i]],
                    mx[i - 1][j]
                );
            }
        }
    }
    return mx[n][W];
}


int main() {
    int w[] = {1, 2, 3, 4};
    int v[] = {10, 20, 30, 40};
    int capacity = 5;
    int n = sizeof(w) / sizeof(w[0]);

    int max_value = pack_bottomUp(n, v, w, capacity);
    printf("O valor máximo é: %d\n", max_value);
    return 0;
}