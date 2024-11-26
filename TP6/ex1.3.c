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

    for (int i = 2; i < n; ++i) {
        if (isPrime(i) == true) {
            prime_numbers[*sz] = i;
            (*sz)++;
        }
    }

    prime_numbers = realloc(prime_numbers, (*sz) * sizeof(int));

    return prime_numbers;
}


/*
 * PRE : t : tableau de longueur sz
 * POST : t représente un tableau trié contenant les sz premiers nombres premiers.
 * RES : vrai en cas de succès ; faux sinon
 */

bool first_prime_numbers(int* t, int sz) {
    int n = 2;
    int szr;
    int* pn = prime_numbers(n, &szr);

    while (szr < sz) {
        n = n * 2;
        pn = prime_numbers(n, &szr);
        if (pn == NULL) {
            free(pn);

            return false;
        }
    }
    // copier les sz premiers entiers de pn dans t
    for (int i = 0; i < sz; ++i) {
        if (t[i] != pn[i]) {
            free(pn);

            return false;
        }
        t[i] = pn[i];
    }

    free(pn);
    return true;
}

int main() {
    int t1[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 30}; // Test KO
    int t2[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29}; // Test OK
    int t3[4] = {2, 3, 5, 7}; // Test OK
    int t4[4] = {2, 3, 5, 6}; // Test KO

    bool test1 = first_prime_numbers(t1, 10);
    bool test2 = first_prime_numbers(t2, 10);
    bool test3 = first_prime_numbers(t3, 4);
    bool test4 = first_prime_numbers(t4, 4);

    printf("Test 1 : %s\n", test1 ? "OK" : "KO");
    printf("Test 2 : %s\n", test2 ? "OK" : "KO");
    printf("Test 3 : %s\n", test3 ? "OK" : "KO");
    printf("Test 4 : %s\n", test4 ? "OK" : "KO");
    
    return 0;
}
