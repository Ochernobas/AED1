// Exercício 1180a - Rafael Soares

//Bibliotecas usadas no código
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Tamanho máximo do array de números X
#define MAX 1000 

//struct para armazenarmos o menor valor e sua posição de forma agrupada
typedef struct {
  int valor;
  int posicao;
} menor;

int main() { //Função principal do código
  char buffer[20000]; //Variável que receberá a string de valores (input do usuário)
  int N; //Tamanho da string de valores (input do usuário)
  int X[MAX], cont = 0; //Vetor que armazenará os números em inteiro e contador da sua posição
  menor menor_valor;
  scanf("%d", &N); //Lê a quantidade de valores 
  getchar(); //Limpa o '\n' que fica restante

  fgets(buffer, sizeof(buffer), stdin); //Recebe a string de valores do usuário e armazena em buffer

  char *token = strtok(buffer, " "); //Função do <string.h> para separar a string a cada espaço
  while (token != NULL) {
    X[cont++] = atoi(token); //Converte o número de char para int e armazena no vetor X
    token = strtok(NULL, " ");
  }

  menor_valor.valor = X[0]; //Atualiza o menor valor com o primeiro elemento do vetor
  menor_valor.posicao = 0;

  for (int i = 0; i < cont; i++) { //Loop para ler cada elemento de X
    if (X[i] < menor_valor.valor) { //Confere se o valor atual é menor do que o atual menor valor
      menor_valor.valor = X[i]; //Atualiza o menor valor com o valor atual
      menor_valor.posicao = i;
    }
  }
  printf("Menor valor: %d\nPosicao: %d", menor_valor.valor,
         menor_valor.posicao);
  printf("\n");

  return 0; //Retorna 0 para finalizar a função main
}