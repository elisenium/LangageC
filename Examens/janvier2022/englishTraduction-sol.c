#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

#define NB_CHAR 256
#define MAX_PHRASES 10


int unEntierAuHasardEntre (int valMin, int valMax);


int main (int argc, char* argv[])
{
   /***********************************/
   /* PHASE 1: SAISIE DES TRADUCTIONS */
   /***********************************/
   
   printf("Entrez des phrases en anglais suivies de leur traduction française,");
   printf("à raison d'une phrase par ligne.\n");
   printf("Chaque phrase comprend au plus %d caractères.\n", NB_CHAR-2);
   printf("Entrez Ctrl-D (EOF) pour terminer la saisie.\n\n");
   
   int nbMots = 0;

   char** tabFR = (char**)malloc(MAX_PHRASES*sizeof(char*));
   if (tabFR == NULL) return 0;

   char** tabEN = (char**)malloc(MAX_PHRASES*sizeof(char*));
   if (tabEN == NULL) return 0;

   char buffer[NB_CHAR];

   printf("Entrez la phrase en anglais puis sa traduction en français :\n");
   while (fgets(buffer, NB_CHAR, stdin) != NULL) {
        if (nbMots == MAX_PHRASES) {
            tabFR = (char**)realloc(tabFR, (nbMots*2)*sizeof(char*));
            tabEN = (char**)realloc(tabEN, (nbMots*2)*sizeof(char*));
        }

        if (buffer[strlen(buffer)-1] == '\n') {
            buffer[strlen(buffer)-1] = '\0';
        }
        
        tabEN[nbMots] = (char*)malloc((strlen(buffer)+1)*sizeof(char));
        if (tabEN[nbMots] == NULL) return 0;
        strcpy(tabEN[nbMots], buffer);

        if (fgets(buffer, NB_CHAR, stdin) == NULL) {
            break;
        }
        
        if (buffer[strlen(buffer)-1] == '\n') {
            buffer[strlen(buffer)-1] = '\0';
        }
        
        tabFR[nbMots] = (char*)malloc((strlen(buffer)+1)*sizeof(char));
        if (tabFR[nbMots] == NULL) return 0;
        strcpy(tabFR[nbMots], buffer);
        
        nbMots++;
   }
   
   
     
   /**************************************/
   /* PHASE 2: AFFICHAGE DES TRADUCTIONS */
   /**************************************/
   
   printf("\nTRADUCTIONS INTRODUITES:\n\n");

   for (int i = 0; i < nbMots; i++) {
        printf("%s => %s\n", tabEN[i], tabFR[i]);
   }
   
   
   
   /*************************/
   /* PHASE 3: ENTRAINEMENT */
   /*************************/
   
   printf("\nTRADUISEZ LA PHRASE SUIVANTE:\n\n");
   freopen("/dev/tty", "rw", stdin);  /// ne pas modifier! (permet de lire à nouveau sur stdin après EOF)

   int index = unEntierAuHasardEntre(0, nbMots-1);

   printf("%s\n\n", tabEN[index]);

   bool traduction = false;

   while (!traduction) {
       printf("Traduction : ");
       fgets(buffer, NB_CHAR, stdin);
       if (buffer[strlen(buffer)-1] == '\n') {
            buffer[strlen(buffer)-1] = '\0';
       }

       if (strcmp(buffer, tabFR[index]) == 0) {
            traduction = true;
       } else {
            printf("Faux. Réessayez!\n\n");
       }
   }

   printf("Correct!\n");
   
   for (int i = 0; i < nbMots; i++) {
        free(tabFR[i]);
        free(tabEN[i]);
   }
   
   free(tabFR);
   free(tabEN);
}


/**
 * Génère une valeur entière aléatoire
 * PRE: valMin, valMax: deux valeurs entières telles que valMin <= valMax
 * RES: renvoie une valeur entière pseudo-aléatoire comprise 
 *      dans l'intervalle [valMin,valMax]
 **/
int unEntierAuHasardEntre (int valMin, int valMax) {
   // Initialisation de la 'random seed'
   srand((unsigned) time(NULL));
   
   // Génération d'une valeur aléatoire
   int nombre = valMin + (int)(rand()/(RAND_MAX+1.0)*(valMax-valMin+1));
   return nombre;
}
