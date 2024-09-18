#include <stdlib.h>
#include <stdio.h>

int main() {
    int a, b, temp;

    printf("Entrez le premier entier : ");
    scanf("%d", &a);

    printf("Entrez le second entier : ");
    scanf("%d", &b);

    printf("\n");
    printf("AVANT : a = %d; b = %d\n", a, b);

    temp = a;
    a = b;
    b = temp;

    printf("APRÈS : a = %d; b = %d\n", a, b);

    exit(0);
}
