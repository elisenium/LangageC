#include <stdio.h>
#include <stdlib.h>

#define MAXDIM 9

int main() {

    printf("Entrez le nombre de lignes : \n");
    int m;
    scanf("%d",&m);
    printf("Entrez le nombre de colonnes : \n");
    int n;
    scanf("%d",&n);

    
    char lettre = 'A';
    char tab[MAXDIM][MAXDIM];
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            tab[i][j] = lettre;
            printf("%c en ligne %d et colonne %d\n", tab[i][j], i, j);
            lettre++;

            if (lettre > 'Z') {
                lettre = 'A';
            }
        }
    }
    exit(0);
}
