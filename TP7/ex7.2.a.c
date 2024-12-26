#include <stdio.h>
#include <stdlib.h>

void permuter(int* a, int* b) {
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x, y;
    
    printf("Entrez l'entier 1 : ");
    scanf("%d", &x);
    printf("Entrez l'entier 2 : ");
    scanf("%d", &y);
    
    printf("\nAvant permutation :\n");
    printf("x = %d; y = %d\n\n", x, y);

    permuter(&x, &y);

    printf("Après permutation :\n");
    printf("x = %d; y = %d\n", x, y);
    
}