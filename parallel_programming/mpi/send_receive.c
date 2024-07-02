#include <stdio.h>
#include <mpi.h>

#define SIZE 16

int main(int argc, char **argv) {
    int v[SIZE] = {3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3};
    int sum;
    int r = 0;
    int nproc = 0;
    int dest = 0;
    int tag = 369;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &r);
    MPI_Comm_size(MPI_COMM_WORLD, &nproc);
    
    int spec = SIZE/nproc;
    int g = spec * r;
    int u = g + spec;

    for (int i = g; i < u; i++) sum += v[i];

    if (r > 0) {
        MPI_Send(&sum, 1, MPI_INT, dest, tag, MPI_COMM_WORLD);
    } else {
        MPI_Status stts;
        int c = 0;
        for(int i = 1; i < nproc; i++) {
            int aux = 0;
            int src = 0;
            MPI_Recv(&aux, 1, MPI_INT, src, tag, MPI_COMM_WORLD, &stts);
            printf("data from %d %d on %d\n", src, SIZE, aux);
            c += aux;
        }
        c += sum;
        printf("The sum is %d\n", c);
    }

    MPI_Finalize();
}