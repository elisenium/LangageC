#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define BUFFER 256


void imprimerTable(char* legende, int* tab, int sz);
bool ajouterTable(int** tab, int* tailleL, int* tailleP, int val);
int chargerTable(char** mots, int nbrMots, int** tab, int* tailleP);
char* lireLigne();

/* PRE : legende : chaîne de caractères
 *       tab : pointeur vers un tableau d'entiers ou NULL
 *       sz : taille logique du tableau tab
 * POST : Affiche la légende suivi du contenu du tableau tab.
 *        Si tab est NULL ou sz vaut 0, spécifier que la table est vide.
 */
void imprimerTable(char* legende, int* tab, int sz) {
    // Affichage légende
    printf("%s:\n", legende);

    // Si table vide
    if (sz == 0 || tab == NULL) {
        printf("        [table vide]\n\n");
    }
    // Si table pas vide, on l'affiche
    else {
        for (int i = 0; i < sz; i++) {
            printf("        %d\n", tab[i]);
        }
        printf("\n");
    }
}

/* PRE : tab : pointeur vers un tableau d'entiers ou vide
 *       tailleL : pointeur vers un entier représentant la taille logique de tab
 *       tailleP : pointeur vers un entier représentant la taille physique de tab
 *       val : nombre entier à ajouter
 * POST : Ajoute l'entier val au tableau tab.
 *        Agrandissement du tableau si necessaire (x2).
 *        Mise à jour des tailles physiques tailleP et logiques tailleL.
 * RES : true si l'ajout réussit, false sinon.
 */
bool ajouterTable(int** tab, int* tailleL, int* tailleP, int val) {
    if (*tab == NULL) {
        // 1er appel sur table vide : taille physique de 3
        *tailleP = 3;
        *tab = (int*)malloc((*tailleP) * sizeof(int));
        if (*tab == NULL) {
            perror("Malloc error.");
            return false;
        }
    } 
    // Si table remplie : on double sa taille
    else if (*tailleL >= *tailleP) {
        *tailleP *= 2;
        int* temp = realloc(*tab, (*tailleP) * sizeof(int));
        if (temp == NULL) {
            perror("Malloc error.");
            return false;
        }
        *tab = temp;
    }
    // Ajout de la nouvelle valeur au dernier indice
    (*tab)[*tailleL] = val;
    (*tailleL)++;
    return true;
}

/* PRE : mots : tableau de chaînes de caractères représentant des entiers
 *       nbrMots : taille logique de mots
 *       tab : pointeur vers un tableau d'entiers ou NULL
 *       tailleP : taille physique de tab
 * POST : Remplissage de tab avec les chaînes de caractères de mots converties en entiers
 *        Réallocation mémoire si besoin.
 *        Mise à jour de la taille physique tailleP
 * RES : Retourne la taille logique de tab. En cas d'erreur, elle retourne -1.
 */
int chargerTable(char** mots, int nbrMots, int** tab, int* tailleP) {
    int tailleL = 0;

    // Réallocation mémoire
    int* temp = (int*)realloc(*tab, nbrMots* sizeof(int));
    if (temp == NULL) {
        perror("Malloc error.");
        return -1;
    }
    *tab = temp;

    // Ajout des nouveaux éléments au tableau
    for (int i = 0; i < nbrMots; i++) {
        int value = atoi(mots[i]); // Conversion char -> int
        (*tab)[i] = value;
        tailleL++;
    }

    // Mise à jour de la taille physique
    *tailleP += nbrMots;

    return tailleL;
}

/* POST : Lecture d'une ligne de caractère sur stdin et supprime le retour à la ligne
 * RES : Pointeur vers la ligne lue. En cas d'erreur ou EOF, elle retourne NULL.
 */
char* lireLigne() {
    char ligne[BUFFER];

    // Lecture ligne
    if (fgets(ligne, BUFFER, stdin) == NULL) {
        return NULL;
    }

    // Transformation '\n' en '\0'
    int tailleLigne = strlen(ligne);
    if (tailleLigne > 0 && ligne[tailleLigne - 1] == '\n') {
        ligne[tailleLigne - 1] = '\0';
    }

    // Allocation mémoire
    char* ligneModifiee = (char*)malloc((tailleLigne + 1) * sizeof(char));
    if (ligneModifiee == NULL) {
        perror("Error: dynamic memory allocation error");
        return NULL;
    }

    // Copie de la ligne modifiée dans la mémoire allouée
    strcpy(ligneModifiee, ligne);
    return ligneModifiee;
}


int main(int argc, char* argv[]) {
    int* t = NULL;
    int tailleLogique = 0;
    int taillePhysique = 0;

    // Si aucun argument
    if (argc < 2) {
        fprintf(stderr, "Usage: %s argv1 argv2...\n", argv[0]);
        return 1;
    }
    
    imprimerTable("Avant traitement", t, tailleLogique);

    if (chargerTable(argv+1, argc-1, &t, &taillePhysique) == -1) {
        fprintf(stderr, "Error: unable to load table.\n");
        return 1;
    }
    tailleLogique = argc - 1;
    
    imprimerTable("Table des arguments", t, tailleLogique);

    printf("Entrez des entiers à ajouter à la table [un par ligne ; Ctrl-D pour terminer]:\n");

    char* ligne;
    while ((ligne = lireLigne()) != NULL) {
        int val = atoi(ligne);
        if (!ajouterTable(&t, &tailleLogique, &taillePhysique, val)) {
            fprintf(stderr, "Error: unable to add the value %d to the table.\n", val);
            free(ligne);
            return 1;
        }
        free(ligne);
    }
    printf("\n");
    imprimerTable("Table complétée", t, tailleLogique);
    
    free(t);
    return 0;
}