#include <stdlib.h>
#include <stdio.h>

#define MAXDIM 9

int main() {
  int nbLignes, nbColonnes;
  
  scanf("%d %d", &nbLignes, &nbColonnes);
  
  char tab[MAXDIM][MAXDIM];

  char c = 'A';
  for (int i = 0; i < nbLignes; i++) {
  
    for (int j = 0; j < nbColonnes; j++) {
      tab[i][j] = c;
      printf("%c en ligne %d et colonne %d\n", tab[i][j], i, j);

      if (c == 'Z')
        c = 'A';
      else
        c++;
    }
  }
  return 0;
}