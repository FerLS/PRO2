
#ifndef PILAS_PILA_H
#define PILAS_PILA_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define SNULL NULL
typedef int tItem;
typedef struct Node *tPosS;
struct Node {

    tItem data;
    tPosS next;

};

typedef tPosS tStack;

void createEmptyStack(tStack *stack);

bool push(tItem d,tStack *stack);

void pop(tStack *stack);

tItem peek(tStack stack);

bool isEmptyStack(tStack stack);
#endif //PILAS_PILA_H
