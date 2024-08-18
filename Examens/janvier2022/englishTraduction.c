#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define NB_CHAR 256


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
   
   // TODO
   
   
     
   /**************************************/
   /* PHASE 2: AFFICHAGE DES TRADUCTIONS */
   /**************************************/
   
   printf("\nTRADUCTIONS INTRODUITES:\n\n");

   // TODO
   
   
   
   /*************************/
   /* PHASE 3: ENTRAINEMENT */
   /*************************/
   
   printf("\nTRADUISEZ LA PHRASE SUIVANTE:\n\n");
   freopen("/dev/tty", "rw", stdin);  /// ne pas modifier! (permet de lire à nouveau sur stdin après EOF)
   
   // TODO
   
   
   
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
