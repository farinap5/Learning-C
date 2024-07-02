#include <stdio.h>
#include <pthread.h>
#include <time.h>
#include <stdlib.h>
#include <semaphore.h>

#define NFI 5
#define COM_FOME 1
#define PENSANDO 2
#define COMENDO 3

sem_t mutex;
sem_t Filosofo[NFI];
int estado[NFI];
int x = 0;

void testa(int i) {
    if (estado[i] == COM_FOME && estado[(i - 1) % NFI] != COMENDO && estado[(i + 1) % NFI] != COMENDO) {
        estado[i] = COMENDO;
        sem_post(&Filosofo[i]);
    }
}

void pega_garfo(int i) {
    sem_wait(&mutex);
    estado[i] = COM_FOME;
    testa(i);
    sem_post(&mutex);
    sem_wait(&Filosofo[i]);
}

void devolve_garfo(int i) {
    sem_wait(&mutex);
    estado[i] = PENSANDO;
    testa((i-1) % NFI);
    testa((i+1) % NFI);
    sem_post(&mutex);
    sem_wait(&Filosofo[i]);
}

void *filosofo() {
    int i = x++;
    int fim = 0;
    while (fim < 5) {
        printf("Filosofo %d pensando\n",i);
        pega_garfo(i);
        printf("Filosofo %d comendo\n",i);
        devolve_garfo(i);
        fim++;
    }
}

int main() {
    pthread_t thread[NFI];
    int tx[NFI];
    sem_init(&mutex, 0, 1);
    
    for (int i = 0; i < NFI; i++) {
        sem_init(&Filosofo[i], 0, 1);
    }

    for (int i = 0; i < NFI; i++) {
        int *aux = malloc(sizeof(*aux));
        *aux = i;
        tx[i] = pthread_create(&thread[i], NULL, filosofo, aux);
    }

    for (int i = 0; i < NFI; i++) {
        pthread_join(thread[i], NULL);
    }
    //pthread_join(threadx, NULL);
    return 0;
}