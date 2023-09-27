/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 2
 * AUTHOR 1: Fernando Alvarez Legisima LOGIN 1: fernando.alvarezr@udc.es
 * AUTHOR 2: Diego Varela Barral LOGIN 2: diego.vbarral@udc.es
 * GROUP: 3.3
 * DATE: ** / ** / **
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"
#include "bid_stack.h"
#include "product_list.h"
#include <math.h>

#define MAX_BUFFER 255


void S(tList L);

void N(char *param1, char *param2, char *param3, char *param4, tList *L);

void B(tList *L, char *param1, char *param2, char *param3);

void D(tList *L, char *param1);

void A(tList *L, char *param1);

void W(tList *L, char *param1, char *param2);

void R(tList *L);

void EmptyFullStack(tItemL *item);

void
processCommand(char *commandNumber, char command, char *param1, char *param2, char *param3, char *param4, tList *L) {


    printf("\n********************");


    switch (command) { //Elige la funcion a inciar dependiendo del input, crea tambien su cabezera correspondiente
        case 'N':

            printf("\n%s %c: product %s seller %s category %s price %s", commandNumber, command, param1, param2, param3,
                   param4);

            N(param1, param2, param3, param4, L);

            break;
        case 'S':
            printf("\n%s %c", commandNumber, command);

            S(*L);
            break;
        case 'B':
            printf("\n%s %c: product %s bidder %s price %s", commandNumber, command, param1, param2, param3);

            B(L, param1, param2, param3);
            break;
        case 'D':
            printf("\n%s %c: product %s", commandNumber, command, param1);

            D(L, param1);
            break;
        case 'A':

            printf("\n%s %c: product %s", commandNumber, command, param1);
            A(L, param1);

            break;
        case 'W':
            printf("\n%s %c: product %s bidder %s", commandNumber, command, param1, param2);
            W(L, param1, param2);
            break;
        case 'R':

            printf("\n%s %c", commandNumber, command);
            R(L);

            break;
        default:
            break;
    }
}

void readTasks(char *filename, tList *L) {
    FILE *f = NULL;
    char *commandNumber, *command, *param1, *param2, *param3, *param4;
    const char delimiters[] = " \n\r";
    char buffer[MAX_BUFFER];

    f = fopen(filename, "r");

    if (f != NULL) {

        while (fgets(buffer, MAX_BUFFER, f)) {
            commandNumber = strtok(buffer, delimiters);
            command = strtok(NULL, delimiters);
            param1 = strtok(NULL, delimiters);
            param2 = strtok(NULL, delimiters);
            param3 = strtok(NULL, delimiters);
            param4 = strtok(NULL, delimiters);

            processCommand(commandNumber, command[0], param1, param2, param3, param4, L);
        }

        fclose(f);

    } else {
        printf("Cannot open file %s.\n", filename);
    }
}


int main(int nargs, char **args) {

    tList L;
    createEmptyList(&L); // crea la lista vacia

    char *file_name = "new.txt";

    if (nargs > 1) {
        file_name = args[1];
    } else {
#ifdef INPUT_FILE
        file_name = INPUT_FILE;
#endif
    }

    readTasks(file_name, &L);

    return 0;
}


void N(char *param1, char *param2, char *param3, char *param4, tList *L) {

    //Objetivo: Crear un nuevo item con los parametros espcificados y meterlo en lista
    //Entrada :Codigo de producto, vendedor,categoria,precio
    //Salida: Un nuevo item en lista



    tItemL item;

    if (findItem(param1, *L) == LNULL) {       //comprueba que no existe un item igual

        strcpy(item.productId, param1);     //copia los parametros al item
        item.productCategory = strcmp(param3, "book") == 0 ? book : painting;
        strcpy(item.seller, param2);
        item.productPrice = atof(param4);
        item.bidCounter = 0;
        tStack stack;
        createEmptyStack(&stack);       //crea su pila correspondiente vacia
        item.bidStack = stack;

        if (insertItem(item, L)) {       //Intenta insertarlo en la lista

            printf("\n* New: product %s seller %s category %s price %s", param1, param2, param3, param4);
        } else {

            printf("\n+ Error: New not possible");
        }
    } else {

        printf("\n+ Error: New not possible");
    }


}

void S(tList L) {

    //objetivo: Mostrar todos los elemtos de la lista y otras estadisticas
    //Entrada: una lista
    //salida: los datos imprimidos por consola


    tPosL p;
    tItemL item, bestBidItem;


    bestBidItem.productPrice = 0; //Inciliza a 0 el de referencia


    int books = 0, paintings = 0;        //contador de libros y pinturas
    float aBooks = 0, aPaintings = 0;     //Media de libros y pinturas

    if (!isEmptyList(L)) {  //Comprueba que la lista no este vacia

        p = first(L);
        while (p != LNULL) {    //recorrre la lista si es una posicion valida
            item = getItem(p, L);

            if (item.bidCounter == 0) {     //Imprime segun el numero de bids

                printf("\nProduct %s seller %s category %s price %.2f. No bids", item.productId, item.seller,
                       item.productCategory == book ? "book" : "painting", item.productPrice);
            } else {
                printf("\nProduct %s seller %s category %s price %.2f bids %d top bidder %s", item.productId,
                       item.seller,
                       item.productCategory == book ? "book" : "painting", item.productPrice, item.bidCounter,
                       peek(item.bidStack).bidder);
            }

            p = next(p, L);

            if (item.productCategory == book) {   //actualiza medias y contadores
                books = books + 1;
                aBooks += item.productPrice;
            } else {
                paintings++;
                aPaintings += item.productPrice;
            }


            //Comprueba si el bid es mejor que el del anterior item


            if ((!isEmptyStack(item.bidStack)) && (bestBidItem.productPrice == 0 ||
                                                   ((peek(item.bidStack).productPrice / item.productPrice) >
                                                    (peek(bestBidItem.bidStack).productPrice /
                                                     bestBidItem.productPrice)))) {

                bestBidItem = item;
            }
        }

        //Imprime Tabla
        printf("\n");
        printf("\nCategory  Products    Price  Average");
        printf("\nBook      %8d %8.2f %8.2f", books, aBooks, (isnan(aBooks / books) ? 0 : (aBooks /(float) books)));
        printf("\nPainting  %8d %8.2f %8.2f", paintings, aPaintings,
               (isnan(aPaintings / paintings) ? 0 : (aPaintings /(float) paintings)));


        //Imprime el mayor Postor y precio

        if (bestBidItem.productPrice != 0) {

            printf("\n");
            printf("\nTop bid: Product %s seller %s category %s price %.2f bidder %s top price %.2f increase %.2f%s ",
                   bestBidItem.productId, bestBidItem.seller, bestBidItem.productCategory == book ? "book" : "painting",
                   bestBidItem.productPrice, peek(bestBidItem.bidStack).bidder,
                   peek(bestBidItem.bidStack).productPrice,
                   (peek(bestBidItem.bidStack).productPrice / bestBidItem.productPrice * 100) - 100, "%");

        } else {

            printf("\nTop bid not possible");
        }

    } else {

        printf("\n+ Error: Stats not possible");
    }
}

void B(tList *L, char *param1, char *param2, char *param3) {

    //Objetivo: Hacer una oferta a un deteminado item de la lista y añadirlo a la pila de ofertas del item
    //Entrada : Producto a ofertar, quien pone la oferta y el precio que propone
    //Salida: la lista con los item con sus pilas actualizadas

    tPosL p = findItem(param1, *L);          //Busca y consigue el item

    if (p != LNULL) { //Comprueba que es una posicion valida en la lista

        tItemL item = getItem(p, *L);

        //crea el nuevo item bidder
        tItemS bidItem;
        bidItem.productPrice = atof(param3);
        strcpy(bidItem.bidder, param2);

        /*comprueba que se pueda insertar y inserta el item en su pila.
                ↓
                ↳ ➜   ➜   ➜   ➜   ➜   ➜   ➜   ➜   ➜   ➜   ➜   ➜   ➜   ➜   ➜   ➜   ➜   ➜   ➜   ➜   ➜   ➜   ➜   ➜   ➜   ➜   ➜  ➜ ↴
                                                                                                                               ↓
                                                                                                                               ↓*/
        if (strcmp(item.seller, param2) != 0 &&                                                                              //↓
            (isEmptyStack(item.bidStack) ? (atof(param3) > item.productPrice) : (atof(param3) >            // ↓
                                                                                 peek(item.bidStack).productPrice)) && push(bidItem, &item.bidStack)) { //Comprueba que cumple los requisitos



            item.bidCounter = item.bidCounter + 1;  //Actualiza el contador de pujas
            updateItem(item, p, L);        //Actualiza el item en la lista


            printf("\n* Bid: product %s bidder %s category %s price %.2f bids %d", param1, bidItem.bidder,
                   item.productCategory == book ? "book" : "painting", bidItem.productPrice, item.bidCounter);
        } else {

            printf("\n+ Error: Bid not possible");
        }
    } else {

        printf("\n+ Error: Bid not possible");
    }


}

void D(tList *L, char *param1) {

    //Objetivo: Borrar un elemto de la lista y su pila de ofertas
    //Entrada: La lista, el producto a borrar
    //Salida: La lista sin el product borrado


    tPosL p = findItem(param1, *L); // busca el item

    if (p != LNULL) {     //comprueba que esa posicion es valida antes de borrar

        tItemL item;
        item = getItem(p, *L);

        EmptyFullStack(&item);  //vacia la pila correspondiente del item;
        updateItem(item,p,L);

        deleteAtPosition(p, L);     //borra el item de la lista
        printf("\n* Delete: product %s seller %s category %s price %.2f bids %d", param1, item.seller,
               item.productCategory == book ? "book" : "painting", item.productPrice, item.bidCounter);

    } else {

        printf("\n+ Error: Delete not possible");
    }

}

void A(tList *L, char *param1) {

    //Objetivo: Se declara un ganador de la puja de un producto y a continuacion se borra el producto
    //Entrada: La lista , el producto
    //Salida: La lista sin el producto y la impresion del ganador por pantalla

    tPosL p = findItem(param1, *L);

    if (p != LNULL) {     //comprueba que esa posicion es valida

        tItemL item;
        item = getItem(p, *L);

        if (!isEmptyStack(item.bidStack)) {     // si la pila no esta vacia procede a declarar un ganador

            printf("\n* Award: product %s bidder %s category %s price %.2f", param1, peek(item.bidStack).bidder,
                   item.productCategory == book ? "book" : "painting", peek(item.bidStack).productPrice);

            EmptyFullStack(&item);  //Vacia el stack del item;
            updateItem(item,p,L);

            deleteAtPosition(p, L); //elimina el item

        } else {

            printf("\n+ Error: Award not possible ");
        }
    } else {

        printf("\n+ Error: Award not possible ");
    }
}

void W(tList *L, char *param1, char *param2) {


    //Objetivo: Borrar la mejor puja de un elemento
    //Entrada: El bidder correspondiente a la puja,  la lista, el producto
    //Salida: La lista con el item sin su mejor postor

    tPosL p = findItem(param1, *L);

    if (p != LNULL) {     //comprueba que esa posicion es valida

        tItemL item;
        item = getItem(p, *L);

        if (!isEmptyStack(item.bidStack) && (strcmp(peek(item.bidStack).bidder, param2) == 0)) {            //comprueba que no este vacia y que el userId se corresponda con el autor de lapuja

            printf("\n* Withdraw: product %s bidder %s category %s price %.2f bids  %d", param1,
                   peek(item.bidStack).bidder,
                   item.productCategory == book ? "book" : "painting", peek(item.bidStack).productPrice,
                   item.bidCounter);

            item.bidCounter = item.bidCounter - 1;  //Descuenta el numero de bids y elimina el ultimo bid de la pila
            pop(&item.bidStack);

            updateItem(item, p, L);     //actualiza el item en la lista


        } else {

            printf("\n+ Error: Withdraw not possible");
        }
    } else {

        printf("\n+ Error: Withdraw not possible");
    }
}

void R(tList *L) {


    //Objetivo: Borrar todas aquellos items con su pila de  pujas vacia
    //Entrada : la lista
    //Salida: La lista con todos sus items con pujas
    tPosL p;
    p = first(*L);
    bool all = true;

    while (p != LNULL) {    //recorrre la lista

        tItemL item;
        item = getItem(p, *L);
        if (isEmptyStack(item.bidStack)) { // comprueba que la pila de pujas este vacia

            all = false; // no todos los items tienen la pila vacia
            printf("\nRemoving product %s seller %s category %s price %.2f bids %d", item.productId, item.seller,
                   item.productCategory == book ? "book" : "painting", item.productPrice, item.bidCounter);
            deleteAtPosition(p, L); // borrra el item de la pila
        }

        p = next(p, *L);

    }
    if (all) { //Comprobar si no hay ninguno vacio

        printf("+ Error: Remove not possible");
    }

}

void EmptyFullStack(tItemL *item){

    while (!isEmptyStack((item->bidStack))){
        pop(&(item->bidStack));                 //quita elemento a elemento hasta que ka pila este vacia
    }

}