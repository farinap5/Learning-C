#include <stdio.h>

int fib_din_tdo(int n) {
    if (n == 0 || n == 1) {
        return n;
    } else {
        return fib_din_tdo(n - 1) + fib_din_tdo(n - 2);
    }
}

int main() {
    printf("%d\n", fib_din_tdo(6));
}