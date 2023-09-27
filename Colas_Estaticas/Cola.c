

#include "Cola.h"

int addOne(int i){
    if(i == Q_MAX-1){

        return 0;
    }
    else{

        return ++i;
    }

}
bool isFullQueue(tQueue Q){

    return (Q.front == addOne(addOne(Q.rear)));
}



void createEmptyQueue(tQueue *Q){

    Q->front = 0;
    Q->rear = Q_MAX-1;

}
bool isEmptyQueue(tQueue Q){

    return(Q.front == addOne(Q.rear));

}
tItemQ front(tQueue Q){

    return Q.data[Q.front];
}

bool enqueue(tItemQ d,tQueue *Q){

    if(isFullQueue(*Q)){

        return false;
    }
    else{

        Q->rear = addOne(Q->rear);
        Q->data[Q->rear] = d;
        return true;
    }
}

void dequeue(tQueue *Q){

    Q->front = addOne(Q->front);
}
