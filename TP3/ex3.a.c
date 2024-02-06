#include <stdio.h>
#include <stdlib.h>

int main() {

    int nbData, nbPos, nbNeg;
    int *inputs, *positives, *negatives;

    printf("Entrez le nombre d'entrées voulues (0 pour terminer) : ");
    scanf("%d", &nbData);

    while(nbData > 0) {
        inputs = malloc(nbData*sizeof(int));
        if (inputs == NULL) {
            perror("Out of memory\n");
            exit(EXIT_FAILURE);
        }

        printf("Entrez les données : \n");
        nbNeg = nbPos = 0;
        for (int i = 0; i < nbData; ++i) {
            scanf("%d", &(inputs[i]));
            if (inputs[i] > 0) {
                nbPos++;
            } else {
                nbNeg++;
            }
        }

        positives = malloc(nbPos*sizeof(int));
        negatives = malloc(nbNeg*sizeof(int));
        if (positives == NULL || negatives == NULL) {
            perror("Out of memory\n");
            exit(EXIT_FAILURE);
        }

        nbNeg = nbPos = 0;
        for (int i = 0; i < nbData; ++i) {
            if (inputs[i] >= 0) {
                positives[nbPos] = inputs[i];
                nbPos++;
            } else {
                negatives[nbNeg] = inputs[i];
                nbNeg++;
            }
        }
        printf("Résultats : \n");
        for (int i = 0; i < nbPos; ++i) {
            printf("%d ", positives[i]);
        }
        printf("\n");

        for (int i = 0; i < nbNeg; ++i) {
            printf("%d ", negatives[i]);
        }
        printf("\n");

        free(inputs);
        free(positives);
        free(negatives);

        printf("Entrez le nombre d'entrées voulues (0 pour terminer) : ");
        scanf("%d", &nbData);
    }
}
