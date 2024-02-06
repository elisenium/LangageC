#include <stdio.h>
#include <stdlib.h>

#define SIZE 50

int main() {
    double moyenne, somme, note, ecart, taille;

    int tab[SIZE];

    printf("Entrez les notes des étudiants, Ctrl-D pour terminer :\n");

    for (int i = 0; i < SIZE; ++i) {
        scanf("%d",&tab[i]);
        somme += tab[i];
    }

    for (int j = 0 ; j < SIZE; j++) {
        taille++;
        if (tab[j+1] == 0)
        {
            break;
        }
    }
    
    moyenne = somme/taille;
    printf("Moyenne = %f\n", moyenne);
    printf("Ecarts des étudiants par rapport à la moyenne :\n");

    for (int k = 0; k <= SIZE; ++k) {
        note = tab[k];
        if (note == 0)
        {
            break;
        }
        ecart = note-moyenne;
        printf("    Etudiant %d: %f - %f = %f\n", k+1, note, moyenne, ecart);
    }
}