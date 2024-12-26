#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define MAX_N 100

void cribleEratosthene(int n) {
    bool estPremier[MAX_N + 1];

    // Initialisation de tous les éléments à true au début
    for (int i = 2; i <= n; i++) {
        estPremier[i] = true;
    }

    // Crible d'Ératosthène
    for (int k = 2; k <= n/2; k++) {
        if (estPremier[k]) {
            for (int j = k * k; j <= n; j += k) {
                estPremier[j] = false;
            }
        }
    }

    // Affichage des nombres premiers
    printf("Les nombres premiers entre 2 et %d sont :\n", n);
    for (int i = 2; i <= n; i++) {
        if (estPremier[i]) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main() {
    int n;

    // Lire la valeur de N
    do {
        printf("Entrez un nombre entre 2 et 100 : ");
        scanf("%d", &n);
        if (n < 2 || n > 100) {
            printf("Erreur : le nombre doit être compris entre 2 et 100.\n");
        }
    } while (n < 2 || n > 100);

    // Crible d'Ératosthène
    cribleEratosthene(n);

    return 0;
}