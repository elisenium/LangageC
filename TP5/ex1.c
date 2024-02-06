#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int nbMots = argc - 1;
    if (nbMots == 0)
    {
        printf("Usage: %s needs arguments in command line", argv[0]);
    }

    char** tabMots = malloc((argc-1)*sizeof(char*));

    for (int i = 0; i < argc-1; ++i) {
        tab[i] = malloc((strlen(argv[i+1])+1)*sizeof(char));
        if (!tabMots)
        {
            /* code */
        }
    }
    int i = 0;
    while(tab[i]) {
        int upperTab = toupper(tab[i]);
        fprintf(stderr, upperTab);
        i++;
    }

    return(0);
}
