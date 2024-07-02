#include <stdio.h>
#include <omp.h>
#include <math.h>

int max(int a, int b) {
  if (a > b) {
    return a;
  }
  return b;
}

int min(int a, int b) {
  if (a < b) {
    return a;
  }
  return b;
}


int main() {
  int nthreads, tid;
  const int n = 8;
  int A[] = {4,2,6,3,8,1,7,5};
  int B[(n * 2)];

  omp_set_num_threads(4);
  #pragma omp parallel private (nthreads, tid) 
  {
    nthreads = omp_get_num_threads();
    tid = omp_get_thread_num();
    int space = n/nthreads;

    int l_limit = tid * space;
    int u_limit = (tid + 1) * space;

    for (int i = l_limit; i < u_limit; i++) {
      B[(n + i)] = A[i];
    }
  }

  for (int i = log2(n)-1; i >= 0; i--) {
    int s = (int)pow(2,i);

    #pragma omp parallel private (nthreads, tid)
    {
      nthreads = omp_get_num_threads();

      tid = omp_get_thread_num();
      int space = max(1,s/nthreads);

      int l_limit = tid * space;
      int u_limit = (tid + 1) * space;

      int m = 0;

      if (u_limit <= s) {
        for (int j = s+l_limit; j < s+u_limit; j++) {
          //printf("%d\n",B[j]);
          //printf("i = %d, j = %d\n",i, j);

          B[j] = max(B[2*j], B[(2*j)+1]);
        }
      }
      //printf("%d\n",m);
    }
  }

  for (int i = 0; i < (n * 2); i++) {
    printf("%d ", B[i]);
  }
  printf("\n");

  printf("Max = %d\n", B[1]);
 
  return 0;
}
