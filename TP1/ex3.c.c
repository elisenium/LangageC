#include <stdio.h>
#include <limits.h>

int main() {
  double nbr, i, f = 1.0;
 
  printf("Entrez un nombre pour calculer sa factorielle : ");
  scanf("%lf", &nbr);
 
  for (i = 1; i <= nbr; i++)
    f = f * i;
 
  printf("%lf! = %lf\n", nbr, f);

  printf("\nLa valeur de INT_MAX est : %d\n", INT_MAX);
 
  return 0;
}