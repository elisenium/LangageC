#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAXDIM 9
#define NB_LETTRES_ALPHABET 26

int main() {
  char tab[MAXDIM][MAXDIM];

  int nbLignes, nbColonnes;
  scanf("%d %d", &nbLignes, &nbColonnes);

  srand(time(NULL)); //Définition du générateur de nombre aléatoires par rapport au temps

  for (int i = 0; i < nbLignes; i++) {
    for (int j = 0; j < nbColonnes; j++) {
      char c = 'A' + (int)(rand()/(RAND_MAX+1.0)*('Z'-'A'+1));
      
      tab[i][j] = c;
      printf("%c ", tab[i][j]);
    }
    printf("\n");
  }

  printf("\n          ");
  for (char lettre = 'A'; lettre <= 'Z'; lettre++) {
    printf("%c ", lettre);
  }

  int tabOcc[MAXDIM][NB_LETTRES_ALPHABET] = {0};
  int numLettre;

  for (char lettre = 'A'; lettre <= 'Z'; lettre++) {
    int nbOccurences = 0;

    for (int i = 0; i < nbLignes; i++) {
      for (int j = 0; j < nbColonnes; j++) {
        if (tab[i][j] == lettre) {
          tabOcc[i][numLettre] += 1;
        }
      }
    }
    numLettre++;
  }

  for (int i = 0; i < nbLignes; i++) {
    printf("\nLigne %d : ", i+1);

    for (int j = 0; j < NB_LETTRES_ALPHABET; j++) {
      printf("%d ", tabOcc[i][j]);
    }
  }
  printf("\n\n");

  return 0;
}