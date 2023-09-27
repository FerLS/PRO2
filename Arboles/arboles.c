

#include "arboles.h"

bool createNode(tBinTree *T){
    *T = malloc(sizeof (struct tNodeT));
    return  *T!= TNULL;
}
void createEmptyTree(tBinTree *T){

    *T = TNULL;

}
bool isEmptyTree(tBinTree T){

    return (T==TNULL);

}
tItemT Root(tBinTree T){

    return  T->data;

}

tBinTree LeftChild(tBinTree T){

    return T->left;

}
tBinTree RightChild(tBinTree T){

    return T->right;
}
bool BuildTree(tBinTree LT,tItemT itemT,tBinTree RT,tBinTree *T){

    if(createNode(T)){

        (*T)->data=itemT;
        (*T)->left=LT;
        (*T)->right=RT;
        return true;
    }
    else return false;


}

