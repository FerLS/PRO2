#include <stdio.h>
#include "arboles.h"

int main() {


    return 0;
}

//Caso base : si vacio => 0,si no tinee hijos =>1
//Hipoteiss induccion :  count node funciona con Rightchild y LeftChild
//Caso general : 1 + countNode(izquierda) + countNode(derecha)

unsigned int countNodes(tBinTree T) {

    if (isEmptyTree(T)) {

        return 0;
    } else if (isEmptyTree(RightChild(T)) && isEmptyTree(LeftChild(T))) {

        return 1;
    } else {

        return 1 + countNodes(RightChild(T)) + countNodes(LeftChild(T));
    }

}

//Caso base: si vacia => nada
//HI: si delete tree funciona si recibe hijo izquierdo o hijo derecho
//Caso general: Deletetre(izqu) y deletetree(der) y deelteTree(root) (free(root))
void DeleteTree(tBinTree *T) {

    if (!isEmptyTree(*T)) {

        DeleteTree(&(*T)->left);
        DeleteTree(&(*T)->right);
        free(T);
        *T = TNULL;

    }


}


int countLeafs(tBinTree T) {

    if (isEmptyTree(T)) {

        return 0;
    } else if (isEmptyTree(RightChild(T)) && isEmptyTree(LeftChild(T))) {

        return 1;
    } else {

        return countLeafs(RightChild(T)) + countLeafs(LeftChild(T));
    }

}

int max(int A, int B) {

    return A > B ? A : B;

}


int height(tBinTree T) {

    if (isEmptyTree(T)) {
        return 0;

    } else {

        return 1+max(height((RightChild(T))), height(LeftChild((T))));
    }


}

