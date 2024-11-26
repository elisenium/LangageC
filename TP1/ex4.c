#include <stdio.h>
#include <limits.h>

int main() {
  int codeASCII, nbr, i, f, validInput;

  //printf("Entrez un nombre pour calculer sa factorielle (compris entre 0 et 9) : ");
  while (1) {
    validInput = 1;
    nbr = 0;
    int isFirstChar = 1;
    int inputLength = 0;

    while ((codeASCII = getchar()) != '\n' && codeASCII != EOF) {
      inputLength++;

      if (codeASCII < '0' || codeASCII > '9') {
        validInput = 0;

      } else {
        if (isFirstChar) {
          nbr = codeASCII - '0';
          isFirstChar = 0;

        } else {
          nbr = nbr * 10 + (codeASCII - '0');

        }
      }
    }

    if (codeASCII == EOF) {
      break;
    }

    if (inputLength == 0) {
      printf("Error: empty line\n");

    } else if (inputLength > 1) {
      printf("Error: too many characters\n");

    } else if (!validInput || nbr < 0 || nbr > 9) {
      printf("Error: invalid character\n");

    } else {
      //printf("\ncaractere lu '%d' - code ascii %d\n", nbr, nbr + '0');
      i = 2;
      f = 1;

      while (i <= nbr && f <= INT_MAX / i) {
        f *= i;
        i++;
      }

      if (i > nbr) {
        printf("%d! = %d\n", nbr, f);
      }
    }
    //printf("Entrez un nombre pour calculer sa factorielle (compris entre 0 et 9) : ");
  }
  return 0;
}