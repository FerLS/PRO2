/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 2
 * AUTHOR 1: Fernando Alvarez Legisima LOGIN 1: fernando.alvarezr@udc.es
 * AUTHOR 2: Diego Varela Barral LOGIN 2: diego.vbarral@udc.es
 * GROUP: 3.3
 * DATE: ** / ** / **
 */

#ifndef PRODUCT_LIST_H
#define PRODUCT_LIST_H

#include "types.h"
#include "bid_stack.h"




#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LNULL NULL


typedef struct tItemL {
    tUserId seller;
    tProductId productId;
    tProductCategory productCategory;
    tProductPrice productPrice;
    tBidCounter bidCounter;
    tStack bidStack;
} tItemL;

typedef struct LNode *tPosL;

struct LNode {

    tItemL data;
    tPosL next;

};

typedef tPosL tList;

//Operaciones

void createEmptyList(tList *L);

bool isEmptyList(tList L);

tItemL getItem(tPosL p, tList L /* No es necesaria si se usan punteros*/);

void updateItem(tItemL d, tPosL p, tList *L/* No es necesaria si se usan punteros*/);

tPosL first(tList L);

tPosL previous(tPosL p, tList L);

tPosL next(tPosL p, tList L);

tPosL last(tList L);

tPosL findItem(tProductId pId, tList L);

bool insertItem(tItemL d, tList *L);

void deleteAtPosition(tPosL p, tList *L);

void deleteList(tList *L);

#endif
