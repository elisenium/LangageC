#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char** copierArgs (char** tab, int n, int* ncp);
void trier (char** tab, int n);
void afficher (char** tab, int n);


int main (int argc, char* argv[]) {
   // Copie profonde des arguments du programme
   int taille = argc-1;
   int sz;
   
   char** tab = copierArgs(argv+1, argc-1, &sz);
   if (tab == NULL) {
	   exit(1);
    }

   // Affichage du tableau
   printf("Arguments non triés :\n");
   afficher(tab, sz);

   // Tri du tableau
   trier(tab, sz);

   // Affichage du tableau trié
   printf("Arguments triés :\n");
   afficher(tab, sz);

   // Libération de la mémoire dynamique
   for (int i = 0; i < argc-1; i++) {
        free(tab[i]);
   }
   free(tab);
   
   return 0;
}

/**
 * PRE: tab: tableau de n chaînes de caractères
 * POST: *ncp: nombre de chaînes dans le tableau renvoyé
 * RES: renvoie un tableau contenant les chaînes de tab sans doublon
 *      (taille logique = taille physique); NULL si une erreur s'est produite
 */
char** copierArgs(char** tab, int n, int* ncp) {
   
   char** tabCopie = (char**)malloc(n*sizeof(char*));
   if (tabCopie == NULL){
        return NULL;
   }
   
   for (int i = 0; i < n; i++) {
        tabCopie[i] = (char*)malloc((strlen(tab[i])+1)*sizeof(char));
        if (tabCopie[i] == NULL){
            return NULL;
        }
        
        bool exists = false;
        for (int j = 0; j < *ncp; j++) {
            if (strcmp(tabCopie[j], tab[i]) == 0) {
                exists = true;
                break;
            }
        }
        
        if (!exists) {
            strcpy(tabCopie[i], tab[i]);
            *ncp += 1;
        }
   }
   
   return tabCopie;
}

/**
 * PRE: tab: tableau de n chaînes de caractères
 * POST: les n chaînes de tab sont triées par ordre alphabétique
 *       (algorithme: tri par sélection)
 */
void trier (char** tab, int n) {

    // Cette fonction ne devrait pas créer de nouvelles chaînes,
    // elle ne fait que manipuler des adresses.
    int min;
    char* temp;

    for (int i = 0; i < n-1; i++) {
        min = i;
        for (int j = i+1; j < n; j++) {
            if (strcmp(tab[j], tab[min]) < 0) {
                min = j;
            }
        }
        if (min != i) {
            temp = tab[i];
            tab[i] = tab[min];
            tab[min] = temp;
        }
    }
}

/**
 * PRE: tab: tableau de n chaînes de caractères
 * POST: affiche les chaînes de tab (à raison d'une par ligne,
 *       précédée par leur numéro)
 */
void afficher (char** tab, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d - '%s'\n", i+1, tab[i]);
    }
}