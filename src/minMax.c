/* 
	Aluno: Vitor Palma Aderaldo

	Código para estudar recursão e analisar:
	Base de Indução,
	Hipótese Fraca,
	Passo de Indução,
	Forma da Recorrencia.

	Objetivo: Achar o maior e menor valor
			  de um vetor.
*/

#include <stdio.h>

int maior;
int menor;

int maior_linha;
int menor_linha;

// Retorna o maior valor
int max(int a, int b){
	if( a >= b) return a;
	else return b;
}

// Retorna o menor valor
int min(int a, int b){
	if(a <= b) return a;
	else return b;
}

// Acha o maior e menor valor de um vetor.
// T(n) = T(n-2) + 0 + 4
void minMax(int *vetor, int f){

	// Caso Base T(2)
	// Custo: 1 Comparação
	if(f == 1){
		if(vetor[0] >= vetor[1]){
			maior = vetor[0];
			menor = vetor[1];
		}else{
			maior = vetor[1];
			menor = vetor[0];
		}
	}

	// Caso Base T(1)
	// Custo: 0 Comparações
	else if(f == 0){
		maior = vetor[0];
		menor = vetor[0];
	}

	else{

		// Hipótese de Indução		
		minMax(vetor,f-2);

		/* Paso de Indução:
			Assumimos que ja temos o maior e menor
			do subconjunto, agora só comparar esses
			valores com os dois elementos que não
			estavam no conjunto.
		*/

		maior_linha = max(vetor[f],vetor[f-1]);
		menor_linha = min(vetor[f],vetor[f-1]);		

		maior = max(maior_linha,maior);
		menor = min(menor_linha,menor);

	/*  Custo: 4 Comparacoes.
	    Pode ser otimizado para 3 Comparações.
	*/

	}
}

int main(){

	int vetor[5] = {6,5,3,8,2};

	minMax(&vetor[0],4);

	printf("Min: %d - Max: %d",menor,maior);

	return 1;
}
