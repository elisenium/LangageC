#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <float.h>

int main() {
    int number = 0, pow = 0;
    double result = 1.0;
    int sign = 1;
    char c;
    int digit_count = 0;

    printf("Entrez la base (1 ou 2 chiffres, peut être négatif) : ");
    
    // Lire la base
    while ((c = getchar()) != '\n' && c != EOF) {
        if (c == '-') {
            sign = -1;
        } else if (c >= '0' && c <= '9') {
            number = number * 10 + (c - '0');
            digit_count++;
            if (digit_count > 2) {
                printf("Erreur : La base ne doit pas dépasser 2 chiffres.\n");
                return 1;
            }
        }
    }
    number *= sign;

    printf("Entrez l'exposant (1 ou 2 chiffres, peut être négatif) : ");
    sign = 1; // Réinitialiser le signe pour l'exposant
    digit_count = 0; // Réinitialiser le compteur de chiffres

    // Lire l'exposant
    while ((c = getchar()) != '\n' && c != EOF) {
        if (c == '-') {
            sign = -1;
        } else if (c >= '0' && c <= '9') {
            pow = pow * 10 + (c - '0');
            digit_count++;
            if (digit_count > 2) {
                printf("Erreur : L'exposant ne doit pas dépasser 2 chiffres.\n");
                return 1;
            }
        }
    }
    pow *= sign;

    // Cas limite : 0^0 = 1
    if (number == 0 && pow == 0) {
        result = 1.0;
    }
    // Cas limite : a^0 = 1
    else if (pow == 0) {
        result = 1.0;
    }
    // Cas limite : 0^(-b) = ∞ si b > 0
    else if (number == 0 && pow < 0) {
        result = INFINITY;
    }
    else {
        // Si l'exposant est négatif, on change l'état positive_pow à false
        // On change met le pow à positif pour qu'il puisse faire la boucle for
        int positive_pow = (pow >= 0);
        if (!positive_pow) {
            pow = -pow;
        }

        // Calcul de la puissance
        for (int i = 0; i < pow; i++) {
            result *= number;
        }

        // Si l'exposant est négatif, on calcule l'inverse du résultat
        if (!positive_pow) {
            result = 1.0 / result;
        }
    }

    printf("%d^(%d) = %.30f\n", number, pow * (sign), result);
    
    return 0;
}