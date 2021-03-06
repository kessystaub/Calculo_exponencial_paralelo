#include <stdlib.h>
#include <stdio.h>
#include <omp.h>
#include <iostream>


using namespace std;

int calcula(int base, int expoente) {
	if (expoente == 0) {
		return 1;
	}
	else {
		return base * calcula(base, expoente - 1);
	}
}



int main() {
	int base = 2, expoente = 30, resposta = 0;

	//double tempo_execucao = 0.0000;
	//double inicio = omp_get_wtime();

	#pragma omp parallel num_threads(1)
	{
		int id = omp_get_thread_num();

		if (id==0) {
			resposta = calcula(base, expoente);
		}
		else {

		}

		
	}

	//double final = omp_get_wtime();
	//tempo_execucao = (final - inicio);
	//cout << "tempo execucao: " << tempo_execucao << endl;

	printf("resposta: %i\n", resposta);
}
