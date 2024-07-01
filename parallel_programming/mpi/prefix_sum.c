#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

#define VSIZE 16
#define NPROC 4
#define WORK VSIZE/NPROC

int main(int argc, char **argv) {
    MPI_Init(&argc, &argv);

    int r, s;
    int v[VSIZE] = { 1, 2, 3, 4, 5, 2, 4, 5, 7, 8, 3, 4, 1, 6, 4, 1};
    //               1, 3, 6,10,15,17,21,26,33,41,44,48,49,55,59,60
    int sum = 0;

    MPI_Comm_rank(MPI_COMM_WORLD, &r);
    MPI_Comm_size(MPI_COMM_WORLD, &s);

    // broadcast
    MPI_Scatter(v, WORK, MPI_INT, v, WORK, MPI_INT, 0, MPI_COMM_WORLD);

    for (int i = 0; i < WORK; i++)
        sum += v[i];
    
    int sum_l = 0;
    // prefix reduction
    MPI_Scan(&sum, &sum_l, 1, MPI_INT, MPI_SUM, MPI_COMM_WORLD);

    int sum_x[WORK];
    sum_x[0] = sum_l - sum + v[0];
    
    for (int i = 1; i <= WORK; i++)
        sum_x[i] = sum_x[i-1] + v[i];

    for (int i = 0; i < WORK; i++)
        printf("s[%d=(%2d general context)]=%2d for rank %d\n", 
        i, (r * WORK + i), sum_x[i], r);

    MPI_Finalize();
}

/*
s[0=( 8 general context)]= 9 for rank 2
s[1=( 9 general context)]=10 for rank 2
s[2=(10 general context)]=11 for rank 2
s[3=(11 general context)]=12 for rank 2
s[0=( 0 general context)]= 1 for rank 0
s[1=( 1 general context)]= 2 for rank 0
s[2=( 2 general context)]= 3 for rank 0
s[3=( 3 general context)]= 4 for rank 0
s[0=( 4 general context)]= 5 for rank 1
s[1=( 5 general context)]= 6 for rank 1
s[2=( 6 general context)]= 7 for rank 1
s[3=( 7 general context)]= 8 for rank 1
s[0=(12 general context)]=13 for rank 3
s[1=(13 general context)]=14 for rank 3
s[2=(14 general context)]=15 for rank 3
s[3=(15 general context)]=16 for rank 3
//~~~~~~~~~~~~~~~~~//~~~~~~~~~~~~~~~~//
s[0=( 4 general context)]=15 for rank 1
s[1=( 5 general context)]=17 for rank 1
s[2=( 6 general context)]=21 for rank 1
s[3=( 7 general context)]=26 for rank 1
s[0=( 8 general context)]=33 for rank 2
s[1=( 9 general context)]=41 for rank 2
s[2=(10 general context)]=44 for rank 2
s[3=(11 general context)]=48 for rank 2
s[0=( 0 general context)]= 1 for rank 0
s[1=( 1 general context)]= 3 for rank 0
s[2=( 2 general context)]= 6 for rank 0
s[3=( 3 general context)]=10 for rank 0
s[0=(12 general context)]=49 for rank 3
s[1=(13 general context)]=55 for rank 3
s[2=(14 general context)]=59 for rank 3
s[3=(15 general context)]=60 for rank 3
*/