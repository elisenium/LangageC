#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#define NB_CHAR 256
#define MAX_PHRASES 100

int unEntierAuHasardEntre(int valMin, int valMax);

typedef struct {
    char english[NB_CHAR];
    char french[NB_CHAR];
} Translation;

int main(int argc, char* argv[]) {
    Translation translations[MAX_PHRASES];
    int count = 0;

    /***********************************/
    /* PHASE 1: SAISIE DES TRADUCTIONS */
    /***********************************/
   
    printf("Entrez des phrases en anglais suivies de leur traduction française,");
    printf("à raison d'une phrase par ligne.\n");
    printf("Chaque phrase comprend au plus %d caractères.\n", NB_CHAR-2);
    printf("Entrez Ctrl-D (EOF) pour terminer la saisie.\n\n");
    
    while (count < MAX_PHRASES && fgets(translations[count].english, NB_CHAR, stdin) != NULL) {
        // Enlever le saut de ligne à la fin de la phrase
        translations[count].english[strcspn(translations[count].english, "\n")] = '\0';
        
        printf("Traduction: ");
        if (fgets(translations[count].french, NB_CHAR, stdin) == NULL) break;
        translations[count].french[strcspn(translations[count].french, "\n")] = '\0';
        
        count++;
    }
     
    /**************************************/
    /* PHASE 2: AFFICHAGE DES TRADUCTIONS */
    /**************************************/
   
    printf("\nTRADUCTIONS INTRODUITES:\n\n");
    for (int i = 0; i < count; i++) {
        printf("'%s' --> '%s'\n", translations[i].english, translations[i].french);
    }
   
    /*************************/
    /* PHASE 3: ENTRAINEMENT */
    /*************************/
   
    printf("\nTRADUISEZ LA PHRASE SUIVANTE:\n\n");
    freopen("/dev/tty", "rw", stdin);  // ne pas modifier! (permet de lire à nouveau sur stdin après EOF)
    
    srand((unsigned) time(NULL));  // Réinitialiser la graine du générateur de nombres aléatoires
    
    int randomIndex = unEntierAuHasardEntre(0, count - 1);
    printf("%s\n", translations[randomIndex].english);
    
    char userTranslation[NB_CHAR];
    do {
        printf("Traduction: ");
        fgets(userTranslation, NB_CHAR, stdin);
        userTranslation[strcspn(userTranslation, "\n")] = '\0';
        
        if (strcmp(userTranslation, translations[randomIndex].french) == 0) {
            printf("Correct!\n");
            break;
        } else {
            printf("Faux. Réessayez!\n");
        }
    } while (1);
   
    return 0;
}

/**
 * Génère une valeur entière aléatoire
 * PRE: valMin, valMax: deux valeurs entières telles que valMin <= valMax
 * RES: renvoie une valeur entière pseudo-aléatoire comprise 
 *      dans l'intervalle [valMin,valMax]
 **/
int unEntierAuHasardEntre(int valMin, int valMax) {
    // Initialisation de la 'random seed'
    return valMin + rand() % (valMax - valMin + 1);
}
