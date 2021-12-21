#include "gauss.h"
#include "backsubst.h"
#include "mat_io.h"
#include <stdlib.h>
#include <stdio.h>


int main(int argc, char ** argv) {
	int res;
	Matrix * A = readFromFile(argv[1]);
	Matrix * b = readFromFile(argv[2]);
	

	if ( A->r != A->c) {
		printf("error: nieprawidlowy rozmiar macierzy A\n");
		return 2;
	}
	if ( A->r != b->r) {
		printf("error: liczba wierszy macierzy nie jest rowna liczbie wierszy macierzy wyrazow wolnych\n");
		return 3;
	}
	if ( b->c != 1) {
		printf("error: liczba kolumn w macierzy wyrazow wolnych jest inna niz 1\n");
		return 4;
	}

	Matrix * x;

	if (A == NULL) return -1;
	if (b == NULL) return -2;
	printf("Macierz rownan A:\n");
	printToScreen(A);
	printf("Macierz wyrazow wolnych:\n");
	printToScreen(b);
	res = eliminate(A,b);
	if ( res)
		exit(EXIT_FAILURE);
	x = createMatrix(b->r, 1);
	if (x != NULL) {
		res = backsubst(x,A,b);
		if( res)
			exit(EXIT_FAILURE);
		printf("macierz po eliminacji Gaussa\n");
		printToScreen(A);
		printf("Macierz rozwiazan\n");
		printToScreen(x);
	  	freeMatrix(x);
	} else {
		fprintf(stderr,"Błąd! Nie mogłem utworzyć wektora wynikowego x.\n");
	}

	freeMatrix(A);
	freeMatrix(b);

	return 0;
}
