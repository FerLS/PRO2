//Fernando Alvarez Legisima y Diego Varela Barral


#include <stdio.h>

//Usa solo uno de los dos!!
#include "rational_struct.h"
//#include "racional_pointer.h"

int main() {
    Rational r1,r2,r3,r4,s;
    r1 = createRational(2,4);
    r2 = createRational(5,9);
    r3 = createRational(2,1);
    r4 = createRational(5,2);
    s = suma(r1,r2);
    printf("\nLa suma es %d/%d", numerator(s), denominator(s));
    s = suma(r3,r4);
    printf("\nLa suma es %d/%d", numerator(s), denominator(s));
    return 0;


}
