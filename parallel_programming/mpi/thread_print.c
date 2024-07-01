#include <stdio.h>
#include <omp.h>

/*
This code will fill each array position with is correspondent thread id.

00000000 00000000 00000000 00000000
t0     | t1       t2       t3
|      ^-up_limit
^-down_limit

t0 = thread 0
*/

#define SIZE 40
#define NTDS 4

int main() {
    int tid,tn;
    int v[SIZE];
    int space = SIZE/NTDS;
    printf("SIZE: %d\nNTDS: %d\nSPACE: %d\n", SIZE, NTDS, space);

    omp_set_num_threads(NTDS);
    #pragma omp parallel private(tid, tn)
    {
        tid = omp_get_thread_num();

        int down_limit  = tid * space;
        int up_limit    = down_limit + space;

        for (int i = down_limit; i < up_limit; i++) {
            v[i] = tid;
        }
    }

    for (int i = 0; i < SIZE; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
    
    return 0;
}