#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER 256

void permuter(char** a, char** b) {
    char* temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    char c1[BUFFER+1], c2[BUFFER+1];
    char* pc1 = c1;
    char* pc2 = c2;

    printf("Première chaîne de caractère : ");
    fgets(c1, BUFFER+1, stdin);
    c1[strlen(pc1)-1] = '\0';

    printf("Deuxième chaîne de caractère : ");
    fgets(c2, BUFFER+1, stdin);
    c2[strlen(pc2)-1] = '\0';
    
    printf("Avant permutation :\n");
    printf("c1 = '%s'; c2 = '%s'\n\n", c1, c2);

    permuter(&pc1, &pc2);

    printf("Après permutation :\n");
    printf("c1 = '%s'; c2 = '%s'\n\n", pc1, pc2);

    return 0;
}