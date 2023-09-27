/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: ***************************** LOGIN 1: **********
 * AUTHOR 2: ***************************** LOGIN 2: **********
 * GROUP: *.*
 * DATE: ** / ** / **
 */

#ifndef STATIC_LIST_H
#define STATIC_LIST_H
#define MAX 25
#define LNULL -1 // negativo, valor que nunca tiene ninguna posicion 0...MAX

#include "types.h"

//Nuestro codigo//
#include <stdbool.h>

typedef int tPosL;
typedef struct {
    tItemL data[MAX];
    tPosL lastPos;
} tList;


void createEmptyList(tList *L);

bool isEmptyList(tList L);

tItemL getItem(tPosL p, tList L);

void updateItem(tItemL d, tPosL p, tList *L);

tPosL first(tList L);

tPosL previous(tPosL p, tList L);

tPosL next(tPosL p, tList L);

tPosL last(tList L);

bool copyList(tList L, tList *M);

bool insertItem(tItemL d, tPosL p, tList *L);

tPosL findItem(tProductId pID, tList L);

void deleteAtPosition(tPosL p, tList *L);
//Nuestro codigo//
#endif
