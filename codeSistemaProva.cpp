/*Uma turma de 50 alunos fez uma prova da disciplina de Algoritmo II. Esta prova 
foi de teste e teve 20 questões. Foram cadastrados os seguintes dados: nome do 
aluno, respostas da prova (sabendo que as respostas poderiam ser a, b, c, d ou e)
o gabarito da prova. O sistema leu os dados e calculou os acertos de cada 
aluno, identificou os nomes dos alunos que tiraram a maior e a menor nota, 
também calculou a média da turma. Faça um programa em Linguagem C que resolva 
esse problema. Você deve usar vetor e matriz para armazenar os dados.*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define m 50 // número de alunos
#define n 20 // número de questões da prova

int main(){
	int l, c, acertos[m], contAcertos, somaAcertos = 0, media;
	int posMaiorNota = 0, posMenorNota = 0, maiorNota, menorNota;
	char nomes[m][40], gabarito[n], respostas[m][n];
	
	//Ler o gabarito da prova
	printf("-----GABARITO-----");
	for(c = 0; c < n; c++){
		printf("\nDigite o gabarito da prova, alternativas de [A] a [E]: ", c+1);
		fflush(stdin);
		gabarito[c] = getche();
	}
	//Ler os nomes dos alunos e suas respostas
	printf("\n\n-----DADOS DO ALUNO-----");
	for(l = 0; l < m; l++){
		printf("\n\nDigite o nome do aluno: ");
		fflush(stdin);
		gets(nomes[l]);
		for(c = 0; c < n; c++){
			printf("\nDigite a resposta do aluno, da questao %d: ", c+1);
			fflush(stdin);
			respostas[l][c] = getche();
		}
	}
	//Calcular os acertos
	for(l = 0; l < m; l++){
		contAcertos = 0;
		for(c = 0; c < n; c++){
			if(gabarito[c] == respostas[l][c]){
				contAcertos++;
			}
		}
		acertos[l] = contAcertos;
	}
	//Achar os alunos que tiraram a maior e a menor nota.
	maiorNota = acertos[0];
	menorNota = acertos[0];
	for(l = 0; l < m; l++){
		//Maior nota
		if(acertos[l] > maiorNota){
			maiorNota = acertos[l];
			posMaiorNota = l;
		}
		if(acertos[l] < menorNota){
			menorNota = acertos[l];
			posMenorNota = l;
		}
		//Somar os acertos
		somaAcertos = somaAcertos + acertos[l];
	}
	//Calcular a média
	media = somaAcertos / m;
	system("cls");
	printf("\n Nome \t\t respostas \t acertos \n");
	for(l = 0; l < m; l++){
		printf("\n %-15s", nomes[l]);
		for(c = 0; c < n; c++)
		{
			printf(" %c ", respostas[l][c]);
		}
		printf(" %5d ", acertos[l]);
	}
	//Mostrar os resultados
	printf("\n\n Aluno com maior nota: %s ", nomes[posMaiorNota]);
	printf("\n Maior nota: %d ", acertos[posMaiorNota]);
	printf("\n Aluno com a menor nota: %s", nomes[posMenorNota]);
	printf("\n Menor nota: %d ", acertos[posMenorNota]);
	printf("\n Media de acertos da prova: %d \n\n", media);
	return 0;
}
