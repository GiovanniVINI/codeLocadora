/*
Exercício: Faça um algoritmo que receba o nome e anota de 80 alunos de uma sala e armazene em um vetor. 
Calcule e mostre a média da sala, o nome do aluno com a maior e menor nota e os nomes dos alunos aprovados e reprovados.
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define m 80 //Número de alunos

int main(){
	int i, posMaiorNota = 0, posMenorNota = 0;
	float notas[m], media = 0;
	char nomes[m][30];
	
	printf("-----DADOS DO ALUNO-----");
	//Armazenar o nome e a nota dos alunos
	for(i = 0; i < m; i++){
		printf("\n\nDigite o nome do aluno: ");
		fflush(stdin);
		gets(nomes[i]);
		printf("\nNota do aluno: ");
		fflush(stdin);
		scanf("%f", &notas[i]);
	}
	//Descobrir a maior e menor nota e somá-las
	for(i = 0; i < m; i++){
		//Maior nota
		if(notas[i] > notas[posMaiorNota]){
			posMaiorNota = i;
		}
		//Menor nota
		if(notas[i] < notas[posMenorNota]){
			posMenorNota = i;
		}
		//Somar as notas
		media = media + notas[i];
	}
	media = media / m;
	//Mostrar os resultados
	for(i = 0; i < m; i++){
		printf("\n %30s \t %.2f \n ", nomes[i], notas[i]);
	}
	printf("\n Media da sala: %.2f ", media);
	printf("\n Aluno maior nota: %2s ", nomes[posMaiorNota]);
	printf("\n Maior nota: %.2f ", notas[posMaiorNota]);
	printf("\n Aluno menor nota: %2s ", nomes[posMenorNota]);
	printf("\n Menor nota: %.2f ", notas[posMenorNota]);
	//Mostrar os alunos aprovados e reprovados
	printf("\n\n-----RESULTADO FINAL------");
	for(i = 0; i < m; i++){
		if(notas[i] >= 7.0){
			printf("\n %20s - APROVADO ", nomes[i]);
		}
		else 
			printf("\n %20s - REPROVADO ", nomes[i]);
	}
	return 0;
}
