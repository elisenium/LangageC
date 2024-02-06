#include <stdio.h>
#include <limits.h>

int main()
{
  double nbr, i, f = 1.0;
 
  printf("Entrez un nombre pour calculer sa factorielle : \n");
  scanf("%lf", &nbr);
 
  for (i = 1; i <= nbr; i++)
    f = f * i;
 
  printf("Factorielle de %lf = %lf\n", nbr, f);

  printf("La valeur de INT_MAX est : %d\n", INT_MAX);
 
  return 0;
}