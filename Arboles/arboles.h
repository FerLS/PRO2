
#ifndef ARBOLES_ARBOLES_H
#define ARBOLES_ARBOLES_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define TNULL NULL


typedef  int tItemT;

typedef struct tNodeT *tPosT;

struct tNodeT {

    tItemT data;
    tPosT right;
    tPosT left;


};
typedef tPosT tBinTree;

void createEmptyTree(tBinTree *T);
bool isEmptyTree(tBinTree T);
tItemT Root(tBinTree T);
tBinTree RightChild(tBinTree T);
tBinTree LeftChild(tBinTree T);
bool BuildTree(tBinTree LT,tItemT itemT,tBinTree RT,tBinTree *T);



#endif //LISTAS_LISTA_H
