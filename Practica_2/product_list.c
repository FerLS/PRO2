/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 2
 * AUTHOR 1: Fernando Alvarez Legisima LOGIN 1: fernando.alvarezr@udc.es
 * AUTHOR 2: Diego Varela Barral LOGIN 2: diego.vbarral@udc.es
 * GROUP: 3.3
 * DATE: ** / ** / **
 */

#include "product_list.h"

void createEmptyList(tList *L){
     //Crea una lista vacia y la inicializa.
     //Salida: lista vacia.
     //PostCD: la lista no debe tener datos.


    *L = LNULL;
}

bool isEmptyList(tList L) {
    //Objetivo: Comprobar si la lista esta vacia.
    //Entrada: la lista
    //Salida: Verdadero si la lista esta vacia, falso si no lo esta.
    //PreCD: lista inicializada.

    return L == LNULL;

}

tItemL getItem(tPosL p, tList L){
    //Recupera el contenido de un item determinado.
    //Entrada: la posicion del elemento deseado y la lista.
    //Salida: Contenido del item deseado.
    //PreCD: la poscicion indicada debe ser valida.

    return (p->data);

}

void updateItem(tItemL d, tPosL p, tList *L) {
    //Modifica el contenido de un item.
    //Entrada:un nuevo item que sustituya al anterior, la posicion del item que se quiera modificar y la lista
    //Salida: Lista con el item modificado.
    //PreCD:la posicion indicada debe ser valida.

    p->data = d;

}

tPosL first(tList L) {
    //Devuelve la posicion del primer elemento de la lista.
    //Entrada: la lista
    //Salida: la posicion del primer elemento.
    //PreCD: la lista no debe estar vacia.

    return L;
}

tPosL previous(tPosL p, tList L) {
    //Devuelve la posicion del elemento anterior al actual.
    //Entrada: posicion del elemento actual y la lista.
    //Salida: Posicion del elemento anterior al actual.
    //PreCD: la posicion indicada es valida en la lista.

    if (p == L) return LNULL;
    else {

        tPosL q;
        for (q = L; p != q->next; q = q->next);
        return q;

    }
}
tPosL next(tPosL p, tList L) {
    //Devuelve la posicion del elemento posterior al actual.
    //Entrada: posicion del elemento actual y la lista.
    //Salida: Posicion del elemento anteior posterioral.
    //PreCD: la posicion indicada es valida en la lista.

    return p->next;
}

tPosL last(tList L) {
    //Devuelve la posicion del ultimo elemento de la lista.
    //Entrada: la lista
    //Salida: posicion del ultimo elemento de la lista.
    //PreCD: la lista no esta vacia.

    tPosL p;
    for (p = L; p->next != LNULL; p = p->next);
    return p;

}

tPosL findItem(tProductId pId, tList L) {
    //Busca el contenido de un elemento especifico.
    //Entrada: elemento que se quiere buscar y la lista donde buscarlo.
    //Salida: posicion del elemento encontrado o nulo si el elemento no se encuentra en la lista.


    tPosL p;
    if (isEmptyList(L)) {

        return  LNULL;

    } else {

        for (p = L; p != LNULL && (strcmp(p->data.productId, pId) < 0); p = p->next);

        if(p!= LNULL && (strcmp(p->data.productId, pId) == 0)){


            return  p;

        }
        else{
            return  LNULL;
        }
    }



}
tPosL findPosition(tList L,tItemL d){



    tPosL p;
    p=L; //asigna p a L
    while((p->next != LNULL) && (strcmp(p->next->data.productId , d.productId) < 0 )){ // en este caso que va de menor a mayor : 1,2,4,5,20

        p = p->next;

    }
    return  p;


}
bool createNodeL(tPosL *p) {

    *p = malloc(sizeof(struct LNode));

    return *p != LNULL;
}


bool insertItem(tItemL d, tList *L) {
    //Añade un elemento al final de la lista si la posicion indicada es nula. En caso contrario, añadira el elemento justo en la posicion anterior a la indicada
    //Entrada: elemento a insertar, posicion donde se quiera insertar y lista donde instertarlo.
    //Salida: lista con el elemento insertado, verdadero si se pudo insertar y falso en caso contrario.
    //PreCD: la posicion indicada es valida.
    //PostCD: las posiciones posteriores al nuevo elemento insertado han cambiado.
    tPosL q,p;
    if (!createNodeL(&q)) {

        return false;

    } else {

        q->data = d;
        q->next = LNULL; //por si acaso
    }
    if (isEmptyList(*L)) {

        *L = q;
    }
    else if(strcmp(d.productId,(*L)->data.productId) < 0 ){

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



void deleteAtPosition(tPosL p, tList *L) {
    //Elimina un elemento de la lista en base a la posicion indicada.
    //Entrada: posicion del elemento que se quiere eliminar y la lista que contiene al elemento.
    //Salida: lista con dicho elemento eliminado.
    //PreCD: la posicion indicada debe ser valida.
    //PostCD: las posiciones de los elementos posteriores al elemento eliminado han variado.

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
    //Elimina todos los elementos de la lista.
    //Entrada: lista a vaciar.
    //Salida; lista vacia.

    tPosL p;
    while (*L != LNULL) {
        p = *L;
        *L = (*L)->next;
        free(p);

    }
}