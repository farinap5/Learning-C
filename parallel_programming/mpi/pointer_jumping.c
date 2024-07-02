#include <stdio.h>
#include <omp.h>
#include <math.h>

#define SIZE 8
#define NTDS 4

int main() {
    /*
         7    6    5    4    3    2    1    0
        [3]->[1]->[5]->[2]->[6]->[4]->[0]->[7]->[NULL]
        
        The position 3 points to 1 (has the value 1)
        The position 1 points to 5 (has the value 5)
        The position 5 points to 2 (has the value 2)

        Distance 1  6  4  7  2  5  3  0
                {7, 5, 6, 1, 0, 2, 4,-1}
    */
    int P[SIZE] = {7, 5, 6, 1, 0, 2, 4, -1};
    int p[SIZE] = {0};
    int D[SIZE] = {0};
    int SPACE = SIZE/NTDS; // espaço geral

    omp_set_num_threads(NTDS);
    #pragma omp parallel for
    for (int i = 0; i < SIZE; i++) {
        p[i] = P[i];
        if (p[i] == -1) {
            D[i] = 0;
        } else {
            D[i] = 1;
        }
    }

    for (int i = 0; i <= log2(SIZE); i++) {
        #pragma omp parallel for // It works! But some times it does not, takuno...
        for (int j = 0; j < SIZE; j++) {
            if (p[j] != -1) {
                D[j] = D[j] + D[p[j]];
                p[j] = p[p[j]];
            }
        }
    }
    // P[1] = B[1];
    /*for (int i = 1; i <= log2(SIZE); i++) {
        #pragma omp parallel private (i)
        {
            #pragma omp for
            for (int j = 0; j < SIZE; j++) {
                if(P[i] != -1) {
                    D_aux[i] = D[i] + D[i];
                    P_aux[i] = P[i];
                }
            }
            
            #pragma omp for
            for (int j = 0; j < SIZE; j++) {
                if (P_aux[i] != -1) {
                    D[i] = D_aux[i];
                    P[i] = P_aux[P_aux[i]];
                }
            }

        *#pragma omp for
            for (int j = 0; j < SIZE; j++) {
                if (j <= SIZE) {
                    if (j+P[j] < SIZE) {
                        #pragma omp atomic
                        D[j] = D[j] + D[j+P[j]];
                        P[j] += P[j+1];
                    }
                }
            }
        }
   }*/

    for (int i = 0; i < SIZE; i++) {
        printf("%d ", D[i]);
    }
    printf("\n");

    return 0;
}