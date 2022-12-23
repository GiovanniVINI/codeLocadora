#include <stdio.h>
#include <stdlib.h>

//valor referência
#define n 80

int main(){
	int i, locacoes[n], locGratis[n];
	//vetor de 80 strings, cada string com 50 caracteres
	char nomeCli[n][50];
	//ler os nomes e locações dos clientes e armazenar nos vetores
	for(i = 0; i < n; i++){
		printf("\nNome cliente: ");
		fflush(stdin);
		gets(nomeCli[i]);
		printf("\nLocacoes: ");
		scanf("%d", &locacoes[i]);
	}
	//calcular locacações grátis de cada cliente
	for(i = 0; i < n; i++){
		locGratis[i] =  locacoes[i] / 10;
	}
	system("cls");
	//mostrar resultados
	for(i = 0; i < n; i++){
		printf("\n %20s \t %5d \t %5d ", nomeCli[i], locacoes[i], locGratis[i]);
	}
	return 0;
}