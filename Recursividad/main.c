#include <stdio.h>

int main() {
    printf("Hello, World!\n");
    return 0;
}
/*
sum(v vector,ini int,fin int) => int

 //caso base

    si ini = fin => v[ini]

  //Hipotesis de induccion

    si funciona si sum(v,ini,fin-1)

  //caso general

    sum(v,ini,fin) = sum(v,ini,fin-1) + v[ini]

********************************************************

 power(real x, int n) -> real

 //caso base

 si n= 0 return 1
 o
 si n = 1 return x

 //hipotesis de induccion

 power funciona si power(x,n-1)

 //caso general

 Power(x,n) = x * power(x,n-1)

 //codigo

 Power(int x,float n){

 if(n==0) return 1;
 else{

 return x * power(x,n-1);
 }

 }


***********************************************************

 Contar elementos de una lista con implementacion dinamica

 count(L) -> int

 //Caso base

 si lista vacia => 0

 //Hipotesis induccion

 Count funciona si count(L->next)

 //Caso General

 count(L) = count(L-> next) +1

 ********************************************************

 ShowList(L) => nada

 //caso base

 si lista vacia => no imprime nada

 //Hipoteisis induccion

 ShowList funciona si Showlist(L->next)

 //Caso general


 Sholist(L) =  (primero imprime el primero ) (despues ->  sholist(L->next))

//Codigo

 void ShowList(tlist L){

    if(L!=NULL){
    printf("%i",L-> data)
    Showlist(L-> next)

    }

 }

