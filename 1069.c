#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(){
	int N, topo = 0, tam, diamantes;
	char pilha[1000], mina[1000];

	scanf("%d", &N);
	getchar();

	for (int i = 0; i < N; i++){
		//printf("l");
		diamantes = 0;
		topo = 0;
		if (fgets(mina, sizeof(mina), stdin) != NULL){
			tam = strlen(mina);
			for (int j = 0; j < tam; j++){
				if (mina[j] == '<'){
					pilha[topo] = '<';
					topo ++;
				}
				else if (mina[j] == '>' && topo > 0){
					topo --;
					diamantes++;
				}
			}
		}	

		printf("%i\n", diamantes);
	}
}