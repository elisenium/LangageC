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

/**
 * PRE : n >= 2
 * POST : sz est égal à la taille (physique ou logique) du tableau renvoyé
 * RES : un tableau trié contenant tous les nombres premiers plus petits que n si aucune erreur n'est survenue ;
 *       NULL si une erreur est survenue (sz est mis à 0)
 */

//Vérifier avec les solutions
int* prime_numbers (int n, int sz*) {
    *sz = 0;
    int *primes = malloc(n*sizeof(int));
    if (primes == NULL) {
        return NULL;
    }

    for (int i = 2; i < n; ++i)
    {
        if (isPrime(i) == true)
        {
            primes[*sz] = i;
            (*sz)++;
        }
    }
    primes = realloc(primes, *sz * sizeof(int))
    return primes
}

int main ()
{
    int max = 100;
    int taille;
    int* t = prime_numbers(100, &taille);
    exit(0);
}
