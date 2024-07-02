#include <stdio.h>
#include <pthread.h>
#include <time.h>
#include <stdlib.h>
#include <semaphore.h>

#define BSIZE 8

int buff[BSIZE];
int in = 0;
int out = 0;

sem_t mutext;
sem_t v;
sem_t c;

void produtor() {
    int fim = 1;
    int count = 0;
    int t = time(NULL);
    srand(t);
    while (fim) {
        sem_wait(&v);
        sem_wait(&mutext);
        if (count == 20) {
            buff[in] = 15;
            printf("End Produtor\n");
            fim = 0;
        } else {
            int n = rand() % 10;
            buff[in] = n;
            in = (in + 1) % BSIZE;
        }
        sem_post(&mutext);
        sem_post(&c);

        count++;
    }
}

void consumidor() {
    int fim = 1;
    while (fim) {
        sem_wait(&c);
        sem_wait(&mutext);
        int d = buff[out];
        printf("Data=%d out=%d\n", d, out);
        if (d == 15) {
            printf("End Consumidor\n");
            fim = 0;
        }
        out = (out + 1) % BSIZE;
        sem_post(&mutext);
        sem_post(&v);
    }
}

int main() {
    pthread_t thread1;
    pthread_t thread2;
    sem_init(&mutext, 0, 1);
    sem_init(&v, 0, 1);
    sem_init(&c, 0, 1);

    pthread_create(&thread1, NULL, produtor, NULL);
    pthread_create(&thread2, NULL, consumidor, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    return 0;
}