#include <stdlib.h>
#include <stdio.h>

int main() {
    int a;
    printf("Entrez un nombre entier strictement positif :");
    scanf("%d", &a);
    for (int i = 1; i < a; ++i) {
        if (a%i == 0)
        {
            printf("%d\n", i);
        }
    }
}