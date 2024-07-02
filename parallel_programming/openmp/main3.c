#include <stdio.h>
#include <omp.h>

int main() {
  int nthreads, tid;
  
  const int n = 20;
  int x = n/4;
  int v[n];

  omp_set_num_threads(4);
  #pragma omp parallel private(nthreads, tid)
  {
    tid = omp_get_thread_num();
    for (int i = 0; i < x; i++) {
      v[(x * tid) + i] = tid;
    }
  }

  for (int i = 0; i < n; i++) {
    printf("%d ",v[i]);
  }
}
