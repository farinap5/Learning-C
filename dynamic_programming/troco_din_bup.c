#include <stdio.h>

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
#define SIZE 5

int M[SIZE];
int cache[10];

int moedas(int n) {
    cache[0] = 0;
    for (int i = 1; i < n; i++)
        cache[i] = ~(1<<31);

    for (int i = 0; i < n; i++) {
        for (int j = 1; j < SIZE; j++) {
            if (i >= M[j])
                cache[i] = MIN(cache[i], moedas(n - M[j]) + 1);
        }
    }
    return cache[n];
}

int main() {

    M[0] = 50;
    M[1] = 25;
    M[2] = 10;
    M[3] =  5;
    M[4] =  1;
    printf("menor: %d\n", moedas(31));
}