#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
  int l = 0;
  while (1) {
    printf("[\x1b[31m*\x1b[0m]> ");
    scanf("%d",&l);
  
    int a[l][l];
    srand(time(NULL));
  
    for (int i = 0; i < l; i++) {
      for (int j = 0; j < l; j++) {
        int r = rand()%2;
        a[i][j] = r;
      }
    }

    for (int i = 0; i < l; i++) {
      printf("\x1b[31m%d\x1b[0m ",i+1);
    }

    printf("\n\n");
    
    for (int i = 0; i < l; i++) {
      for (int j = 0; j < l; j++) {
        //int r = rand()%2;
        if (a[i][j] == 1) {
          printf("\033[35m%d\033[0m ",a[i][j]);
        } else {
          printf("%d ",a[i][j]);
        }
        if (j == l-1) {
          printf("  \x1b[31m%d\x1b[0m\n",i+1);
        }
      }
    }

    printf("\n");
    int o = 0;
    printf("[N]> ");
    scanf("%d",&o);
    
    for(int i = 0;i<l;i++) {
      if(a[o-1][i] == 1) {
        printf("%d has connection with -> %d\n",o,i+1);
      }
    }
    
  }
}