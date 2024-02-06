#include <stdlib.h>
#include <stdio.h>

int main() {
    for (char c = 'A'; c <= 'Z'; c++)
        printf("Caractère = '%c'    code déc. = %d      code hexa. = %x\n",c,c,c);
    for (char c = '1'; c <= '9'; c++)
        printf("Caractère = '%c'    code déc. = %d      code hexa. = %x\n",c,c,c);
}