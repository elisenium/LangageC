#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 29

int main(int argc, char *argv[]) {
    int nbMots = argc - 1;
    if (nbMots == 0)
    {
        printf("Usage: %s needs arguments in command line.\n", argv[0]);
    }
    if (nbMots > 27)
    {
        printf("Impossible: this word doesn't exist.");
        free(argv);
    }
    for (int i = 0; i < nbMots; ++i)
    {
        if (!tabMots)
        {
            printf("Error");
        }
    }

    while(fgets(argv[nbMots], stdin) != NULL) {
        fprintf("Mot lu : %s\nLongueur : %d", tabMots**, nbMots);
    }
    
    return(0);
}
