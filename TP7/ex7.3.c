#include <stdlib.h>
#include <stdio.h>

// Réponse à l'exercice : Il faut faire un malloc !

// Correction : 

/* Crée un tableau avec les puissances d’un nombre
 * PRE: n: nombre entier strictement positif
 * RES: renvoie un tableau de taille n+1 contenant les puissances de n
 */
int* creerTable (int n) {
    /* Début correction */
    int* t = (int*)malloc((n+1)*sizeof(int));
    if (t == NULL) {
        perror("Error: dynamic allocation");
    }
    /* Fin correction */
    
    t[0] = 1;
    for (int i=1; i<=n; i++)
        t[i] = t[i-1] * n;

    return t;
}

int main() {
    // Test
    int size = 5;
    int* tab = creerTable(size);

    for (int i = 0; i <= size; i++) {
        printf("%d\n", tab[i]);
    }

    free(tab);
}