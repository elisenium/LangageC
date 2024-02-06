#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * PRE : n: nombre entier positif
 * RES : vrai si n est premier, faux sinon
 */

bool isPrime (int n) {

    bool isPrimeNumber = true;
    bool isNotPrimeNumber = false;

    if (n%n == 0 && n%1 == n)
    {
        printf("%d est un nombre premier.\n", n);
        return isPrimeNumber;
    }
    else {
      printf("%d n'est pas un nombre premier.\n", n);
      return isNotPrimeNumber; 
    }
}



int main()
{
    int number = 10;
    bool primeTest = isPrime(number);

    exit(0);
}
