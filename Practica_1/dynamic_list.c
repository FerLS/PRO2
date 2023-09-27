/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: ***************************** LOGIN 1: **********
 * AUTHOR 2: ***************************** LOGIN 2: **********
 * GROUP: *.*
 * DATE: ** / ** / **
 */

#include "dynamic_list.h"

#define LNULL NULL
//Aqui nuestro codigo//

void createEmptyList(tList *L) {

    *L = LNULL;
}

bool isEmptyList(tList L) {

    return L == LNULL;

}

tItemL getItem(tPosL p, tList L /* No es necesaria si se usan punteros*/) {

    return (p->data);

}

void updateItem(tItemL d, tPosL p, tList *L /* No es necesaria si se usan punteros*/) {

    p->data = d;

}

tPosL first(tList L) {

    return L;
}

tPosL previous(tPosL p, tList L) {

    if (p == L) return LNULL;
    else {

        tPosL q;
        for (q = L; p != q->next; q = q->next);
        return q;

    }
}

tPosL next(tPosL p, tList L) {

    return p->next;
}

tPosL last(tList L) {

    tPosL p;
    for (p = L; p->next != LNULL; p = p->next);
    return p;

}

tPosL findItem(tProductId pId, tList L) {

    tPosL p;
    if (isEmptyList(L)) {

        p = LNULL;
    } else {

        for (p = L; p != LNULL && strcmp(p->data.productId, pId) != 0; p = p->next); // Ojito el orden de el && importa
    }
    return p;

}
bool createNode(tPosL *p) {

    *p = malloc(sizeof(struct Node));

    return *p != LNULL;
}
bool insertItem(tItemL d, tPosL p, tList *L) {

    tPosL q;
    if (!createNode(&q)) {

        return false;

    } else {

        q->data = d;
        q->next = LNULL; //por si acaso
    }
    if (isEmptyList(*L)) {

        *L = q;
    } else if (p == LNULL) {

        last(*L)->next = q;

    } else if (p == *L) {

        q->next = p;
        *L = q;

    } else {

        q->next = p->next;
        p->next = q;
        q->data = p->data;
        p->data = d;
    }
    return true;
}



void deleteAtPosition(tPosL p, tList *L) {





    if (p == *L) {

        *L = p->next;
    } else if (p->next == LNULL) {

        previous(p, *L)->next = LNULL;
    } else {
        tPosL q;
        q = p->next;
        p->data = q->data;
        p->next = q->next;
        p = q;
    }

    free(p);

}

void deleteList(tList *L) {

    tPosL p;
    while (*L != LNULL) {
        p = *L;
        *L = (*L)->next;
        free(p);

    }
}






//Aqui nuestro codigo//
