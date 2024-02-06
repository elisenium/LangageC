#include <stdio.h>
#include <limits.h>

int main() {
  int nbr, i, f = 1.0;
 
  printf("Entrez un nombre pour calculer sa factorielle : \n");
  scanf("%d", &nbr);

  if (nbr < 0) {
        printf("La factorielle n'est définie que pour les nombres entiers positifs.\n");
    } else {
        int i = 2;
        while (i <= nbr && f <= INT_MAX / i) {
            f *= i;
            i++;
        }

        if (f <= INT_MAX) {  // Vérification finale du résultat
            printf("La factorielle de %d est %d\n", nbr, f);
        } else {
            printf("Erreur : Le calcul de la factorielle dépasse les capacités du type int.\n");
        }
    }

  printf("La valeur de INT_MAX est : %d\n", INT_MAX);
 
  return 0;
}