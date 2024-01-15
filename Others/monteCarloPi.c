#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

float Pi(int p, int t, int d) {
    int a = 5;
    srand(time(NULL)+(a*p));

    for (int i = 0; i < t; i++) {
        float x = ((float)(rand()%1000) / 1000.0);
        float y = ((float)(rand()%1000) / 1000.0);
        if ((x*x + y*y) < 1) {
            d+=1;
        }
    }

    float prob = (4.0 * d)/t;
    return prob;
}

int main() {
    int d = 0;
    int t = 100000000;
    int w = -1;
    char *fname = "cfile.n";
    
    int f = fork();
    if (f == 0) { // child
        FILE *fptr;
        fptr = fopen(fname, "w");
        float x = Pi(f,t,d);
        fwrite(&x, 1, sizeof(x), fptr);
        //printf("%f\n",x);
    } else {
        float pi = Pi(f,t,d);
        wait(&w);
        float xf;
        FILE *fptr;
        fptr = fopen(fname, "r");
        fread(&xf,1,sizeof(xf),fptr);
        //printf("%f\n",xf);
        float pir = (xf+pi)/2;
        printf("Pi f:%f Pi c:%f Pi:%f\n", pi, xf, pir);
        remove(fname);
    }
}
/*
  A = πr^2
  se r=1, estão A = π

  P = (Adentro ou π)/Atotal
  π = P . Atotal

  se raiz(x^2 + y^2) = 1 -> x^2 + y^2 = 1
  então x^2 + y^2 < 1 está dentro do circulo.
  
  O id do processo filho sempre será 0 pro filho;
*/