#include <stdio.h>

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
#define SIZE 5

int M[SIZE];
int cache[10];

int moedas(int n) {
    if (n == 0)
        return n;
    else if (n < 0)
        return ~(1<<31);
    else if (cache[n] != -1)
        return cache[n];

    int x = ~(1<<31);
    for (int i = 0; i < SIZE; i++) {
        x = MIN(x, moedas(n - M[i]) + 1);
    }
    cache[n] = x;
    return x;
}

int main() {
    for (int i = 0; i < 124; i++)
        cache[i] = -1;

    M[0] = 50;
    M[1] = 25;
    M[2] = 10;
    M[3] =  5;
    M[4] =  1;

    printf("menor: %d\n", moedas(31));
}

/*

╭─farinap@xyz ~/C/dynamics 
╰─$ time ./troco 
menor: 3
./troco  3.11s user 0.00s system 99% cpu 3.112 total
╭─farinap@xyz ~/C/dynamics 
╰─$ time ./troco_din_tdo 
menor: 3
./troco_din_tdo  0.00s user 0.00s system 77% cpu 0.001 total
╭─farinap@xyz ~/C/dynamics 
╰─$ 

*/