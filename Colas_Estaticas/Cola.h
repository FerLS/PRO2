
#ifndef PILAS_COLA_H
#define PILAS_COLA_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define QNULL -1
#define  Q_MAX 10       //Anda con cuidado con nombres repetidos entre tipos de datos difrentes (deberian tener un prefijo como aqui)
typedef int tItemQ;

typedef struct tQueue{

    tItemQ data[Q_MAX];
    int front;
    int rear;

}tQueue;

void createEmptyQueue(tQueue *Q);

bool enqueue(tItemQ d,tQueue *Q);

void dequeue(tQueue *Q);

tItemQ front(tQueue Q);


bool isEmptyQueue(tQueue Q);
#endif //PILAS_COLA_H
