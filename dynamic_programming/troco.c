#include <stdio.h>

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
#define SIZE 5

int M[SIZE];

int moedas(int n) {
    if (n == 0)
        return n;
    else if (n < 0)
        return ~(1<<31);
    int x = ~(1<<31);

    for (int i = 0; i < SIZE; i++) {
        x = MIN(x, moedas(n - M[i]) + 1);
    }
    return x;
}

int main() {
    M[0] = 50;
    M[1] = 25;
    M[2] = 10;
    M[3] =  5;
    M[4] =  1;
    printf("menor: %d\n", moedas(31));
}