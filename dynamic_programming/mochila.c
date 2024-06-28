#include <stdio.h>
#include <stdlib.h>

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

float mx[4][4];
int mem[4][4];

int pack(int n, int i, int W, int w[], int v[]) {
	if(i == n+1) return 0;
	if(mem[i][W]) 
        return mx[i][W];

	mem[i][W] = 1;
	
	mx[i][W] = pack(n,i+1, W, w, v);
	
	if(W >= w[i])
		mx[i][W] = MAX(mx[i][W], pack(n, i+1, W - w[i], w, v) + v[i]);
	
	return mx[i][W];
}

int main() {
    int w[] = {1, 2, 3, 4};
    int v[] = {10, 20, 30, 40};
    int capacity = 5;
    int n = sizeof(w) / sizeof(w[0]);

    int x = pack(4, 1, 5, w, v);
    printf("O valor máximo é: %d\n", x);
    return 0;
}