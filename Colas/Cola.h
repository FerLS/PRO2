
#ifndef PILAS_COLA_H
#define PILAS_COLA_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define QNULL NULL
typedef int tItemQ;
typedef struct Node *tPosQ;
struct Node {

    tItemQ data;
    tPosQ next;

};

typedef struct tQueue{

    tPosQ front;
    tPosQ rear;

}tQueue;

void createEmptyQueue(tQueue *Q);

bool enqueue(tItemQ d,tQueue *Q);

void dequeue(tQueue *Q);

tItemQ front(tQueue Q);


bool isEmptyQueue(tQueue Q);
#endif //PILAS_COLA_H
