#include <stdlib.h>
#include <stdio.h>

#define MAXDIM 9

int main() {
  int nbLignes, nbColonnes;
  
  scanf("%d %d", &nbLignes, &nbColonnes);
  
  char tab[MAXDIM][MAXDIM];

  char min = 'A';
  char max = 'Z';

  for (int i = 0; i < nbLignes; i++) {
  
    for (int j = 0; j < nbColonnes; j++) {
      char c = 'A' + (int)(rand()/(RAND_MAX+1.0)*(max-min+1));

      tab[i][j] = c;
      printf("%c en ligne %d et colonne %d\n", tab[i][j], i, j);
    }
  }
  return 0;
}