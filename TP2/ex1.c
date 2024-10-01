#include <stdio.h>
#include <stdlib.h>

#define SIZE 50

int main() {
    double moyenne, note, ecart, somme;

    int tab[SIZE];

    printf("Entrez les notes des étudiants, Ctrl-D pour terminer :\n");

    int taille = 0;
    while ((scanf("%d", &tab[taille]) != EOF)) {
        somme += tab[taille];
        taille++;
    }
    
    moyenne = somme/taille;
    printf("Moyenne = %.2f\n", moyenne);
    printf("Ecarts des étudiants par rapport à la moyenne :\n");

    for (int k = 0; k <= SIZE; ++k) {
        note = tab[k];
        if (note == 0) {
            break;
        }
        ecart = note-moyenne;
        printf("    Etudiant %d: %.2f - %.2f = %.2f\n", k+1, note, moyenne, ecart);
    }
}
