

#include "pila.h"


void createEmptyStack(tStack *stack){

    stack->top = SNULL;

}
bool push(tItem d,tStack *stack){

    if(stack->top == (MAX-1)){

        return false;
    }
    else{

        stack->top++;
        stack->data[stack->top] = d;
        return true;
    }
}
tItem peek(tStack stack){

    return stack.data[stack.top];

}

void pop(tStack *stack){

    stack->top--;

}
bool isEmptyStack(tStack stack){

    return (stack.top == SNULL);
}