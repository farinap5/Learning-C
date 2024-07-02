#include <stdio.h>
#include <omp.h>
#include <math.h>
#include <time.h>

#include <stdio.h>
#include <omp.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 16
#define NTDS 4

int max(int a, int b) {if (a >= b) {return a;}return b;}

int main() {
    int tid, nt;
    int A[SIZE];
    int B[SIZE * 2];
    int P[SIZE * 2];
    int SPACE = SIZE/NTDS; // espaço geral
    int t = time(NULL);

    for (int i = 0; i < (SIZE * 2); i++) {
        B[i] = 0;
        P[i] = 0;
    }

    srand(t);
    for (int i = 0; i < SIZE; i++) {
        A[i] = (rand() % 100) + 1;
    }

    omp_set_num_threads(NTDS);
    #pragma omp parallel private(tid, nt)
    {
        tid = omp_get_thread_num();
        int down_limit = tid * SPACE;
        int up_limit = down_limit + SPACE;
        for (int i = down_limit; i< up_limit; i++) {
            B[i + SIZE] = A[i];
        }
    }

    for (int i = log2(SIZE)-1; i >= 0; i--) {
        int p = pow(2,i);
        #pragma omp parallel private (tid, nt)
        {
            nt = omp_get_num_threads();
            tid = omp_get_thread_num();
            int space = max(1, p/nt);

            int down_limit = tid * space;
            int up_limit = down_limit + space;

            for (int j = p + down_limit; j < (p + up_limit); j++) {
                B[j] = B[2 * j] + B[2 * j + 1];
            }
        }
    }

    P[1] = B[1];
    for (int i = 1; i <= log2(SIZE); i++) {
        int p = pow(2,i);
        #pragma omp parallel private (tid, nt)
        {
            nt = omp_get_num_threads();
            tid = omp_get_thread_num();
            int space = max(1, p/nt);

            int down_limit = tid * space;
            int up_limit = down_limit + space;
            
            for (int j = p + down_limit; j < (p + up_limit); j++) {
                if (j % 2 == 0) {
                    P[j] = P[j/2] - B[j + 1];
                } else {
                    P[j] = P[(j - 1)/2];
                }
            }
        }
    }

    for (int i = 0; i < SIZE; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    for (int i = 0; i < SIZE*2; i++) {
        printf("%d ", B[i]);
    }
    printf("\n");

    for (int i = 0; i < SIZE*2; i++) {
        printf("%d ", P[i]);
    }
    printf("\nResultado: ");

    for (int i = SIZE; i < SIZE*2; i++) {
        printf("%d ", P[i]);
    }
    printf("\n");

    return 0;
}