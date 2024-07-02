#include <stdio.h>

void swap(int *a, int *b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

void div_conp(int *v, int s, int e) {
    int pivot = s;
    int l = s+1;
    int r = e;
    
    while (l <= r) {
        /*
        pl3,4,2,1,6,5,9,r7
        pl3,4,2,1,6,5,r9,7
        pl3,4,2,1,6,r5,9,7
        pl3,4,2,1,r6,5,9,7
        pl3,4,2,r1,6,5,9,7
  swap  pl1,4,2,r3,6,5,9,7
        */
        while (v[l] < v[pivot])
            l++;
        while (v[r] >= v[pivot])
            r--;
        
        if (l <= r) {
            swap(&v[l], &v[r]);
            l++;
            r--;
        }
    }
    swap(&v[pivot], &v[r]);

    if (s < r)
        div_conp(v, s, r - 1);
    if (l < e)
        div_conp(v, l + 1, e);
}

void quickSort(int *v, int len) {
    div_conp(v, 0, len-1);
}

int main() {
    int v[8] = {3,4,2,1,6,5,9,7};
    int len = 8;
    quickSort(v,len);
    for (int i = 0; i < len; i++) {
        printf("%d ", v[i]);
    }
}