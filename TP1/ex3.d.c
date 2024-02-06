#include <stdio.h>
#include <limits.h>

int main() {
  int nbr, i, f = 1.0;
 
  printf("Entrez un nombre pour calculer sa factorielle : \n");
  scanf("%d", &nbr);

  if (nbr < 0) {
        printf("La factorielle n'est définie que pour les nombres entiers positifs.\n");
    } else {
        int i;
        for (i = 2; i <= nbr; i++) {
            // Vérifier si fact dépasse les capacités du type int
            if (f > INT_MAX / i) {
                printf("Erreur : Le calcul de la factorielle dépasse les capacités du type int.\n");
                break;
            }
            f *= i;
        }

        if (i > nbr) {
            printf("La factorielle de %d est %d\n", nbr, f);
        }
    }

  printf("La valeur de INT_MAX est : %d\n", INT_MAX);
 
  return 0;
}