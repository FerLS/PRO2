/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 2
 * AUTHOR 1: Fernando Alvarez Legisima LOGIN 1: fernando.alvarezr@udc.es
 * AUTHOR 2: Diego Varela Barral LOGIN 2: diego.vbarral@udc.es
 * GROUP: 3.3
 * DATE: ** / ** / **
 */

#include "bid_stack.h"

void createEmptyStack(tStack *stack){

   // Objetivo: Crear una Pila vacia
    //Entrada: el stack incializado
    //Salida: el stack vacio
    // PostCondicion: La pila debe estar vacia

    stack->top = SNULL;

}
bool push(tItemS d,tStack *stack){

    //Insertar un elemento en la cima de la pila, devolvera true si lo consiguio.
    //Entrada: el item y el stack
    //Salida: el stack con el nuevo item
    if(stack->top == (SMAX-1)){ // Si la pila esta llena devuelve false.

        return false;
    }
    else{

        stack->top++;
        stack->data[stack->top] = d;
        return true;
    }
}
tItemS peek(tStack stack){

    //Agarra el elemento de la cima de la pila
    //Entrada: el stack
    //salida: el item de la cima del stack
    //Precondicion: La pila no debe estar vacia
    return (stack.data[stack.top]);

}

void pop(tStack *stack){

    //Elimina el ultimo elemento de la pila.(que entro)
    //Entrada: el stack
    //SAlida: el stack sin el ultimo elemtno de la pila(que entro)
    //Precondicion: la pila no debe estar vacia.
    stack->top--;

}
bool isEmptyStack(tStack stack){

    //Comprueba si la pila esta vacia.
    //Entrada: El stack
    //salida: un booleano

    return (stack.top == SNULL);
}
