

#include "Cola.h"


bool createNode(tPosQ *p) {

    *p = malloc(sizeof(struct Node));

    return *p != QNULL;
}
void createEmptyQueue(tQueue *Q){

    Q->front = QNULL;
    Q->rear = QNULL;

}
bool isEmptyQueue(tQueue Q){

    return(Q.front == QNULL);

}
tItemQ front(tQueue Q){

    return Q.front->data;
}

bool enqueue(tItemQ d,tQueue *Q){

    tPosQ aux;

    if(!createNode(&aux)){

        return false;
    }
    else{

        aux->data=d;
        aux->next=QNULL;

        if(Q->front == QNULL){
            Q->front = aux;

        }
        else{
            Q->rear->next = aux;
        }
        Q->rear = aux;

        return true;
    }

}

void dequeue(tQueue *Q){

    tPosQ aux;
    aux = Q->front;
    Q->front = aux->next;
    if(Q->front == QNULL){

        Q->rear = QNULL;
    }
    free(aux);

}
