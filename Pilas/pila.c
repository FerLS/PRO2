

#include "pila.h"


bool createNode(tPosS *p) {

    *p = malloc(sizeof(struct Node));

    return *p != SNULL;
}
void createEmptyStack(tStack *stack){

    *stack = SNULL;

}
bool push(tItem d,tStack *stack){

    tPosS aux;

    if(!createNode(&aux)){

        return false;
    }
    else{

        aux->data=d;
        aux->next=*stack;
        *stack = aux;
        return true;
    }

}
tItem peek(tStack stack){

    return stack->data;

}

void pop(tStack *stack){

    tPosS aux;
    aux = *stack;
    *stack = (*stack)->next;
    free(aux);

}
bool isEmptyStack(tStack stack){

    return stack == SNULL;


}