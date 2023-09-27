/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: Fernado Álvarez de Legísima    LOGIN 1: **********
 * AUTHOR 2: Diego Varela Barral            LOGIN 2: **********
 * GROUP: 3.3
 * DATE: ** / ** / **
 */

#ifndef DYNAMIC_LIST_H
#define DYNAMIC_LIST_H

#include "types.h"

//Aqui nuestro codigo//

#define LNULL NULL

typedef struct Node *tPosL;
typedef tPosL tList;
struct Node {

    tItemL data;
    tPosL next;

};

void createEmptyList(tList *L);

bool isEmptyList(tList L);

tItemL getItem(tPosL p, tList L /* No es necesaria si se usan punteros*/);

void updateItem(tItemL d, tPosL p, tList *L/* No es necesaria si se usan punteros*/);

tPosL first(tList L);

tPosL previous(tPosL p, tList L);

tPosL next(tPosL p, tList L);

tPosL last(tList L);

tPosL findItem(tProductId pId, tList L);

bool insertItem(tItemL d, tPosL p, tList *L);

void deleteAtPosition(tPosL p, tList *L);

void deleteList(tList *L);

//Aqui nuestro codigo//


#endif
