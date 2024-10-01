#include <stdio.h>
#include <stdlib.h>

#define MAXDIM 9

int main() {
    int m, n, max, min;
    printf("Entrez le nombre de lignes : ");
    scanf("%d",&m);
    printf("Entrez le nombre de colonnes : ");
    scanf("%d",&n);

    char tab[MAXDIM][MAXDIM], tab2[MAXDIM][MAXDIM];
    char lettre = 'A';
    
    printf("Table de caractères \n");
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            tab[i][j] = lettre;
            //printf("%c en ligne %d et colonne %d\n", lettre, i, j);
            lettre++;

            if (lettre > 'Z') {
                lettre = 'A';
            }
        }
    }
    
    printf("\n");
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++)
            printf("%c  ", tab[i][j]);
        printf("\n");
    }
    printf("\n");
    
    printf("\nTable de caractères random\n");
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            // Utiliser la formule générique pour obtenir une lettre aléatoire entre 'A' et 'Z'.
            tab2[i][j] = 'A' + (int)(rand() / (RAND_MAX + 1.0) *('Z'-'A'+1));
            char c = tab2[i][j];
            //printf("%c en ligne %d et colonne %d\n", tab2[i][j], i, j);
        }
    }
    
    printf("\n");
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++)
            printf("%c  ", tab2[i][j]);
        printf("\n");
    }
    printf("\n");

// Calcul du nombre d'occurences par ligne
    int count[MAXDIM][26] = {{0}};
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++)
            count[i][tab2[i][j]-'A']++;
    }

    // Affichage du nombre d'occurences par ligne
    printf("         ");
    for (char c='A'; c<='Z'; c++)
        printf(" %c",c);
    printf("\n\n");
    for (int i=0; i<m; i++) {
        printf("Ligne %d: ",i+1);
        for (int j=0; j<26; j++)
            printf(" %d", count[i][j]);
        printf("\n");
    }
    printf("\n");
}