#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/* 
	Aluno: Vitor Palma Aderaldo		
	Objetivo: Ordenar um vetor utilizando Counting Sort	
*/

int min;
int max;

//Achar o menor e maior valor do vetor
void minMax(int *v,int n){

	// Custo: 2*(n-1)

	min = v[0];
	max = v[0];

	for(int i=1;i<n;i++){
		if(min > v[i]){
			min = v[i];
		}
		if(max < v[i]){
			max = v[i];
		}
	}
	//printf("\n\nMin: %d  Max: %d",min,max);	
}

//Verifica se pode aplicar o Couting Sort
bool podeAplicar(int n){

	// Custo: 1

	// printf("\nPodemos ter %d valores distintos para um vetor de %d posicoes",(max-min+1),n);

	if ((max-min)+1 <= n){
		//printf("\nPodemos aplicar o Algoritmo");
		return true;
	}else{
		printf("\nNao podemos aplicar o Algoritmo\n");
		return false;
	}
}

int main(){

	int tamanho = 9;

	int num;
	int qnt;
	int p;

	int vetor[9] = {6,1,2,2,3,8,7,7,5};

	//printf("\nVetor Original:\n");
	for(int k=0;k<tamanho;k++) printf("%d ",vetor[k]);

	minMax(&vetor[0],tamanho);												

	if(podeAplicar(tamanho)==true){											

		printf("\nAplicando o Counting-Sort\n");

		//Alocar vetor auxiliar de tamanho (Max-Min+1)
		int tamHisto = (max-min)+1;
		int *histograma = (int *) malloc(tamHisto*(sizeof(int)));
		for(int i=0;i<tamHisto;i++) histograma[i] = 0;
		//printf("\nVetor auxiliar criado");

		//Criar Histograma
		for(int j=0;j<tamanho;j++){

			//Pega os numeros do vetor original
			num = vetor[j];

			//Faz a contagem da quantidade de vezes que esse numero aparece no vetor
			histograma[num-min] = histograma[num-min] + 1;

		}

		//Ordenando o vetor original
		p = 0;
		for(int j=0;j<tamHisto;j++){

			//Acha o valor e qnts vezes aparece
			num = j+min;
			qnt = histograma[j];

			//Insere esse valor n vezes no vetor original
			for(int k=0;k<qnt;k++){
				vetor[p] = num;
				p++;
			}			
		}

		//Mostrando o vetor ordenados
		//printf("\nVetor Ordenado:\n");
		for(int k=0;k<tamanho;k++) printf("%d ",vetor[k]);
		printf("\n");
	}
	return 1;
}
