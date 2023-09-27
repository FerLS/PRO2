
#ifndef PILAS_PILA_H
#define PILAS_PILA_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define SNULL -1
#define MAX 10
typedef int tItem;
typedef int tPosS;
typedef struct {

    tItem data[MAX];
    tPosS top;

}tStack;


void createEmptyStack(tStack *stack);

bool push(tItem d,tStack *stack);

tItem peek(tStack stack);

bool isEmptyStack(tStack stack);

void pop(tStack *stack);

#endif //PILAS_PILA_H
