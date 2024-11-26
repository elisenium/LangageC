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
        printf("%d n'est pas un nombre premier.\n", n);
        return false;
    }
    
    for (int i = 2; i <= sqrt(n); i++) {
        if (i != n && n %i == 0) {
            printf("%d n'est pas un nombre premier.\n", n);
            return false;
        }
    }
    printf("%d est un nombre premier.\n", n);
    return true;
}


int main() {
    int number;

    printf("Entrez un nombre pour vérifier si c'est un nombre premier : ");
    scanf("%d", &number);

    bool primeTest = isPrime(number);

    exit(0);
}
