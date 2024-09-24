#include <stdlib.h>
#include <stdio.h>

int main() {
    int a, b, quotient, reste;
    printf("Entrez deux entiers positifs : \n");
    scanf("%d %d",&a, &b);

    while (b == 0) {
        printf("b ne peut pas être égal à 0. Entrez une nouvelle valeur pour b : \n");
        scanf("%d", &b);
    }

    if (a < b) {
        int temp = a;
        a = b;
        b = temp;
    }

    quotient = 0;
    reste = a;

    while (reste >= b) {
        reste -= b;
        quotient++;
    }

    printf("Quotient : %d\n", quotient);
    printf("Reste : %d\n", reste);

    return 0;

}