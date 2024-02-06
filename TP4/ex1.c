#include <stdio.h>
#include <stdlib.h>

int main() {
    int nLignes, nbColonnes;

    printf("Hauteur = ? ");
    scanf("%d", &nbLignes);
    printf("Largeur = ? ");
    scanf("%d", &nbColonnes);

    char** cases = (char**)malloc(nbLignes*sizeof(char *));
    int* remplissageCol = (int*)malloc(nbColonnes*sizeof(int));
    if (cases == NULL || remplissageCol == NULL) {
        perror("Out of memory\n");
        exit(1);
    }

    for (int i = 0; i < nbLignes; ++i) {
        cases[i] = (char *)malloc(nbLignes*sizeof(char));
        if (cases[i] == NULL) {
            perror("Out of memory\n");
            exit(1);
        }
    }

    for (int i = 0; i < nbLignes; ++i) {
        for (int j = 0; j < nbColonnes; ++j) {
            cases[i][j] = '.';
        }
    }
    
    exit(0);
}