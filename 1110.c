//Bibliotecas utilizadas no código
#include <stdio.h>
#include <stdlib.h>

//Função que atualiza as posições do vetor, joga o primeiro pra trás, e o segundo pra frente
void atualizaVetor(int v[], int tamanho) {
  int aux = 0;
  aux = v[1];

  //Primeiro, joga todo mundo uma posição pra frente (Visto que o primeiro elemento foi excluído no main)
  for (int j = 1; j < tamanho; j++) {
    v[j - 1] = v[j];
  }

  //Depois, joga o novo primeiro elemento pra última posição do vetor 
  //(Importante fazer isso nesse momento pois se o vetor estiver completamente ocupado, só agora vai ter uma posição disponível pra ele lá atras)
  v[tamanho - 1] = v[0];

  //Depois, joga todo mundo uma posição pra frente de novo
  for (int j = 1; j < tamanho; j++) {
    v[j - 1] = v[j];
  }
}

//Função principal do programa
int main() {
  //tam controla quando o usuário quer parar 
  //tamanho controla a quantidade atual de elementos no vetor
  //cdescartes controla a quantidade atual de elementos no vetor descartes
  int tamanho, tam = 1, cdescartes = 0; 
  //vetor é o vetor principal do programa
  //descartes armazena os números descartados
  int vetor[50], descartes[50];

  while (tam != 0) { //enquanto o usuário quiser continuar (A atividade garante que não será digitado um número menor que 0)
    for (int i = 0; i < 50; i++) { //Reseta descartes
      descartes[i] = 0;
    }
    cdescartes = 0;

    scanf("%d", &tamanho); //Lê a quantidade de elementos que o usuário quer
    tam = tamanho;

    if (tam != 0) { //Garante que o programa não quebra se o usuário digitar 0 na primeira iteração
      for (int i = 0; i < tamanho; i++) { //preenche o vetor principal
        vetor[i] = i + 1;
      }

      while (tamanho > 1) { //Enquanto houver 2 ou mais elementos no vetor

        descartes[cdescartes] = vetor[0]; //Joga o primeiro elemento pra fila de descartados
        cdescartes++;
        atualizaVetor(vetor, tamanho); //Chama a função atualizaVetor
        tamanho--;
      }

      printf("Discarded cards: "); //Printa os descartados, depois o valor restante
      for (int i = 0; i < cdescartes; i++) {
        if (i < (cdescartes - 1)) {
          printf("%d, ", descartes[i]);
        } else {
          printf("%d\n", descartes[i]);
        }
      }
      printf("Remaining card: %d\n", vetor[0]);
    }
  }

  return 0; //Finaliza a execução do programa
}