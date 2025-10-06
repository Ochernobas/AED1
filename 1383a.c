// Exercício 1383a - Rafael Soares

// Bibliotecas usadas no código
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int matriz[9][9]; // vetor 2d de 9x9, representando as matrizes que virão a
                    // serem digitadas
  int auxiliar;     // Variável usada para percorrer o vetor matriz
  int N; // Variável para armazenar o número de matrizes a serem digitadas
         // (input do usuário)
  char buffer[1000]; // Variável para armazenar cada linha da matriz digitada
                     // (input do usuário)

  int confere_linha[9];  // Variável usada para auxiliar na correção de cada
                         // linha da matriz
  int confere_coluna[9]; // Variável usada para auxiliar na correção de cada
                         // coluna da matriz
  int segmento[9][9];    // Variável usada para auxiliar na correção de cada
                         // segmento 3x3 da matriz
  int contadores[9];     // Variável usada para percorrer o vetor segmento

  int aprovado =
      0; // Variável usada para definir o output final (0 = SIM, 1 = NÃO)

  scanf("%d", &N); // Lê a quantidade de valores
  getchar();       // Limpa o '\n' que fica restante

  for (int i = 0; i < N; i++) { // Loop para cada iterção de matriz
    for (int z = 0; z < 9;
         z++) { // Loop utillizado para resetar o vetor contadores
      contadores[z] = 0;
    }

    for (int j = 0; j < 9;
         j++) { // Loop usado para percorrer cada linha da matriz (LER MATRIZ)
      auxiliar = 0;
      fgets(buffer, sizeof(buffer), stdin); // input de linha do usuário

      char *token = strtok(
          buffer,
          " "); // Função do <string.h> para separar a string a cada espaço
      while (token != NULL) {
        matriz[j][auxiliar] = atoi(token); // Converte o número de char para int
                                           // e armazena no vetor matriz
        token = strtok(NULL, " ");
        auxiliar++;
      }
    }

    for (int j = 0; j < 9; j++) { // Loop usado para percorrer cada linha da
                                  // matriz (CONFERIR MATRIZ)
      for (int k = 0; k < 9;
           k++) { // Loop usado para percorrer cada coluna da matriz

        int linha = j / 3; // Variáveis usadas para armazenar os valores no
                           // segmento certo (Daqui)
        int coluna = k / 3;
        segmento[(linha * 3) + coluna][contadores[(linha * 3) + coluna]] =
            matriz[j][k];
        contadores[(linha * 3) + coluna]++; // (Até aqui)

        for (int w = 0; w < k;
             w++) { // Loop para conferir cada linha e coluna da matriz, caso
                    // qualquer valor tenha se repetido em qualquer uma das
                    // duas, aprovado = 1
          if (matriz[j][k] == confere_linha[w] ||
              matriz[k][j] == confere_coluna[w]) {
            aprovado = 1;
          }
        }
        confere_linha[k] =
            matriz[j][k]; // Armazena o valor da matriz na variável da linha
        confere_coluna[k] =
            matriz[k][j]; // Armazena o valor da matriz na variável da coluna
      }
    }

    for (int j = 0; j < 9; j++) { // Loop usado para percorrer cada linha da
                                  // matriz (CONFERIR SEGMENTO)
      for (int k = 0; k < 9;
           k++) { // Loop usado para percorrer cada coluna da matriz
        for (int w = 0; w < k; w++) {
          if (segmento[j][w] == segmento[j][k]) {
            aprovado = 1;
          }
        }
      }
    }

    if (aprovado == 1) {
      printf("Instancia %d\nNAO\n\n", i + 1);
    } else {
      printf("Instancia %d\nSIM\n\n", i + 1);
    }

    aprovado = 0;
  }

  return 0; // Retorno final da função
}