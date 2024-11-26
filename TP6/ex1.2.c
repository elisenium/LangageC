#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

/*
* PRE : n : nombre entier positif
* RES : vrai si n est un premier ; faux sinon
*/

bool isPrime(int n) {
    if (n < 2) {
        //printf("%d n'est pas un nombre premier.\n", n);
        return false;
    }
    
    for (int i = 2; i <= sqrt(n); i++) {
        if (i != n && n %i == 0) {
            //printf("%d n'est pas un nombre premier.\n", n);
            return false;
        }
    }
    //printf("%d est un nombre premier.\n", n);
    return true;
}

/**
 * PRE : n >= 2
 * POST : sz est égal à la taille (physique ou logique) du tableau renvoyé
 * RES : un tableau trié contenant tous les nombres premiers plus petits que n si aucune erreur n'est survenue ;
 *       NULL si une erreur est survenue (sz est mis à 0)
 */


int* prime_numbers (int n, int* sz) {
    *sz = 0;
    int *prime_numbers = (int*)malloc(n*sizeof(int));
    if (prime_numbers == NULL) {
        return NULL;
    }

    for (int i = 2; i <= n; ++i) {
        if (isPrime(i) == true) {
            prime_numbers[*sz] = i;
            (*sz)++;
        }
    }

    prime_numbers = realloc(prime_numbers, (*sz) * sizeof(int));
    /*
    printf("Nombres premiers plus petits que %d :\n", n);
    for (int i = 0; i < *sz; ++i) {
        printf("%d\n", prime_numbers[i]);
    }
    printf("TAILLE : %d\n", *sz);
    */

    return prime_numbers;
}

int main () {
    int max = 100;
    int taille;
    int* t = prime_numbers(max, &taille);
    
    free(t);

    exit(0);
}
