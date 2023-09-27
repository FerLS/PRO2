

#include "lista.h"

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

    return p->previous;
}
tPosL next(tPosL p, tList L) {

    return p->next;
}

tPosL last(tList L) {

    tPosL p;
    for (p = L; p->next != LNULL; p = p->next);
    return p;

}

tPosL findItem(tItemL d, tList L) {

    tPosL p;
    if (isEmptyList(L)) {

        p = LNULL;
    } else {

        for (p = L; p != LNULL && p->data != d; p = p->next); // Ojito el orden de el && importa
    }
    return p;

}

bool insertItem(tItemL d, tPosL p, tList *L) {

    tPosL q,r;
    if (!createNode(&q)) {

        return false;

    } else {

        q->data = d;
        q->next = LNULL; //por si acaso
        q->previous = LNULL;
    }
    if (isEmptyList(*L)) {

        *L = q;
    } else if (p == LNULL) {

        for(r = *L;r->next != LNULL;r = r->next);
        r->next = q;
        q->previous = r;

    } else if (p == *L) {

        q->next = p;
        p->previous = q;
        *L = q;

    } else {

        q->previous = p->previous;
        q->next = p;
        p->previous->next = q;
        p->previous= p;

    }
    return true;
}

bool createNode(tPosL *p) {

    *p = malloc(sizeof(struct Node));

    return *p != LNULL;
}


void deleteAtPosition(tPosL p, tList *L) {

    tPosL q;
    if(p ==*L){

        *L = p->next;
        if(*L != LNULL){
        p->next->previous = LNULL;
        }
    } else if ( p->next != LNULL){

        p->previous->next = p->next;
        p->next->previous = p->previous;
    }
    else{

        p->previous->next = LNULL;
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

