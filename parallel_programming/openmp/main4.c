#include <stdio.h>
#include <omp.h>
#include <math.h>
#include <time.h>

#include <stdio.h>
#include <omp.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 32
#define NTDS 4

int max(int a, int b) {if (a >= b) {return a;}return b;}

int main() {
    int tid, nt;
    int A[SIZE];
    int B[SIZE * 2];
    int SPACE = SIZE/NTDS; // espaço geral
    int t = time(NULL);

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
                B[j] = max(B[2 * j], B[2 * j + 1]);
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
}