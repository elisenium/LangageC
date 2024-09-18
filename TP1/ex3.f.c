#include <stdio.h>
#include <limits.h>

int main() {
  int nbr, i = 2, f = 1;
 
  printf("Entrez un nombre pour calculer sa factorielle : ");
  scanf("%d", &nbr);

  if (nbr < 0) {
    printf("La factorielle n'est définie que pour les nombres entiers positifs.\n");

  } else {
    while (i <= nbr && f <= INT_MAX / i) {
      f *= i;
      i++;
    }

    if (i > nbr) {
      printf("%d! = %d\n", nbr, f);

    } else {
      printf("Erreur : Le calcul de la factorielle dépasse les capacités du type int.\n");
    }
    
  }

  printf("\nLa valeur de INT_MAX est : %d\n", INT_MAX);
  return 0;
}