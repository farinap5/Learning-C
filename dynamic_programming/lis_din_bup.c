#include <stdio.h>

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

int num[124];
int cache[124];

int lis(int n) {
    if (n == 0) {
        return 1;
    } else {
        int x = 1;
        for (int i = 0; i < n; i++) {
            if (num[i] < num[n]) {
                x = MAX(x, lis(i)+1);
            }
        }
        return x;
    }
}

int subsequencia_crescente_mais_longa(int n) {
    for (int i = 0; i < 124; i++)
        cache[i] = 1;

    int x = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (num[j] < num[i])
                cache[i] = MAX(cache[i], cache[i] + 1);
            
        }
        x = MAX(x, lis(i));
    }
    return x;
}

int main() {
    for (int i = 0; i < 124; i++) 
        num[i] = 0;

    num[0] = 3, num[1] = 10, num[2] = 2, num[3] = 11,
    num[4] = 5,  num[5] = 7, num[6] = 9; num[7] =  4;
    printf("%d\n", subsequencia_crescente_mais_longa(10));
}