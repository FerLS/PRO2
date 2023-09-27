/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: ***************************** LOGIN 1: **********
 * AUTHOR 2: ***************************** LOGIN 2: **********
 * GROUP: *.*
 * DATE: ** / ** / **
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "types.h"

#define MAX_BUFFER 255

#ifdef DYNAMIC_LIST
#include "dynamic_list.h"
#endif
#ifdef STATIC_LIST
#include "static_list.h"
#endif

void S (tList L);
void N ( char *param1, char *param2, char *param3, char *param4,tList *L);
void D (tList *L, char *param1);
void B(tList *L,char *param1,char *param2,char *param3);

void processCommand(char *commandNumber, char command, char *param1, char *param2, char *param3, char *param4,tList *L) {



    printf("\n********************");

    switch (command) {
        case 'N':
            printf("\n%s %c: product %s seller %s category %s price %s", commandNumber, command, param1, param2, param3, param4);

            N(param1,param2,param3, param4,L);
            break;
        case 'S':
            printf("\n%s %c", commandNumber, command);

            S(*L);
            break;
        case 'B':
            printf("\n%s %c: product %s bidder %s price %s", commandNumber, command, param1, param2, param3);

            B(L,param1,param2,param3);
            break;
        case 'D':
            printf("\n%s %c: product %s", commandNumber, command, param1);

            D(L,param1);
            break;
        default:
            printf("Error el comando %c no esta permitdo",command);
            break;
    }
}

void readTasks(char *filename,tList *L) {


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

            processCommand(commandNumber, command[0], param1, param2, param3, param4,L);
        }

        fclose(f);

    } else {
        printf("Cannot open file %s.\n", filename);
    }
}


int main(int nargs, char **args) {

    tList L;
    createEmptyList(&L);

    char *file_name = "new.txt";

    if (nargs > 1) {
        file_name = args[1];
    } else {
        #ifdef INPUT_FILE
        file_name = INPUT_FILE;
        #endif
    }

    readTasks(file_name,&L);

    return 0;
}


void S(tList L) {
    tPosL p;
    tItemL item;

    int books = 0,paintings = 0;        //contador de libros y pinturas
    float aBooks= 0,aPaintings = 0;     //Media de libros y pinturas

    if(!isEmptyList(L)){

        p = first(L);
        while (p != LNULL) {    //recorrre la lista
            item = getItem(p, L);
            printf("\nProduct %s seller %s category %s price %.2f bids %d", item.productId, item.seller,item.productCategory == book ? "book" : "painting",item.productPrice,item.bidCounter);
            p= next(p, L);

            if(item.productCategory == book){   //actualiza medias y contadores
                books = books +1;
                aBooks += item.productPrice;
            }
            else{
                paintings++;
                aPaintings +=item.productPrice;
            }
        }

        //Imprime Tabla
        printf("\n");
        printf("\nCategory  Products    Price  Average");
        printf("\nBook      %8d %8.2f %8.2f",books,aBooks,(isnan(aBooks/ books)? 0: (aBooks/ books)));
        printf("\nPainting  %8d %8.2f %8.2f",paintings,aPaintings,(isnan(aPaintings/ paintings)? 0:(aPaintings/ paintings)));
    }
    else{

        printf("\n+ Error: Stats not possible");
    }
}

void N(char *param1, char *param2, char *param3, char *param4,tList *L){

    tItemL item;

    if(findItem(param1,*L) == LNULL){       //comprueba que no existe un item igual

        strcpy(item.productId, param1);
        item.productCategory = strcmp(param3,"book") == 0? book : painting;
        strcpy(item.seller, param2);
        item.productPrice = atof(param4);
        item.bidCounter = 0;
        if(insertItem(item,LNULL,L)){       //Intenta insertarlo

            printf("\n* New: product %s seller %s category %s price %s",param1,param2,param3,param4);
        }
        else{

            printf("\n+ Error: New not possible");
        }
    }
    else{

        printf("\n+ Error: New not possible");
    }


}
void D(tList *L, char *param1){

    tPosL p = findItem(param1,*L);

    if(p != LNULL){     //comprueba que esa posicion es valida antes de borrar

        tItemL item = getItem(p,*L);
        deleteAtPosition(p,L);
        printf("\n* Delete: product %s seller %s category %s price %.2f bids %d",param1,item.seller,item.productCategory == book ? "book" : "painting",item.productPrice,item.bidCounter);

    }
    else{

        printf("\n+ Error: Delete not possible");
    }

}
void B(tList *L,char *param1,char *param2,char *param3){

    tPosL p = findItem(param1,*L);          //Busca y consigue el item

    if(p!= LNULL) { //Comprueba que es una posicion valida en la lista

        tItemL item = getItem(p,*L);

        if(strcmp(item.seller,param2) != 0 && atof(param3) > item.productPrice){ //Comprueba que cumple los requisitos

            item.bidCounter = item.bidCounter +1;    //Actualiza todos los nuevos valores
            item.productPrice = atof(param3);
            updateItem(item,p,L);        //Actualiza el item en la lista
            printf("\n* Bid: product %s seller %s category %s price %.2f bids %d",param1,item.seller,item.productCategory == book ? "book" : "painting",item.productPrice,item.bidCounter);
        }
        else{

            printf("\n+ Error: Bid not possible");
        }
    }

   else{

       printf("\n+ Error: Bid not possible");
   }



}