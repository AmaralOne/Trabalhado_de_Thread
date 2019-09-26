#include "pch.h"
#include<iostream>
#include <thread>
#include <mutex>
#include <stack> 

using namespace std;

mutex mu;

void Thread_div(unsigned long long* num, unsigned long long* divisor, stack<unsigned long long>* pilha);

int main()
{
	unsigned long long num;
	unsigned long long divisor = 0;
	unsigned long long soma = 0;
	stack<unsigned long long> pilha;
	int numThread = 0;
	cout << "Digite um numero inteiro" << endl;
	cin >> num;
	cout << "Digite o numero de threads" << endl;
	cin >> numThread;
	if ((num % 2) == 0) {

		thread* myThreads = new thread[numThread];

		for (int i = 0; i < numThread; i++) {
			myThreads[i] = thread(Thread_div, &num, &divisor, &pilha);
		}

		for (int i = 0; i < numThread; i++) {
			myThreads[i].join();
		}

	}
	while (!pilha.empty())
	{
		cout << '\t' << pilha.top() << endl;
		soma += pilha.top();
		pilha.pop();
	}
	if (soma == num) {
		cout << num << " Eh um numero perfeito" << endl;
	}
	else {
		cout << num << " Nao eh um numero perfeito" << endl;
	}

}

void Thread_div(unsigned long long* num, unsigned long long* divisor, stack<unsigned long long>* pilha)
{
	unsigned long long divisorThread = 0;
	while (divisorThread <= (*num) / 2) {
		mu.lock();
		*divisor = *divisor + 1;
		divisorThread = *divisor;
		mu.unlock();
		if ((((*num) % divisorThread) == 0) && divisorThread < *num) {
			mu.lock();
			pilha->push(divisorThread);
			mu.unlock();
		}
	}
	return;
}
