#include <stdio.h>
#include <stdlib.h>


void countingSort(int *v, int len) {
    int b = 0; // biggest 
    for (int i = 0; i <= len-1; i++)
        b = (b > v[i]) ? b : v[i];

    int *counter = (int *)malloc((b + 1) * sizeof(int));
    for (int i = 0; i < b; i++) counter[i] = 0;

    for (int i = 0; i < len; i++) {
        counter[v[i]]++;
    }

    printf("sum: ");
     for (int i = 0; i <= b; i++) {
        printf("%d ", counter[i]);
    }
    printf("\n");

    // prefix sum
    for (int i = 1; i <= b; i++) {
        counter[i] = counter[i] + counter[i-1];
    }

    printf("prefix: ");
     for (int i = 0; i <= b; i++) {
        printf("%d ", counter[i]);
    }
    printf("\n");

    int *vx = (int *)malloc(len * sizeof(int));
    for (int i = 0; i < len; i++) vx[i] = 0;

    for (int i = len - 1; i >= 0; i--) {
        vx[counter[v[i]]] = v[i];
        counter[v[i]] = counter[v[i]]-1;
    }

    printf("Shifted: ");
     for (int i = 0; i <= b; i++) {
        printf("%d ", counter[i]);
    }
    printf("\n");

    printf("v_x: ");
    for (int i = 0; i <= len; i++) {
        printf("%d ", vx[i]);
    }
    printf("\n");
    for (int i = 1; i <= len; i++) {
        v[i-1] = vx[i];
    }
    free(counter);
    free(vx);
}

int main() {
    int v[8] = {3,4,2,1,6,5,9,7};
    int len = 8;
    countingSort(v,len);
    for (int i = 0; i < len; i++) {
        printf("%d ", v[i]);
    }
}