#include <stdio.h>
#include <limits.h>

int main() {
  int nbr, i, f = 1.0;
 
  printf("Entrez un nombre pour calculer sa factorielle : ");
  scanf("%d", &nbr);

  if (nbr < 0) {
        printf("La factorielle n'est définie que pour les nombres entiers positifs.\n");
    } else {
        //Vérification dépassement capacités int
        for (i = 2; i <= nbr; i++) { // la boucle commence par 2 car on a pas besoin de faire x 1. Ex : 3! = 3 x 2 x 1 -> avec ou sans le 1 ça change rien
            if (f > INT_MAX / i) {
                printf("Erreur : Le calcul de la factorielle dépasse les capacités du type int.\n");
                break;
            }
            f *= i;
        }

        if (i > nbr) {
            printf("%d! = %d\n", nbr, f);
        }
    }

  printf("\nLa valeur de INT_MAX est : %d\n", INT_MAX);
  return 0;
}