#include <stdio.h>
#include <limits.h>

int main() {
  int nbr, i, f = 1.0;
 
  printf("Entrez un nombre pour calculer sa factorielle : ");
  scanf("%d", &nbr);
 
  for (i = 1; i <= nbr; i++)
    f = f * i;
 
  printf("%d! = %d\n", nbr, f);

  printf("\nLa valeur de INT_MAX est : %d\n", INT_MAX);
 
  return 0;
}