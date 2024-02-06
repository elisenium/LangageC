#include <stdio.h>
#include <stdlib.h>

int main() {

    int nbData, nbPos, nbNeg;
    int *inputs, *positives,*negatives;

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
        for (int* ptr = inputs; ptr-inputs < nbData; ptr++) {
            scanf("%d", ptr);
            if (*ptr >= 0) {
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

        int* ptrP = positives;
        int* ptrN = negatives;

        for (int* ptr = inputs; ptr-inputs < nbData; ptr++) {
            if (*ptr >= 0) {
                *ptrP = *ptr;
                ptrP++;
            } else {
                *ptrN = *ptr;
                ptrN++;
            }
        }
        printf("Résultats : \n");
        for (int* ptrP = positives; ptrP-positives < nbPos; ptrP++) {
            printf("%d ", *ptrP);
        }
        printf("\n");

        for (int* ptrN = negatives; ptrN-negatives < nbNeg; ptrN++) {
            printf("%d ", *ptrN);
        }
        printf("\n");

        free(inputs);
        free(positives);
        free(negatives);

        printf("Entrez le nombre d'entrées voulues (0 pour terminer) : ");
        scanf("%d", &nbData);
    }
    exit(0);
}
