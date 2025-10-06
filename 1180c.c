// Exercício 1180c - Rafael Soares

// Bibliotecas usadas no código
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Tamanho máximo do array de números X
#define MAX 1000

// struct para armazenarmos o menor valor e sua posição de forma agrupada
typedef struct {
  int valor;
  int posicao;
} menor;

// Struct para definir os elementos da lista de números usando ponteiros
typedef struct {
  int elemento;
  struct no *proximo;
} no;

// Função para criar um novo nó, para a lista
no *criarNo(int valor) {
  no *novo_no =
      (no *)malloc(sizeof(no)); // Alocação dinâmica de memória para o nó
  novo_no->elemento = valor;    // Valores padrão do nó
  novo_no->proximo = NULL;
  return novo_no;
}

// Função para adicionar um novo nó ao final da lista encadeada
void adicionarNo(no **cabeca, int valor) {
  no *novo_no = criarNo(valor);
  if (*cabeca == NULL) {
    *cabeca = novo_no;
  } else {
    no *atual = *cabeca;
    while (atual->proximo != NULL) {
      atual = atual->proximo;
    }
    atual->proximo = novo_no;
  }
}

int main() {          // Função principal do código
  char buffer[20000]; // Variável que receberá a string de valores (input do
                      // usuário)
  int N;              // Tamanho da string de valores (input do usuário)
  int contador = 0;
  no *Xcabeca = NULL;
  menor menor_valor;
  scanf("%d", &N); // Lê a quantidade de valores
  getchar();       // Limpa o '\n' que fica restante

  fgets(buffer, sizeof(buffer),
        stdin); // Recebe a string de valores do usuário e armazena em buffer

  char *token = strtok(
      buffer, " "); // Função do <string.h> para separar a string a cada espaço
  while (token != NULL) {
    adicionarNo(&Xcabeca,
                atoi(token)); // Converte o número de char para int e cria um
                              // novo nó na lista com esse número
    token = strtok(NULL, " ");
  }

  menor_valor.valor =
      Xcabeca
          ->elemento; // Atualiza o menor valor com o primeiro elemento do vetor
  menor_valor.posicao = 0;

  no *X = Xcabeca;
  while (X != NULL) {                      // Loop para ler cada elemento de X
    if (X->elemento < menor_valor.valor) { // Confere se o valor atual é menor
                                           // do que o atual menor valor
      menor_valor.valor =
          X->elemento; // Atualiza o menor valor com o valor atual
      menor_valor.posicao = contador;
    }
    X = X->proximo;
    contador++; // Atualiza a variável da posição atual da lista
  }
  printf("Menor valor: %d\nPosicao: %d", menor_valor.valor,
         menor_valor.posicao);
  printf("\n");

  X = Xcabeca;
  while (
      X !=
      NULL) { // Loop para liberar os espaços de memória alocados anteriormente
    no *prox_no = X->proximo;
    free(X);
    X = prox_no;
  }

  return 0; // Retorna 0 para finalizar a função main
}