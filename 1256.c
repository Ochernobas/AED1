#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int M, C;
        scanf("%d %d", &M, &C);

        // tabela hash (cada posição guarda lista de ints)
        int tabela[1000][1000];
        int tamanho[1000] = {0};

        for (int i = 0; i < M; i++)
            tamanho[i] = 0;    // zera lista de cada posição

        // leitura dos valores
        for (int i = 0; i < C; i++) {
            int x;
            scanf("%d", &x);

            int h = x % M;

            tabela[h][tamanho[h]++] = x;
        }

        // impressão
        for (int i = 0; i < M; i++) {
            printf("%d ->", i);
            for (int j = 0; j < tamanho[i]; j++) {
                printf(" %d ->", tabela[i][j]);
            }
            printf(" \\\n");
        }

        if (T > 0)     // NÃO imprime linha extra após o último caso
            printf("\n");
    }

    return 0;
}
