// NumeroPrimo.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include "pch.h"
#include <iostream>
#include <stdio.h>  
#include <stdlib.h>  
#include <time.h> 
#include <thread>   
#include<vector>
#include "NumeroPrimo.h"
#include <time.h>

using namespace std;

int * vetorThread;
int tamanhoVetorThread = 0;
int * resultadoThread;
int erro = 0;
double tempo_gasto;
double tempo_gastoThread;

const int qtdTheads = 10;

int geraNumeroAleatorio(int internvalo) {

	int i;


	i = rand() % internvalo;

	return i;
}

int * geraVetorDeNumerosAletatorios(int tamanho, int intervaloDosNumero) {
	int * vetor = new int[tamanho];
	
	srand(time(NULL));

	for (int i = 0; i < tamanho; i++) {
		vetor[i] = geraNumeroAleatorio(intervaloDosNumero);
	}

	return vetor;
}

void imprimeVetor(int * vetor, int tamanhoVetor) {
	for (int x = 0; x < tamanhoVetor; x++) {
		cout << vetor[x] << endl;
	}
	cout << endl;
}

bool numeroPrimo(int num) {
	int resultado = 0;

	if (num == 1)
		return true;

	for (int i = 2; i <= num / 2; i++) {
		if (num % i == 0) {
			resultado++;
			break;
		}
	}

	if (resultado == 0)
		return true;
	
	return false;
}

int * comparadorNumeroPrimo(int * vetor,int tamanho) {

	clock_t tInicio, tFim, tDecorrido;

	tInicio = clock();

	int * resultado = new int[tamanho];

	for (int i = 0; i <= tamanho; i++) {
		if (numeroPrimo(vetor[i])) {
			resultado[i] = 1;
		}
		else {
			resultado[i] = 0;
		}
	}

	tFim = clock();

	tempo_gasto = ((double)(tFim - tInicio)) / CLOCKS_PER_SEC;

	return resultado;


}

void imprimeVetorComparacaoPrimos(int * vetor, int * resutados, int tamanhoVetor) {
	if (erro == 0) {
		for (int x = 0; x < tamanhoVetor; x++) {
			cout << vetor[x] << " Primo: " << resutados[x] << endl;
		}
	}
	
	cout << endl;
}

void teste1() {
	while (1) {
		cout << "1" << endl;
	}
	
}

void teste2() {
	while (1) {
		cout << "2" << endl;
	}
}

void exec(int n) {
	std::cout << "thread " << n << std::endl;
}

void execThread(int posicaoInicial, int posicaoFinal) {
	for (int i = posicaoInicial; i <= posicaoFinal; i++) {
		if (numeroPrimo(vetorThread[i])) {
			resultadoThread[i] = 1;
		}
		else {
			resultadoThread[i] = 0;
		}
	}
}

int * comparVetorComThread(int * vetor, int tamanhoVetor) {
	vetorThread = vetor;
	resultadoThread = new int[tamanhoVetor];
	tamanhoVetorThread = tamanhoVetor;

	if (qtdTheads == 0 || qtdTheads > tamanhoVetorThread || tamanhoVetorThread == 0) {
		cout << "Nao e possivel rodar essa quantidade de Theads visto que e numero invalido" << endl;
		erro = 1;
	}
	else {
		clock_t tInicio, tFim, tDecorrido;

		tInicio = clock();

		thread myThreads[qtdTheads];

		int intervalo = tamanhoVetorThread / qtdTheads;

		int inicio = 0;
		int fim = intervalo;
		for (int i = 0; i < qtdTheads; i++) {
			myThreads[i] = std::thread(execThread, inicio, fim);
			inicio = inicio + intervalo;
			fim = fim + intervalo;
			if (intervalo + fim > tamanhoVetorThread) {
				fim = tamanhoVetorThread;
			}
		}
		for (int i = 0; i < qtdTheads; i++) {
			myThreads[i].join();
		}

		tFim = clock();

		tempo_gastoThread = ((double)(tFim - tInicio)) / CLOCKS_PER_SEC;
	}

	
	return resultadoThread;

}


int main()
{
	int tamahoVetor = 10;

	

	int * vetor = geraVetorDeNumerosAletatorios(tamahoVetor, 90000);

	imprimeVetor(vetor, tamahoVetor);

	

	int * resultados = comparadorNumeroPrimo(vetor, tamahoVetor);


	imprimeVetorComparacaoPrimos(vetor, resultados, tamahoVetor);

	
	int * resultados2 = comparVetorComThread(vetor, tamahoVetor);

	imprimeVetorComparacaoPrimos(vetor, resultados2, tamahoVetor);


	printf("Tempo gasto: %lf s\n", tempo_gasto);
	printf("Tempo gasto com Thread: %lf s\n", tempo_gastoThread);
	
	
	delete[] vetor;
	
	

	return(0);



}

// Executar programa: Ctrl + F5 ou Menu Depurar > Iniciar Sem Depuração
// Depurar programa: F5 ou menu Depurar > Iniciar Depuração

// Dicas para Começar: 
//   1. Use a janela do Gerenciador de Soluções para adicionar/gerenciar arquivos
//   2. Use a janela do Team Explorer para conectar-se ao controle do código-fonte
//   3. Use a janela de Saída para ver mensagens de saída do build e outras mensagens
//   4. Use a janela Lista de Erros para exibir erros
//   5. Ir Para o Projeto > Adicionar Novo Item para criar novos arquivos de código, ou Projeto > Adicionar Item Existente para adicionar arquivos de código existentes ao projeto
//   6. No futuro, para abrir este projeto novamente, vá para Arquivo > Abrir > Projeto e selecione o arquivo. sln
