#include <stdio.h>
#include <pthread.h>

#define SIZE 40
#define NTDS 4

int tid;
int v[SIZE];
int s = 0;

void *sum() {
    int mytid = tid;
    tid++;
    printf("Thread: %d\n", mytid);

    int space = SIZE/NTDS;
    int l_base = mytid * space;
    int l_up = l_base + space;

    for (int i = l_base; i < l_up; i++) {
        s += v[i];
    }
}

int main() {
    pthread_t thread[4];
    int tx[NTDS];

    for (int i = 0; i < SIZE; i++) {
        v[i] = 1;
    }

    for (int i = 0; i < NTDS; i++) {
        tx[i] = pthread_create(&thread[i], NULL, sum, NULL);
    }

    for (int i = 0; i < NTDS; i++) {
        pthread_join(thread[i], NULL);
    }

    printf("Result: %d\n", s);
    return 0;
}