/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: ***************************** LOGIN 1: **********
 * AUTHOR 2: ***************************** LOGIN 2: **********
 * GROUP: *.*
 * DATE: ** / ** / **
 */

#include "static_list.h"

//Nuestro Codigo//
void createEmptyList(tList *L) {

    L->lastPos = LNULL;

}

bool isEmptyList(tList L) {

    return L.lastPos == LNULL;

}

tItemL getItem(tPosL p, tList L) {

    return (L.data[p]);
}

void updateItem(tItemL d, tPosL p, tList *L) {

    L->data[p] = d;
}

tPosL first(tList L) {

    return 0;
}

tPosL previous(tPosL p, tList L) {

    return --p;
}

tPosL next(tPosL p, tList L) {

    if (p == L.lastPos) {

        return LNULL;
    } else {

        return ++p;
    }


}

tPosL last(tList L) {

    return L.lastPos;

}

tPosL findItem(tProductId pID, tList L) {

    tPosL p = LNULL;

    if (!isEmptyList(L)) {

        for (p = 0; (p <= L.lastPos) && ( 0!= strcmp(pID,L.data[p].productId) ); p++);

        if(p==L.lastPos+1){

            p = LNULL;
        }

    }
    return p;

}

/*bool copyList(tList L, tList *M) {

   for (tPosL p = 0; p <= L.lastPos; p++) {

       M->data[p] = L.data[p];
   }
   M->lastPos = L.lastPos;
   return true;

}*/


bool insertItem(tItemL d, tPosL p, tList *L) {


    tPosL i;
    if (L->lastPos == MAX - 1) {
        return false;
    } else {
        L->lastPos++;
        if (p == LNULL) {
            L->data[L->lastPos] = d;
        } else {
            for (i = L->lastPos; i >= (p + 1); i--) {
                L->data[i] = L->data[i - 1];
            }
            L->data[p] = d;
        }
        return true;
    }

}


void deleteAtPosition(tPosL p, tList *L) {

    tPosL i;
    L->lastPos--;
    for (i = p; i <= L->lastPos; ++i) {

        L->data[i] = L->data[i + 1];
    }
}
//Nuestro Codigo//