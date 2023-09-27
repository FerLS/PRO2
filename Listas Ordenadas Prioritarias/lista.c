

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

tPosL findItem(tItemL d, tList L) {

    tPosL p;
    if (isEmptyList(L)) {

        p = LNULL;
    } else {
                                        //aqui cambio el !=
        for (p = L; p != LNULL && p->data < d; p = p->next); // Ojito el orden de el && importaç

        if(p!= LNULL && p->data == d){
            return  p;

        }
        else{
            return  LNULL;
        }
    }



}
tPosL findPosition(tList L,tItemL d){

    tPosL p;
    p=L;
    while((p->next->data < d )&& (p->next != LNULL)){ // en este caso que va de menor a mayor : 1,2,4,5,20

        p = p->next;

    }
    return  p;


}

bool insertItem(tItemL d, tList *L) {

    tPosL q,p;
    if (!createNode(&q)) {

        return false;

    } else {

        q->data = d;
        q->next = LNULL; //por si acaso
    }
    if (isEmptyList(*L)) {

        *L = q;
    }
    else if(d < (*L)->data){

        q->next = *L;
        *L = q;

    }
    else{

        p = findPosition(*L,d);
        q->next = p->next;
        p->next = q;


    }
    return true;
}

bool createNode(tPosL *p) {

    *p = malloc(sizeof(struct Node));

    return *p != LNULL;
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