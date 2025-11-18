#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 1000000

int pilha[MAXN];
int fila[MAXN];
int pfila[MAXN];

int main() {
  int n;

  while (scanf("%d", &n) != EOF) {

    int comando, valor;

    int topo = -1;
    int frente = 0, costas = 0;
    int pfilatam = 0;

    int is_pilha = 1;
    int is_fila = 1;
    int is_pfila = 1;

    while (n--) {

      if (scanf("%d %d", &comando, &valor) != 2)
        return 0;

      if (comando == 1) {

        pilha[++topo] = valor;
        fila[costas++] = valor;

        int i = pfilatam++;
        pfila[i] = valor;

        while (i > 0) {
          int pai = (i - 1) / 2;

          if (pfila[pai] >= pfila[i])
            break;

          int tmp = pfila[pai];
          pfila[pai] = pfila[i];
          pfila[i] = tmp;

          i = pai;
        }

      } else {

        if (is_pilha) {
          if (topo < 0 || pilha[topo] != valor)
            is_pilha = 0;
          else
            topo--;
        }

        if (is_fila) {
          if (frente == costas || fila[frente] != valor)
            is_fila = 0;
          else
            frente++;
        }

        if (is_pfila) {
          if (pfilatam == 0 || pfila[0] != valor) {

            is_pfila = 0;

          } else {

            pfila[0] = pfila[--pfilatam];
            int i = 0;

            while (1) {
              int esq = 2 * i + 1;
              int dir = 2 * i + 2;
              int maior = i;

              if (esq < pfilatam && pfila[esq] > pfila[maior])
                maior = esq;

              if (dir < pfilatam && pfila[dir] > pfila[maior])
                maior = dir;

              if (maior == i)
                break;

              int tmp = pfila[i];
              pfila[i] = pfila[maior];
              pfila[maior] = tmp;

              i = maior;
            }
          }
        }
      }
    }

    int count = is_pilha + is_fila + is_pfila;

    if (count == 0)
      printf("impossible\n");
    else if (count > 1)
      printf("not sure\n");
    else {
      if (is_pilha)
        printf("stack\n");
      else if (is_fila)
        printf("queue\n");
      else
        printf("priority queue\n");
    }
  }

  return 0;
}
