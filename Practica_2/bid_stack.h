/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 2
 * AUTHOR 1: ***************************** LOGIN 1: **********
 * AUTHOR 2: ***************************** LOGIN 2: **********
 * GROUP: *.*
 * DATE: ** / ** / **
 */

#ifndef BID_STACK_H
#define BID_STACK_H

#include "types.h"

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define SNULL -1
#define SMAX 10
typedef struct tItemS{

    tUserId bidder;
    tProductPrice productPrice;


}tItemS;

typedef int tPosS;
typedef struct {

    tItemS data[SMAX];
    tPosS top;

}tStack;


void createEmptyStack(tStack *stack);

bool push(tItemS d,tStack *stack);

tItemS peek(tStack stack);

bool isEmptyStack(tStack stack);

void pop(tStack *stack);
#endif
