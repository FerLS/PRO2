
#ifndef LISTAS_LISTA_H
#define LISTAS_LISTA_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "Cola.h"

#define LNULL NULL


typedef int tItemL;
typedef struct LNode *tPosL;
struct LNode {

    tItemL data;
    tPosL next;

};

typedef tPosL tList;

//Operaciones

void createEmptyList(tList *L);

bool isEmptyList(tList L);

tItemL getItem(tPosL p, *queueP,&prio,&Queue) /* No es necesaria si se usan punteros*/);

void updateItem(tItemL d, tPosL p, tList *L/* No es necesaria si se usan punteros*/);

tPosL first(tList L);

tPosL previous(tPosL p, tList L);

tPosL next(tPosL p, tList L);

tPosL last(tList L);

tPosL findItem(tItemL d, tList L);

bool insertItem(tItemL d, tList *L);

bool createNode(tPosL *p);

void deleteAtPosition(tPosL p, tList *L);

void deleteList(tList *L);

#endif //LISTAS_LISTA_H
