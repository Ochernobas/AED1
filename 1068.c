#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char expressao[1001];

  while (fgets(expressao, 1001, stdin) != NULL) {
    int parenteses = 0;
    int ok = 1;

    for (int i = 0; expressao[i] != '\0'; i++) {
      if (expressao[i] == '(') {
        parenteses++;
      } else if (expressao[i] == ')') {
        if (parenteses == 0) {
          ok = 0;
          break; // evita parenteses negativos
        }
        parenteses--;
      }
    }

    if (parenteses == 0 && ok == 1) {
      printf("correct\n");
    } else {
      printf("incorrect\n");
    }
  }

  return 0;
}
