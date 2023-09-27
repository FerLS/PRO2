//Fernando Alvarez Legisima y Diego Varela Barral

#ifndef PRACTICA_0_RACIONAL_POINTER_H
#define PRACTICA_0_RACIONAL_POINTER_H

typedef struct Data* Rational;

struct Data{

    int num;
    int den;
};

Rational createRational(int n,int d);
int numerator(Rational r);
int denominator(Rational r);
Rational suma(Rational r1,Rational r2);

#endif //PRACTICA_0_RACIONAL_POINTER_H
