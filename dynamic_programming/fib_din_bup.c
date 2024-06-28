#include <stdio.h>

int cache[124];

int fib_din_bup(int n) {
    cache[0] = 0;
    cache[1] = 1;
    for (int i = 2; i < n; i++)
        cache[i] = cache[i - 1] + cache[i - 2];
    return cache[n];
}

int main() {
    for (int i = 0; i < 124; i++)
        cache[i] = -1;

    printf("%d\n", fib_din_bup(10));
}